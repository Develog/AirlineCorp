#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen_Main.h"
#include "Screen_Menu.h"
#include "Screen_NewGame.h"

using namespace sf;

class ScreenManager : public Drawable
{
    public:
        ScreenManager();

        void updateEvent(Event *event, Vector2f *worldPos, AirportList *airportList, RenderWindow *window);
        void update(Society *society, ClockTime *clockTime, PlaneList *planeList, Money *money, Hangar *hangar, ScenarioList *scenarioList);

        void setScreen(String screenName);
        String getScreen() const;
    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            if(this->getScreen() == "Menu")
                target.draw(sMenu, states);
            if(this->getScreen() == "NewGame")
                target.draw(sNewGame, states);
            if(this->getScreen() == "Main")
                target.draw(sMain, states);
        }

        String _screenName;

        Screen_Main sMain;
        Screen_Menu sMenu;
        Screen_NewGame sNewGame;

        bool firstUpdate = true;
        bool firstUpdateNewGame = true;
};

#endif // SCREENMANAGER_H
