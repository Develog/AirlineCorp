#include "Screen_Battle.h"

Screen_Battle::Screen_Battle(void)
{

}

int Screen_Battle::Run(sf::RenderWindow &window)
{
    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        while (window.pollEvent(Event))
        {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

            if ( (Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape) )
            {
                return (-1);
            }
            if ( (Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A) )
            {
                return (1);
            }
        }
        window.clear(sf::Color(35, 100, 20, 0));
        window.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
