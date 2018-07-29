#ifndef GUI_OBJECTIVE_H
#define GUI_OBJECTIVE_H

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "Society.h"
#include "ScenarioList.h"
#include "Money.h"
#include "Function.h"

using namespace std;
using namespace sf;

class GUI_Objective : public Drawable
{
    public:
        GUI_Objective();
        ~GUI_Objective();

        void update(Money *money, Society *society);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(textObjective, states);
            target.draw(textContractObjective, states);
            target.draw(middleLine, states);

            for(int i = 0; i < 3; i++)
            {
                target.draw(textContractObjectiveInProgress[i], states);
            }
        }

        Config config;
        int width, height;

        int passengerObjective = 0;
        int flightObjective = 0;
        int moneyObjective = 0;

        ScenarioList scenarioList;

        Font font;

        Text textObjective;
        FloatRect gbTextObjective;

        Text textContractObjective;
        FloatRect gbTextContractObjective;

        Text textContractObjectiveInProgress[3];
        FloatRect gbTextContractObjectiveInProgress[3];

        RectangleShape middleLine;
};

#endif // GUI_OBJECTIVE_H
