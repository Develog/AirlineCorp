#ifndef SCREEN_MENU_H
#define SCREEN_MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUI/Button.h"
#include "Society.h"
#include "Config.h"

using namespace std;
using namespace sf;

class Screen_Menu : public Drawable
{
public:
    Screen_Menu();
    ~Screen_Menu();

    bool buttonPlayIsClicked(Event *event, Vector2f *worldPos);
    void buttonQuitIsClicked(Event *event, Vector2f *worldPos, RenderWindow *window);
private:
    virtual void draw(RenderTarget& target, RenderStates states) const
    {
        target.draw(background, states);
        target.draw(buttonPlay, states);
        target.draw(buttonSettings, states);
        target.draw(buttonQuit, states);
    }

    Button buttonPlay;
    Button buttonSettings;
    Button buttonQuit;

    Sprite background;
    Texture texBackground;

    Config config;

    int width, height;
    int space = 0;
};

#endif
