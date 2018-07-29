#ifndef SCREEN_MAP_H
#define SCREEN_MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Map.h"
#include "GUI.h"
#include "Resources.h"

using namespace std;

class Screen_Map : public Screen
{
public:
    Screen_Map(void);
    virtual int Run(sf::RenderWindow &window);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {

        }

        sf::View GameView;
        sf::View GUIView;

        Map map;
        Resources resources;

        bool focus = true;

};

#endif
