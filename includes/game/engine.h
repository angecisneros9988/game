#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../constants.h"
using namespace std;

class Engine
{
public:
    Engine();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow &widnow);

private:
    sf::RectangleShape box;
    sf::Vector2f vel;
};

#endif // SYSTEM_H
