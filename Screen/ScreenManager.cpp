#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
    this->setScreen("Menu");
}


void ScreenManager::updateEvent(Event *event, Vector2f *worldPos, AirportList *airportList, RenderWindow *window)
{
    if(this->getScreen() == "Menu")
    {
        if(sMenu.buttonPlayIsClicked(event, worldPos))
        {
            this->setScreen("NewGame");
        }
        sMenu.buttonQuitIsClicked(event, worldPos, window);
    }

    if(this->getScreen() == "Main")
    {
        sMain.updateEvent(event, worldPos, airportList);
    }

    if(this->getScreen() == "NewGame")
    {
        if(sNewGame.buttonIsClicked(event, worldPos))
        {
            this->setScreen("Main");
        }
        sNewGame.updateEvent(event, worldPos);
    }
}

void ScreenManager::update(Society *society, ClockTime *clockTime, PlaneList *planeList, Money *money, Hangar *hangar, ScenarioList *scenarioList)
{
    if(this->getScreen() == "Menu")
    {

    }

    if(this->getScreen() == "Main")
    {
        sMain.update(society, clockTime, planeList, money, hangar);
        if(firstUpdate)
        {
            sNewGame.update(society, money);
            firstUpdate = false;
        }
    }

    if(this->getScreen() == "NewGame")
    {
        if(firstUpdateNewGame)
        {
            sNewGame.loadScenario(scenarioList);
            firstUpdateNewGame = false;
        }
    }
}

void ScreenManager::setScreen(String screenName)
{
    _screenName = screenName;
}

String ScreenManager::getScreen() const
{
    return _screenName;
}
