#ifndef GRAVITYTRAVELLINGSALESMAN_MYMATH_H
#define GRAVITYTRAVELLINGSALESMAN_MYMATH_H
#include <math.h>
#include "SFML/Graphics.hpp"
#define PI 3.141592654
class myMath {

public:
    static sf::Vector2f normalizeVector(sf::Vector2f vector);

    static float dotProduct(sf::Vector2f vec1, sf::Vector2f vec2);

    static float distanceBetween(sf::Vector2f vec1, sf::Vector2f vec2);

    static float magnitude(sf::Vector2f vec);

    static double angleOfVector(sf::Vector2f vec);

    static double angleBetweenVectors(sf::Vector2f vec1, sf::Vector2f vec2);
};


#endif //GRAVITYTRAVELLINGSALESMAN_MYMATH_H
