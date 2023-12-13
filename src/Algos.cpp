#include <iostream>
#include "../include/Algos.h"

std::map<int, GravitySource> Algos::orderAlgorithm(std::vector<GravitySource> planets, Traveller trav) {

    // map of planets will assign each planet an id to order by.
    std::map<int, GravitySource> order;
    std::map<int, GravitySource> temp;

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
    // Search for best order
    float r;
    double angle;
    double minAngleDiff = 1000000000000;
    sf::Vector2f relativePos;
    //scenario I - ship to planet
    int planetId = 1;
    int best;
    float best_r = 10000000000;
    for( auto itr = temp.begin(); itr != temp.end(); ++itr ){
        relativePos = itr->second.getPos() - trav.get_pos();
        r = myMath::magnitude(relativePos);
        angle = myMath::angleOfVector(relativePos);
        if(minAngleDiff >  std::abs(angle - gravityDir) && r < best_r){
            minAngleDiff = std::abs(angle - gravityDir);
            best = itr->first;
            best_r = r;
        }
        ++planetId;
    }
    order.insert(std::pair<int, GravitySource>(best, temp.at(best)));
    temp.erase(best);
    std::cout << order.at(best).getMass() << " " << order.rbegin()->first << best << '\n';

    //scenario II - planet to planet
    for(auto itr = temp.begin(); itr != temp.end(); ++itr ){
        relativePos = order.rbegin()->second.getPos() - itr->second.getPos();
        r = myMath::magnitude(relativePos);
        angle = myMath::angleOfVector(relativePos);
        if(minAngleDiff >  std::abs(angle - gravityDir) && r < best_r){
            minAngleDiff = std::abs(angle - gravityDir);
            best = itr->first;
            best_r = r;
        }
        ++planetId;
    }

    //scenario II - planet to beginning (ship)
    return order;
}