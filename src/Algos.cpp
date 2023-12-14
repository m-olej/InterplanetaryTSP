#include <iostream>
#include "../include/Algos.h"

std::map<int, GravitySource> Algos::orderAlgorithm(std::vector<GravitySource> planets, Traveller trav) {

    // map of planets will assign each planet an id to order by.
    std::map<int, GravitySource> order;
    std::map<int, GravitySource> temp;
    std::list<int> insertionOrder; // C++ is dumb as fuck
    int i = 1;
    for( GravitySource planet: planets){
        temp.insert(std::pair<int, GravitySource>(i, planet));
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
    std::cout << "Force: " << myMath::magnitude(gravityPull) << ", Angle: " << gravityDir << "\n";

    // Search for best order
    float r;
    double angle;
    double minAngleDiff = 1000000000000;
    sf::Vector2f relativePos;
    //scenario I - ship to planet
    int best;
    float best_r = 10000000000;
    for( auto itr = temp.begin(); itr != temp.end(); ++itr ){
        relativePos = itr->second.getPos() - trav.get_pos();
        r = myMath::magnitude(relativePos);
        angle = myMath::angleOfVector(relativePos);
        if(minAngleDiff >  std::abs(angle - gravityDir)*r*r ){
            minAngleDiff = std::abs(angle - gravityDir)*r*r;
            best = itr->first;
            best_r = r;
        }
    }
    order.insert(std::pair<int, GravitySource>(best, temp.at(best)));
    insertionOrder.push_back(best);
    temp.erase(best);
//    std::cout << order.at(best).getMass() << " " << order.rbegin()->first << best << '\n';

    sf::Vector2f previousPos = trav.get_pos();
    sf::Vector2f currentPos;
    //scenario II - planet to planet
    while(temp.size() != 0){
        minAngleDiff = 1000000000000;
        best_r = 100000000000;
        currentPos = order.rbegin()->second.getPos();
        for(auto itr = temp.begin(); itr != temp.end(); ++itr ){
            relativePos = itr->second.getPos() - currentPos;
            r = myMath::magnitude(relativePos);
            angle = 360 - myMath::angleOfVector(previousPos - currentPos);
            if(minAngleDiff > std::abs(myMath::angleOfVector(relativePos) - angle) && r < best_r){
                minAngleDiff = std::abs(myMath::angleOfVector(relativePos) - angle);
                best = itr->first;
                best_r = r;
            }
        }
        std::cout << best << '\n';
        previousPos = currentPos;
        order.insert(std::pair<int, GravitySource>(best, temp.at(best)));
        insertionOrder.push_back(best);
        temp.erase(best);
    }
    int increment = 1;
    for( int x: insertionOrder ){
        std::cout << increment << ": " << " id:" << x << " - " << "mass: " << order.at(x).getMass() << "\n";
        increment++;
    }

    //scenario II - planet to beginning (ship)
    return order;
}