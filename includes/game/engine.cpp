#include "engine.h"

Engine::Engine()
{
    int xpos = 100;
    int ypos = 100;
    // the shape of the object, along with its velocity, acceleration,
    // position, etc. should be part of the individual object.
    box = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    box.setOrigin(5.f, 5.f);
    box.setPosition(sf::Vector2f(xpos, ypos));
    vel = sf::Vector2f(0, 0); // random velocity
    box.setFillColor(sf::Color::Green);
}

//------------------------------------------------------------------
//------------------------------------------------------------------

// basically what will make the box move
// note each number will correspond to a
// command in which it coordinates the movement
// of our rectangle
void Engine::Step(int command)
{
    // all this is the responsibility of the
    //  individual object:
    box.move(vel);
    // sf::Vector2f pos = box.getPosition();
    // if ((pos.x) >= SCREEN_WIDTH - 20)
    //     vel = sf::Vector2f(-1 * vel.x, 1 * vel.y);
    // if (pos.x <= 0)
    //     vel = sf::Vector2f(-1 * vel.x, 1 * vel.y);
    // if ((pos.y) >= SCREEN_HEIGHT - 20)
    //     vel = sf::Vector2f(1 * vel.x, -1 * vel.y);
    // if (pos.y <= 0)
    //     vel = sf::Vector2f(1 * vel.x, -1 * vel.y);

    // add the code block below once you can get that
    // box moving

    switch (command)
    {
    case 1: // move left
        // cout << "left key pressed" << endl;
        vel = sf::Vector2f(-10, 0);
        break;
    case 2: // move right
        vel = sf::Vector2f(10, 0);
        break;
    case 3: // move up
        vel = sf::Vector2f(0, -10);
        break;
    case 4: // move down
        vel = sf::Vector2f(0, 10);
        break;
    case 5:
        vel = sf::Vector2f(10, 10);
        break;
    case 6:
        vel = sf::Vector2f(-10, 10);
        break;
    case 7:
        vel = sf::Vector2f(10, -10);
        break;
    case 8:
        vel = sf::Vector2f(-10, -10);
        break;
    default:
        vel = sf::Vector2f(0, 0);
        break;
    }
}

void Engine::Draw(sf::RenderWindow &window)
{
    window.clear();
    window.draw(box);
}
