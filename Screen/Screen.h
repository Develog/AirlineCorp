#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SFML/Graphics.hpp>

class Screen
{
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

#endif
