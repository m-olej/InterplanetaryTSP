#include "../include/myMath.h"


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

// x-axis to the right, y-axis upwards
double myMath::angleOfVector(sf::Vector2f vec) {
    double angle;
    if(vec.x > 0 && vec.y > 0){
        // Quadrant I
        if(vec.x == 0){
            float fakeX = 0.1;
            angle = std::atan(vec.y/fakeX) * 180/PI;
        }else{
            angle = std::atan(vec.y/vec.x) * 180/PI;
        }
    }else if(vec.x < 0 && vec.y > 0){
        // Quadrant II
        if(vec.x == 0){
            float fakeX = 0.00000001;
            angle = std::atan(vec.y/fakeX) * 180/PI;

        }else{
            angle = std::atan(vec.y/vec.x) * 180/PI;
        }
        angle += 180;
    }else if(vec.x < 0 && vec.y < 0){
        // Quadrant III
        if(vec.x == 0){
            float fakeX = 0.00000001;
            angle = std::atan(vec.y/fakeX) * 180/PI;
        }else{
            angle = std::atan(vec.y/vec.x) * 180/PI;
        }
        angle += 180;
    }else if(vec.x > 0 && vec.y < 0){
        // Quadrant IV
        if(vec.x == 0){
            float fakeX = 0.00000001;
            angle = std::atan(vec.y/fakeX) * 180/PI;
        }else{
            angle = std::atan(vec.y/vec.x) * 180/PI;
        }
        angle += 360;
    }
    // for clarity, because y is increasing downward for some reason in SFML
    // Angle with x positive to the right and y positive upwards
    return 360 - angle;
}

double myMath::angleBetweenVectors(sf::Vector2f vec1, sf::Vector2f vec2) {
    double angle = std::acos((myMath::dotProduct(vec1, vec2))/(myMath::magnitude(vec1)*myMath::magnitude(vec2)));
    return angle * 180/PI;
}

