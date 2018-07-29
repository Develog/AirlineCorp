#ifndef SCREEN_NEWGAME_H
#define SCREEN_NEWGAME_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Config.h"
#include "GUI/Button.h"
#include "GUI/TextBox.h"
#include "GUI/ScrollableArea.h"
#include "Society.h"
#include "GUI/TextArea.h"
#include "ScenarioList.h"
#include "Money.h"
#include "Function.h"

using namespace sf;

class Screen_NewGame : public Drawable
{
    public:
        Screen_NewGame();
        ~Screen_NewGame();

        void updateEvent(Event *event, Vector2f *worldPos);
        void update(Society *society, Money *money);
        bool buttonIsClicked(Event *event, Vector2f *worldPos);

        void loadScenario(ScenarioList *scenarioList);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(scrollArea, states);
            target.draw(textAirlineName, states);
            target.draw(textBossName, states);
            target.draw(textboxAirlineName, states);
            target.draw(textboxBossName, states);
            target.draw(buttonSubmit, states);
        }

        Text textAirlineName;
        Text textBossName;
        Text textCountry;
        Text textCity;

        FloatRect gbTextAirlineName;
        FloatRect gbTextBossName;
        FloatRect gbTextCountry;
        FloatRect gbTextCity;

        TextBox textboxAirlineName;
        TextBox textboxBossName;

        //const static int textareaQuantity = 6;
        ScrollableArea scrollArea;
        TextArea textareaContract[6];

        string categoryLevel;
        stringstream ssMoney, ssContractDuration, ssPassengerObjective, ssFlightObjective, ssMoneyObjective;

        string airportName[6];
        int id = 0;
        int moneyContract[6];

        Font font;

        Button buttonSubmit;

        bool textAreaIsClicked[6];

        Config config;
        int screenWidth, screenHeight;

        bool isClicked = false;
};

#endif // SCREEN_NEWGAME_H
