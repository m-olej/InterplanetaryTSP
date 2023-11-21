#ifndef GRAVITYTRAVELLINGSALESMAN_TRAVELLER_H
#define GRAVITYTRAVELLINGSALESMAN_TRAVELLER_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "../include/GravitySource.h"

class Traveller {
    sf::Vector2<float> pos;
    sf::Vector2<float> vel;
    sf::CircleShape traveller;
    sf::CircleShape trace;
    float propulsionAcceleration;
    float mass;
    float radius;

public:
    Traveller(float pos_x, float pos_y, float vel_x, float vel_y, float mass);

    void render(sf::RenderWindow &window);

    void update_physics(std::vector<GravitySource> planets);

    void propulsion();

    sf::Vector2<float> get_pos();

    float get_mass();

    float get_radius();

    float getPropulsionAcceleration() const;

    bool collisionDetection(float distance, float rad1, float rad2);

    void traceTrajectory(Traveller traveller, sf::RenderWindow &window, std::vector<sf::Vector2f> &trajectory);
};


#endif //GRAVITYTRAVELLINGSALESMAN_TRAVELLER_H
