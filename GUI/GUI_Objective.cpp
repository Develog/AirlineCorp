#include "GUI_Objective.h"

GUI_Objective::GUI_Objective()
{
    width = config.getSetting(2);
    height = config.getSetting(3);

    if(!font.loadFromFile("Resource/Arial.ttf")) {cout << "error font loading" << endl;}

    textObjective.setFont(font);
    textObjective.setCharacterSize(35);
    textObjective.setString("Objective");
    textObjective.setStyle(Text::Underlined);
    gbTextObjective = textObjective.getGlobalBounds();
    textObjective.setPosition(Vector2f(width / 4 - gbTextObjective.width / 2, height / 4 - 20));

    textContractObjective.setFont(font);
    textContractObjective.setCharacterSize(35);
    textContractObjective.setString("Contract Objective");
    textContractObjective.setStyle(Text::Underlined);
    gbTextContractObjective = textContractObjective.getGlobalBounds();
    textContractObjective.setPosition(Vector2f(width / 4 + width / 2 - gbTextContractObjective.width / 2, height / 4 - 20));

    middleLine.setSize(Vector2f(2, 1000));
    middleLine.setFillColor(Color::White);
    middleLine.setPosition(Vector2f(width / 2, height / 4 - 40));

    for(int i = 0; i < 3; i++)
    {
        textContractObjectiveInProgress[i].setFont(font);
        textContractObjectiveInProgress[i].setCharacterSize(30);
    }

    passengerObjective = scenarioList.getScenarioData(Society::getContractID())->getPassengerObjective();
    flightObjective = scenarioList.getScenarioData(Society::getContractID())->getFlightObjective();
    moneyObjective = scenarioList.getScenarioData(Society::getContractID())->getMoneyObjective();
}

GUI_Objective::~GUI_Objective()
{
    //dtor
}

void GUI_Objective::update(Money *money, Society *society)
{
    textContractObjectiveInProgress[0].setString("Passenger objective : " + Function::NumberToSpaceNumber(society->getTotalPassenger()) + " / " + Function::NumberToSpaceNumber(passengerObjective));
    textContractObjectiveInProgress[1].setString("Flight objective : 0 / " + Function::NumberToSpaceNumber(flightObjective));
    textContractObjectiveInProgress[2].setString("Money objective : " + Function::NumberToSpaceNumber(money->getFlightIncome()) + " / " + Function::NumberToSpaceNumber(moneyObjective));

    for(int i = 0; i < 3; i++)
    {
        gbTextContractObjectiveInProgress[i] = textContractObjectiveInProgress[i].getGlobalBounds();
        textContractObjectiveInProgress[i].setPosition(Vector2f(middleLine.getPosition().x + 20, textContractObjective.getPosition().y + 100 + 50 * i));
    }
}
