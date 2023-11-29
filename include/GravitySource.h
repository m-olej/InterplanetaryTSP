#ifndef GRAVITYTRAVELLINGSALESMAN_GRAVITYSOURCE_H
#define GRAVITYTRAVELLINGSALESMAN_GRAVITYSOURCE_H

#include "SFML/Graphics.hpp"

class GravitySource {

    sf::Vector2<float> Pos;
    float Mass;
    float Radius;
    sf::CircleShape planet;

public:
    GravitySource(float pos_x, float pos_y, float Mass);

    void render(sf::RenderWindow &window);

    sf::Vector2<float> getPos();

    float getMass();

    // for stopping simulation
    void setMass( int mass);

    float getRadius();

    void test();
};


#endif //GRAVITYTRAVELLINGSALESMAN_GRAVITYSOURCE_H
