#ifndef GRAVITYTRAVELLINGSALESMAN_ALGOS_H
#define GRAVITYTRAVELLINGSALESMAN_ALGOS_H

#include "GravitySource.h"
#include "Traveller.h"
#include "myMath.h"
#include "SFML/Graphics.hpp"
#include <map>
#include <list>


class Algos {
public:
    std::map<int, GravitySource> static orderAlgorithm(std::vector<GravitySource> planets, Traveller ship);
};


#endif //GRAVITYTRAVELLINGSALESMAN_ALGOS_H
