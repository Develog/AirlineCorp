#include "Game.h"

#define DEBUG 1

Game::Game(string title)
{
    widthScreen = config.getSetting(0);
    heightScreen = config.getSetting(1);

    width = config.getSetting(2);
    height = config.getSetting(3);

    if(DEBUG)
    {
        ssBuild << config.getBuild();
        config.updateBuild();
    }
    else
    {
        ssBuild << config.getBuild();
    }

    RenderWindow window(VideoMode(widthScreen, heightScreen), "[V0.01." + ssBuild.str() + "]" + title, Style::Default);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(30);

    ContextSettings settings;
    settings.antialiasingLevel = 32;

    View viewScreen(FloatRect(0, 0, width, height));

    ScreenManager screenManager;

    Event event;

    Society society;

    ClockTime clockTime;

    AirportList airportList;

    PlaneList planeList;

    Money money;

    Hangar hangar;

    ScenarioList scenarioList;


    Vector2i pixelPos;
    Vector2f worldPos;

    while (window.isOpen())
    {
        clockTime.updateTime();
        screenManager.update(&society, &clockTime, &planeList, &money, &hangar, &scenarioList);
        while (window.pollEvent(event))
        {
            pixelPos = Mouse::getPosition(window);
            worldPos = window.mapPixelToCoords(pixelPos);

            screenManager.updateEvent(&event, &worldPos, &airportList, &window);

            if ( (event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape) )
            {
                window.close();
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Color(48, 48, 48, 0));
        window.setView(viewScreen);
        window.draw(screenManager);
        window.display();
    }
}
