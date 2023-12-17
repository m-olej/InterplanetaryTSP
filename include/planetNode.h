#ifndef GRAVITYTRAVELLINGSALESMAN_PLANETNODE_H
#define GRAVITYTRAVELLINGSALESMAN_PLANETNODE_H

#include "GravitySource.h"
#include <unordered_set>
class planetNode: public GravitySource {
public:
    std::unordered_set<int> visited = {}; //each planet will hold all visited planets from it

};


#endif //GRAVITYTRAVELLINGSALESMAN_PLANETNODE_H
