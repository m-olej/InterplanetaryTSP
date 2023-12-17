#include <iostream>
#include "../include/Algos.h"
#include "../include/planetNode.h"

std::map<int, GravitySource> Algos::orderAlgorithmGreed(std::vector<GravitySource> planets, Traveller trav) {
    ////setup

    // map of planets will assign each planet an id to order by.
    std::map<int, GravitySource> order;
    std::map<int, GravitySource> temp;
    std::list<int> insertionOrder; // C++ is dumb as fuck
    int i = 1;
    for (GravitySource planet: planets) {
        temp.insert(std::pair<int, GravitySource>(i, planet));
        i++;
    }

    // calculate resultant vector of gravitational force
    sf::Vector2f gravityPull = {0, 0};
    for (GravitySource planet: planets) {
        float r = myMath::distanceBetween(trav.get_pos(), planet.getPos());
        sf::Vector2f relativePos = planet.getPos() - trav.get_pos();
        gravityPull += (planet.getMass() * trav.get_mass() * relativePos) / (r * r * r);
    }
    // direction of gravity pull vector
    double gravityDir = myMath::angleOfVector(gravityPull);

    ////
    //// Search for best order
    ////



    float r;
    double angle;
    double minAngleDiff = 1000000000000;
    sf::Vector2f relativePos;

    double fitnesSum = 0;

    ////scenario I - ship to planet

    int best;
    float best_r = 10000000000;
    for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
        relativePos = itr->second.getPos() - trav.get_pos();
        r = myMath::magnitude(relativePos);
        angle = myMath::angleOfVector(relativePos);
        if (minAngleDiff > std::abs(angle - gravityDir) && r < best_r) {
            minAngleDiff = std::abs(angle - gravityDir);
            best = itr->first;
            best_r = r;
        }
    }
    order.insert(std::pair<int, GravitySource>(best, temp.at(best)));
    insertionOrder.push_back(best);
    temp.erase(best);
    fitnesSum += minAngleDiff;
    sf::Vector2f previousPos = trav.get_pos();
    sf::Vector2f currentPos;
    double last_angle;
    ////scenario II - planet to planet

    while (temp.size() != 0) {
        minAngleDiff = 1000000000000;
        best_r = 100000000000;
        currentPos = order.rbegin()->second.getPos();
        for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
            relativePos = itr->second.getPos() - currentPos;
            r = myMath::magnitude(relativePos);
            angle = 360 - myMath::angleOfVector(previousPos - currentPos);
            if (minAngleDiff > std::abs(myMath::angleOfVector(relativePos) - angle) && r < best_r) {
                minAngleDiff = std::abs(myMath::angleOfVector(relativePos) - angle);
                best = itr->first;
                best_r = r;
                last_angle = 360 - myMath::angleOfVector(currentPos - itr->second.getPos());
            }
        }
        previousPos = currentPos;
        fitnesSum += minAngleDiff;
        order.insert(std::pair<int, GravitySource>(best, temp.at(best)));
        insertionOrder.push_back(best);
        temp.erase(best);
    }

    //// Adding to the fitnesSum the diffAngle from last planet to starting point
    relativePos = trav.get_pos() - order.at(best).getPos();
    fitnesSum += std::abs(myMath::angleOfVector(relativePos) - last_angle);
    //// Printing the answer

//    std::list<std::string> colorOrderName = {"Blue", "Red", "Yellow", "Green"};
//    std::list<sf::Color> colorOrder = {sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Green};
    int increment = 1;
    std::cout << "Greedy order: ";
    for (int x: insertionOrder) {
        std::cout << x << " ";
//        std::cout << increment << ": " << " id: " << x << " - " << "Color: " << colorOrderName.front() << "\n";
//        order.at(x).setColor(colorOrder.front());
//        colorOrder.pop_front();
//        colorOrderName.pop_front();
        increment++;
    }
    std::cout << "-> fitnesSum: " << fitnesSum << '\n';
    return order;
}

struct graphNode {
    int id;
    sf::Vector2f pos;
    float Mass;
    double angleIn;
    double angleOut;
    sf::Vector2f startingPos;
    std::unordered_set<int> visited;
};


void planet2planet(graphNode node,
                  std::map<int, graphNode> nodes,
                  std::pair<std::list<int>, double> solution,
                  std::vector<std::pair<std::list<int>, double>> &allSolutions){
    for(auto el: solution.first){
        std::cout << el << " ";
    }
    std::cout << solution.second << "\n";
    if(solution.first.size() == nodes.size()){
        // add fitness cost of returning to starting point
        solution.second += std::abs(node.angleOut - myMath::angleOfVector(node.startingPos - node.pos));
        // add to allSolutions
        allSolutions.push_back(solution);
        // subtract fitnessCost of going back to starting point before backtracking;
        solution.second -= std::abs(node.angleOut - myMath::angleOfVector(node.startingPos - node.pos));
        return;
    }
    for(std::pair<int, graphNode> nextNode: nodes){
        // returns node.visited.end() if element not in visited
        auto itVis = node.visited.find(nextNode.first);
        // returns solution.first.end() if element not in solution
        auto itSol = std::find(solution.first.begin(), solution.first.end(), nextNode.first);
        if( itVis == node.visited.end() && itSol == solution.first.end()){
            node.visited.insert(nextNode.second.id);
            nextNode.second.angleIn = myMath::angleOfVector(nextNode.second.pos - node.pos);
            nextNode.second.angleOut = 360 - myMath::angleOfVector(node.pos - nextNode.second.pos);
            // add fitness cost of going to that nextNode
            solution.second += std::abs(node.angleOut - nextNode.second.angleIn);
            solution.first.push_back(nextNode.first);
            //recursively go to another planet
            planet2planet(nextNode.second, nodes, solution,  allSolutions);
            // remove last element when backtracking
            solution.first.pop_back();
            // subtract the fitness cost from backtracked travel
            solution.second -= std::abs(node.angleOut - nextNode.second.angleIn);
        }
    }
    return;
}

void Algos::orderAlgorithmFull(std::vector<GravitySource> planets, Traveller trav){

    std::map<int, graphNode> nodes;
    std::list<int> insertionOrder;
    std::pair<std::list<int>, double> solution;
    // vector of fitnesSum, order pairs
    std::vector<std::pair<std::list<int>, double>> allSolutions;

    // Transcribe into graph algorithm

    int i = 1;
    for( GravitySource planet: planets){
        graphNode node;
        node.id = i;
        node.pos = planet.getPos();
        node.Mass = planet.getMass();
        // so node can't go to itself
        node.visited = {i};
        node.startingPos = trav.get_pos();
        nodes.insert(std::pair<int, graphNode>(i, node));
        i++;
    }


    // calculate resultant vector of gravitational force
    sf::Vector2f gravityPull = {0,0};
    for( GravitySource planet: planets ){
        float r = myMath::distanceBetween(trav.get_pos(), planet.getPos());
        sf::Vector2f relativePos = planet.getPos() - trav.get_pos();
        gravityPull += (planet.getMass() * trav.get_mass() * relativePos)/ (r*r*r);
    }
    // direction of gravity pull vector
    double gravityDir = myMath::angleOfVector(gravityPull);

    //// Check solution for every first planet from starting position

    sf::Vector2f relativePos;

    for(std::pair<int, graphNode> startNode: nodes){
        std::cout << "--------" << "\n";
        relativePos = startNode.second.pos - trav.get_pos();
        solution.first.push_back(startNode.first);

        // set angleIn, angleOut for nextNode
        startNode.second.angleIn = myMath::angleOfVector(relativePos);
        startNode.second.angleOut = 360 - myMath::angleOfVector(trav.get_pos() - startNode.second.pos);

        // set fitnesSum for this starting configuration
        // fitness cost from 0 -> 1 (starting point to first planet)
        solution.second = std::abs(myMath::angleOfVector(relativePos) - gravityDir);


        planet2planet(startNode.second, nodes, solution, allSolutions);

        //clear all node properties
        for(std::pair<int, graphNode> node: nodes){
            node.second.visited = {node.first};
        }
        //clear solution before starting from new point
        solution.first.clear();
    }

    //// Print solutions with their fitnesSum and pick the one with min fitnesSum

    int increment = 0;
    // maximum sumOfAngleDiff can't exceed (number of planets + 1) * 359;
    double minFitnesSum = (nodes.size()+1)*361;
    int minIndex = 0;
    std::cout << "\n\n";
    for( auto sol: allSolutions){
        std::cout << "FitnesSum of route: " << sol.second << "->\t";
        if(minFitnesSum > sol.second){
            minFitnesSum = sol.second;
            minIndex = increment;
        }
        for( auto el: sol.first){
            std::cout << el << " ";
        }
        increment++;
        std::cout << "\n";
    }

    std::cout << "\n" << "Optimal order: ";
    for(auto el: allSolutions[minIndex].first){
        std::cout << el << " ";
    }
    std::cout << "with fitnesSum of: " << minFitnesSum << "\n";

    return;
}
