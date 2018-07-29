#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <time.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Screen/ScreenManager.h"
#include "Screen_Main.h"
#include "Screen_Menu.h"
#include "Screen_NewGame.h"
#include "Config.h"
#include "Society.h"
#include "ClockTime.h"
#include "LineList.h"
#include "AirportList.h"
#include "Money.h"
#include "Hangar.h"
#include "ScenarioList.h"

using namespace sf;

class Game
{
    public:
        Game(string title);

    private:
        Config config;

        int widthScreen, heightScreen, width, height;

        stringstream ssBuild;
};

#endif // GAME_H
