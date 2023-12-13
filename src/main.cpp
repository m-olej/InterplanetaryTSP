#include "SFML/Graphics.hpp"
#include "../include/GravitySource.h"
#include "../include/Traveller.h"
#include "../include/Algos.h"
#include <vector>
#include<cstdlib>
#include <iostream>

// Render only after finding optimal solution with greedy algorithm
// Render only when reached another milestone in metaheuristic algo

int visualize(std::vector<GravitySource> planets, Traveller traveller)
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Visualization");
    window.setFramerateLimit(60);

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
                std::cout << position.x << ", " << position.y << '\n';
                traveller.propulsion(position, window);
            }
        }

        window.clear();
        traveller.propulsion(window);
        traveller.update_physics(planets);
        for(GravitySource planet: planets){
            planet.render(window);
        }
        traveller.render(window);
        traveller.traceTrajectory(traveller, window, trajectory);

        //draw calls
        window.display();
    }
    return 0;
}

std::vector<GravitySource> planetGen(int num){

    std::vector<GravitySource> planets;
    srand((unsigned) time(NULL));
    float mass, posX, posY;
    for(int i = 0; i < num; ++i){
        float mass = (rand() % (5000 - 1000 + 1)) + 1000;
        float posX = (rand() % (1500 - 100 + 1)) + 100;
        float posY = (rand() % (900 - 100 + 1)) + 100;
        planets.push_back(GravitySource(posX, posY, mass));
    }
    int increment = 1;
    for(GravitySource planet: planets){
        std::cout << "Planet " << increment << "\n";
        std::cout << "Mass:  " << planet.getMass() << " Pos_x: " << planet.getPos().x << " Pos_y: " << planet.getPos().y << "\n";
        ++increment;
    }

    return planets;
}

sf::Vector2f initCoordinates(){
    sf::Vector2f initPosition;
    srand((unsigned)time(NULL));
    float posx = rand() % 1600;
    float posy = rand() % 1000;
    initPosition.x = posx;
    initPosition.y = posy;

    return initPosition;
}

int main()
{
    // Random generation algorithm
    //bottom-left
    GravitySource planetA(600, 500, 1000);
    //top-left
    GravitySource planetB(600, 200, 1500);
    //bottom-right
    GravitySource planetC(900, 500, 1950);
    //top-right
    GravitySource planetD(900, 200, 1200);
//    GravitySource planetTest(800,500, 4000);

    std::vector<GravitySource> planets = {planetA, planetB, planetC, planetD};
//    sf::Vector2f pos = initCoordinates();
    Traveller traveller(901, 700, 0, 0, 50);


    std::map<int, GravitySource> order = Algos::orderAlgorithm(planets, traveller);
    // should take in dt
//    visualize( planets, traveller );

    return 0;
}
