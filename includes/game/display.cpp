#include "display.h"

display::display()
{
    cout << "display CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "game window!");
    engine = Engine();
    window.setFramerateLimit(60);
    cout << "Geme CTOR. preparing to load the font." << endl;
    //--- FONT ----------
    // font file must be in the "working directory:
    //      debug folder
    // Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    // font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 5));
    cout << "animate instantiated successfully." << endl;
}

void display::run()
{
    while (window.isOpen())
    {
        processEvents();
        processRealTimeEvents();
        update();
        render(); // clear/draw/display
    }
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}

void display::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) // or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            // case sf::Keyboard::Left:
            //     engine.Step(1);
            //     break;
            // case sf::Keyboard::Right:
            //     engine.Step(2);
            //     break;
            case sf::Keyboard::Escape:
                window.close();
                break;
            }

        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
                // case sf::Keyboard::Left:
                //     engine.Step(1001);
                //     break;
                // case sf::Keyboard::Right:
                //     engine.Step(1002);
                //     break;
            }

            break;

        default:
            break;
        }
    }
}

void display::processRealTimeEvents()
{
    int keyPressed = 0;

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     engine.Step(1);
    // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     engine.Step(2);
    // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //     engine.Step(3);
    // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //     engine.Step(4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        engine.Step(5);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        engine.Step(6);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        engine.Step(7);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        engine.Step(8);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        engine.Step(0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        engine.Step(0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        engine.Step(1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        engine.Step(2);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        engine.Step(3);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        engine.Step(4);
}

void display::update()
{
    // cause changes to the data for the next frame
    engine.Step(0); // 0 is null in this case
}

void display::render()
{
    window.clear();
    draw();
    window.display();
}

void display::draw()
{
    engine.Draw(window);
    window.draw(myTextLabel);
}