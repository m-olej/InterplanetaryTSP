#include "../include/myMath.h"
#include <math.h>

sf::Vector2f myMath::normalizeVector(sf::Vector2f vector) {
    // A normalized vector helps to change only the direction of other vectors
    // when calculating the dot product
    // Normalizing a vector is to make its magnitude one, but keeping the angle.
    sf::Vector2f normalizedVector;
    float x = vector.x;
    float y = vector.y;
    // the magnitude
    float r = sqrt(x*x + y*y);
    float inverse_r = 1/r;
    normalizedVector.x = x * inverse_r;
    normalizedVector.y = y * inverse_r;

    return normalizedVector;
}

float myMath::dotProduct(sf::Vector2f vec1, sf::Vector2f vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

float myMath::distanceBetween(sf::Vector2f vec1, sf::Vector2f vec2) {
    float distance_x = vec1.x - vec2.x;
    float distance_y = vec1.y - vec2.y;
    return sqrt(distance_x * distance_x + distance_y * distance_y);
}

float myMath::magnitude(sf::Vector2f vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

