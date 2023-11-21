#include "../include/Traveller.h"
#include <math.h>


Traveller::Traveller(float pos_x, float pos_y, float vel_x, float vel_y, float mass) {
    pos.x = pos_x;
    pos.y = pos_y;
    vel.x = vel_x;
    vel.y = vel_y;
    this->mass = mass;
    radius = 5.f;

    traveller.setPosition(pos);
    traveller.setFillColor(sf::Color::White);
    traveller.setRadius(radius);
}

void Traveller::render(sf::RenderWindow &window) {
    traveller.setPosition(pos);
    window.draw(traveller);
}

// make it take a list of all Gravity Sources
void Traveller::update_physics(std::vector<GravitySource> planets){
    for( GravitySource planet: planets) {
        float distance_x = (planet.getPos().x - pos.x) ;
        float distance_y = (planet.getPos().y - pos.y) ;

        float r = sqrt(distance_x * distance_x + distance_y * distance_y) ;

        if(collisionDetection(r, get_radius(), planet.getRadius())){
            traveller.setFillColor(sf::Color::Red);
            vel.x = 0;
            vel.y =0;
        }else {
            // because multiplication is faster than division
            float inverse_distance = 1.f / r;
            float inverse_distance_squared = inverse_distance * inverse_distance;
            // vectors of length 1
            float normalized_x = inverse_distance * distance_x;
            float normalized_y = inverse_distance * distance_y;
            // Using Newtonian interpretation of gravity

            float acceleration_x = normalized_x * planet.getMass() * inverse_distance_squared;
            float acceleration_y = normalized_y * planet.getMass() * inverse_distance_squared;

            vel.x += acceleration_x;
            vel.y += acceleration_y;

            pos.x += vel.x;
            pos.y += vel.y;
        }
    }
}

bool Traveller::collisionDetection(float distance, float rad1, float rad2 ) {
    if (distance <= (rad1 + rad2)){
        return true;
    }else{
        return false;
    }
}

void Traveller::propulsion(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        vel.y -= getPropulsionAcceleration();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        vel.y += getPropulsionAcceleration();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel.x -= getPropulsionAcceleration();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        vel.x += getPropulsionAcceleration();
    }
}

void Traveller::traceTrajectory(Traveller traveller, sf::RenderWindow &window ,std::vector<sf::Vector2f> &trajectory){
    trajectory.push_back(traveller.get_pos());
    for (sf::Vector2f postPas: trajectory){
        trace.setPosition(postPas);
        trace.setFillColor(sf::Color::Yellow);
        trace.setRadius(1);
        window.draw(trace);
    }
}

sf::Vector2<float> Traveller::get_pos(){
    return pos;
}

float Traveller::get_mass() {
    return mass;
}

float Traveller::get_radius(){
    return radius;
}

float Traveller::getPropulsionAcceleration() const {
    return  1 / mass;
}

