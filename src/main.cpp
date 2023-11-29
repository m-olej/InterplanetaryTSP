#include "SFML/Graphics.hpp"
#include "../include/GravitySource.h"
#include "../include/Traveller.h"
#include <vector>
#include <iostream>

// Render only after finding optimal solution with greedy algorithm
// Render only when reached another milestone in metaheursitic algo

int visualize()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Visualization");
    window.setFramerateLimit(60);

//    //bottom-left
//    GravitySource planetA(600, 500, 550);
//    //top-left
//    GravitySource planetB(600, 200, 350);
//    //bottom-right
//    GravitySource planetC(900, 500, 450);
//    //top-right
//    GravitySource planetD(900, 200, 200);
//    std::vector<GravitySource> planets = {planetA, planetB, planetC, planetD};
    GravitySource planetTest(1500,800, 0);
    std::vector<GravitySource> planets = { planetTest };

    Traveller traveller(1100, 350, 0, 0, 50);
    std::vector<sf::Vector2f> trajectory;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // left click...
                sf::Vector2f position = sf::Vector2f (sf::Mouse::getPosition(window));
                std::cout << position.x << ", " << position.y << "\n";
                traveller.propulsion(position);
            }
        }

        window.clear();
        traveller.update_physics(planets);
        traveller.propulsion();
//        traveller.propulsion(planetTest.getPos());
//        planetA.render(window);
//        planetB.render(window);
//        planetC.render(window);
//        planetD.render(window);
//        planetTest.render(window);
        traveller.render(window);
        traveller.traceTrajectory(traveller, window, trajectory);


        //draw calls
        window.display();
    }
    return 0;
}

int main()
{
    visualize();
    return 0;
}
