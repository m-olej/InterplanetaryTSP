#ifndef GRAVITYTRAVELLINGSALESMAN_ALGOS_H
#define GRAVITYTRAVELLINGSALESMAN_ALGOS_H

#include "GravitySource.h"
#include "Traveller.h"
#include "myMath.h"
#include "SFML/Graphics.hpp"
#include <map>
#include <unordered_set>
#include <list>
#include <algorithm>


class Algos {
public:
    std::map<int, GravitySource> static orderAlgorithmGreed(std::vector<GravitySource> planets, Traveller ship);

    std::map<int, GravitySource> static orderAlgorithmBrute(std::map<int, GravitySource> planets, Traveller ship);

    void static orderAlgorithmFull(std::vector<GravitySource> planets, Traveller trav);

};



#endif //GRAVITYTRAVELLINGSALESMAN_ALGOS_H
