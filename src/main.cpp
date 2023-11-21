#include "SFML/Graphics.hpp"
#include "../include/GravitySource.h"
#include "../include/Traveller.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Visualization");
    window.setFramerateLimit(60);

    GravitySource planetA(600, 500, 550);
    GravitySource planetB(600, 200, 350);
    GravitySource planetC(900, 500, 450);
    GravitySource planetD(900, 200, 200);

    std::vector<GravitySource> planets = {planetA, planetB, planetC, planetD};
    Traveller traveller(1000, 350, 0, -1, 50);
    std::vector<sf::Vector2f> trajectory;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        window.clear();
        traveller.update_physics(planets);
        traveller.propulsion();
        planetA.render(window);
        planetB.render(window);
        planetC.render(window);
        planetD.render(window);
        traveller.render(window);
        traveller.traceTrajectory(traveller, window, trajectory);


        //draw calls
        window.display();
    }



    return 0;
}

