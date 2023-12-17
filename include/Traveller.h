#ifndef GRAVITYTRAVELLINGSALESMAN_TRAVELLER_H
#define GRAVITYTRAVELLINGSALESMAN_TRAVELLER_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "../include/GravitySource.h"

class Traveller {
    sf::Vector2<float> pos;
    sf::Vector2<float> last_pos = {1100, 350};
private:
    sf::Vector2<float> vel;
    sf::CircleShape traveller;
    sf::CircleShape trace;
    float propulsionAcceleration = 1;
    sf::RectangleShape propulsionLine;
    float mass;
    float radius;

public:
    Traveller(float pos_x, float pos_y, float vel_x, float vel_y, float mass);

    void render(sf::RenderWindow &window);

    void update_physics(std::vector<GravitySource> planets);

    // keys control
    void propulsion(sf::RenderWindow &window);
    // 360 vector propulsion used for algorithm
    void propulsion(sf::Vector2f position, sf::RenderWindow &window);

    sf::Vector2<float> get_pos();

    sf::Vector2<float> get_vel();

    sf::Vector2<float> &getLastPos();

    void setLastPos(sf::Vector2<float> &lastPos);

    float get_mass();

    float get_radius();

    float getPropulsionAcceleration() const;

    bool collisionDetection(GravitySource planet);

    void traceTrajectory(Traveller traveller, sf::RenderWindow &window, std::vector<sf::Vector2f> &trajectory);
};


#endif //GRAVITYTRAVELLINGSALESMAN_TRAVELLER_H
