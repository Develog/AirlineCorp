#include "Screen_Map.h"

Screen_Map::Screen_Map(void)
{
    GameView.setCenter(sf::Vector2f(map.getView()));
    GameView.setSize(sf::Vector2f(Game::getWindowWidth(), Game::getWindowHeight()));

    GUIView.setCenter(sf::Vector2f(Game::getWindowWidth() / 2, Game::getWindowHeight() / 2));
    GUIView.setSize(sf::Vector2f(Game::getWindowWidth(), Game::getWindowHeight()));

    map.load();
    Resources::setQuantityWheat(1000);
    Resources::setQuantityWood(100);
    Resources::setQuantityOre(500);
    cout << Resources::getProductionWheat() << endl;


}

int Screen_Map::Run(sf::RenderWindow &window)
{
    bool a;
    GUI gui;
    gui.drawPurchaseBar();
    sf::Event event;
    bool Running = true;

    while (Running)
    {
        gui.Update();
        resources.Update();

        sf::FloatRect GB_GameView(GameView.getCenter().x - GameView.getSize().x/2.f, GameView.getCenter().y - GameView.getSize().y/2.f, GameView.getSize().x, GameView.getSize().y);
        while (window.pollEvent(event))
        {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

            gui.updatePurchaseBar(&event, &worldPos);

            if (event.type == sf::Event::Closed)
            {
                window.close();
                return (-1);
            }

            if(event.type == sf::Event::LostFocus)
            {
                focus = false;
            }

            if (event.type == sf::Event::GainedFocus)
            {
                focus = true;
            }

            if(focus == true)
            {
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
                return (-1);

                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A) )
                    return (0);

                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Z) )
                    return (2);


                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Z) )
                {
                    Resources::setProductionWheat(Resources::getProductionWheat() + 100);
                }

                // X
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right) )
                {
                    GameView.move(50, 0);
                }
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left) )
                {
                    GameView.move(-50, 0);
                }

                // Y
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down) )
                {
                    GameView.move(0, 50);
                }
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up) )
                {
                    GameView.move(0, -50);
                }

                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::X) )
                {
                    a = true;
                }
                if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::C) )
                {
                    a = false;
                }

                cout << a << endl;

                //std::cout << map.getIDVisibleTile(GB_GameView) << std::endl;


                //ZOOM
                if (event.type == sf::Event::MouseWheelMoved)
                {
                    if(event.mouseWheel.delta > 0)
                    {
                        GameView.zoom(0.9f);
                    }
                    else
                    {
                        GameView.zoom(1.1f);
                    }
                }
            }
            window.clear(sf::Color(0, 0, 0, 0));
            window.setView(GameView);
            window.draw(map);
            if(focus == true)
                map.Update(window);
            window.setView(GUIView);
            window.draw(gui);
            if(a == true)
                gui.drawBidule(window);
            window.display();
        }


    }

    //Never reaching this point normally, but just in case, exit the application
    return -1;
}
