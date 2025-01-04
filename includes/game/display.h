#ifndef DISPLAY_H
#define DISPLAY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../constants.h"
#include "engine.h"
using namespace std;

class display
{
public:
    display();

    void run();

    void update();

    void processEvents();

    void processRealTimeEvents();

    void render();

    void draw();

private:
    sf::RenderWindow window; // window that renders the game
    sf::Font font;           // font to draw on main screen
    sf::Text myTextLabel;    // text to draw on main screen
    Engine engine;
};

#endif