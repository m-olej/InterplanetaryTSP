#include "../include/GravitySource.h"
#include <math.h>

GravitySource::GravitySource(float pos_x, float pos_y, float Mass) {
    Pos.x = pos_x;
    Pos.y = pos_y;
    this->Mass = Mass;
    // density = 1 for simplicity
    Radius = std::cbrt((3*Mass)/(4*3.14));

    planet.setPosition(Pos);
    planet.setOrigin(Radius, Radius);
    planet.setFillColor(sf::Color::White);
    planet.setRadius( Radius );
}

void GravitySource::render(sf::RenderWindow &window){
    window.draw(planet);
}

sf::Vector2<float> GravitySource::getPos() {
    return Pos;
}

float GravitySource::getMass() {
    return Mass;
}

void GravitySource::setMass(int mass) {
    this->Mass = mass;
}

void GravitySource::setColor(sf::Color colour){
    this->planet.setFillColor(colour);
}

float GravitySource::getRadius(){
    return Radius;
}

void GravitySource::test() {
    setMass(0);
    planet.setFillColor(sf::Color::Yellow);
}