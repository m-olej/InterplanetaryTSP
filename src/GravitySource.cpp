#include "../include/GravitySource.h"
#include <math.h>

GravitySource::GravitySource(float pos_x, float pos_y, float Mass) {
    Pos.x = pos_x;
    Pos.y = pos_y;
    this->Mass = Mass;
    Radius = std::cbrt((3*Mass)/(4*3.14));

    planet.setPosition(Pos);
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

float GravitySource::getRadius(){
    return Radius;
}

void GravitySource::test() {
    setMass(0);
    planet.setFillColor(sf::Color::Yellow);
}