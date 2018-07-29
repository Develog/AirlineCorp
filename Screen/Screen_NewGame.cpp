#include "Screen_NewGame.h"

Screen_NewGame::Screen_NewGame()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
    {
        cout << "Error loading font" << endl;
    }

    screenWidth = config.getSetting(2);
    screenHeight = config.getSetting(3);

    textAirlineName.setFont(font);
    textAirlineName.setCharacterSize(45);
    textAirlineName.setString("Airline Name");
    gbTextAirlineName = textAirlineName.getGlobalBounds();
    textAirlineName.setPosition(screenWidth / 4 - gbTextAirlineName.width / 2, 50);

    textBossName.setFont(font);
    textBossName.setCharacterSize(45);
    textBossName.setString("CEO Name");
    gbTextBossName = textBossName.getGlobalBounds();
    textBossName.setPosition(screenWidth / 4 + screenWidth / 2 - gbTextBossName.width / 2, 50);

    textCountry.setFont(font);
    textCountry.setCharacterSize(45);
    textCountry.setString("Country");
    gbTextCountry = textCountry.getGlobalBounds();
    textCountry.setPosition(screenWidth / 4 - gbTextCountry.width / 2, 700);

    textCity.setFont(font);
    textCity.setCharacterSize(45);
    textCity.setString("City");
    gbTextCity = textCity.getGlobalBounds();
    textCity.setPosition(screenWidth / 4 + screenWidth / 2 - gbTextCity.width / 2, 700);


    textboxAirlineName.setSize(Vector2f(500, 100));
    textboxAirlineName.setPosition(Vector2f(screenWidth / 4 - textboxAirlineName.getSize().x / 2, 130));
    textboxAirlineName.setValue("Name here");

    textboxBossName.setSize(Vector2f(500, 100));
    textboxBossName.setPosition(Vector2f(screenWidth / 4 + screenWidth / 2 - textboxBossName.getSize().x / 2, 130));
    textboxBossName.setValue("Name here");


    buttonSubmit.setSize(500, 125);
    buttonSubmit.setPosition(screenWidth / 2 - buttonSubmit.getWidth() / 2, screenHeight - 150);
    buttonSubmit.setColor(130, 130, 130);
    buttonSubmit.setText("Create airline", 35);

    scrollArea.setSize(Vector2f(screenWidth - 100, screenHeight - 450));
    scrollArea.setPosition(Vector2f(50, textboxAirlineName.getPosition().y + textboxAirlineName.getSize().y + 50));
    scrollArea.setColor(Color::White);
    scrollArea.setBackgroundColor(Color(48, 48, 48));

    for(int i = 0; i < 6; i++)
    {
        textareaContract[i].setSize(Vector2f(scrollArea.getSize().x - 55, 150));
        if(i == 0){textareaContract[i].setPosition(Vector2f(scrollArea.getPosition().x + 5, scrollArea.getPosition().y + 10));}
        else{textareaContract[i].setPosition(Vector2f(scrollArea.getPosition().x + 5, textareaContract[i - 1].getPosition().y + textareaContract[i - 1].getSize().y + 5));}
        textareaContract[i].setColor(Color(120, 120, 120));
        scrollArea.addTextArea(&textareaContract[i]);
    }
}

Screen_NewGame::~Screen_NewGame()
{

}

void Screen_NewGame::updateEvent(Event *event, Vector2f *worldPos)
{
    textboxAirlineName.getKeyboardValue(event, worldPos);
    textboxBossName.getKeyboardValue(event, worldPos);
    scrollArea.updateEvent(event, worldPos);
    scrollArea.update();
    for(int i = 0; i < 6; i++)
    {
        if(textareaContract[i].isClicked(event, worldPos) && worldPos->y >= scrollArea.getPosition().y && worldPos->y <= scrollArea.getPosition().y + scrollArea.getSize().y)
        {
            id = i;
            textAreaIsClicked[i] = true;
        }
        if(textAreaIsClicked[i])
        {
            for(int j = 0; j < 6; j++)
            {
                textareaContract[j].setColor(Color(120, 120, 120));
            }
            textareaContract[i].setColor(Color(120, 180, 120));
            textAreaIsClicked[i] = false;
        }
    }
}

void Screen_NewGame::update(Society *society, Money *money)
{
    if(isClicked)
    {
        society->setSocietyName(textboxAirlineName.getValue());
        society->setBossName(textboxBossName.getValue());
        society->setIATA_Code("AF");
        society->setICAO_Code("AFR");
        society->setDepartureCity(airportName[id]);
        society->setSocietyAirport(airportName[id]);
        money->setMoney(moneyContract[id]);
        society->setContractID(id);
    }
}

bool Screen_NewGame::buttonIsClicked(Event *event, Vector2f *worldPos)
{
    if(buttonSubmit.isClicked(event, worldPos))
    {
        isClicked = true;
        return true;
    }
    /*else
        isClicked = false;
        return false;*/
}

void Screen_NewGame::loadScenario(ScenarioList *scenarioList)
{
    for(int i = 0; i < 6; i++)
    {
        textareaContract[i].addText(Vector2f(5, 0),scenarioList->getScenarioData(i)->getAirportName() + " - " + scenarioList->getScenarioData(i)->getAirportCode(), 30);
        textareaContract[i].addText(Vector2f(5, 35), scenarioList->getScenarioData(i)->getCityName() + " (" + scenarioList->getScenarioData(i)->getCountryName() + ")", 30);
        if(scenarioList->getScenarioData(i)->getCategoryLevel() == 1){categoryLevel = "Long haul";}else if(scenarioList->getScenarioData(i)->getCategoryLevel() == 2){categoryLevel = "Medium Haul";}else{categoryLevel = "Short Haul";}
        textareaContract[i].addText(Vector2f(5, 70), "Acceptable plane : " + categoryLevel, 30);
        textareaContract[i].addText(Vector2f(5, 105), "Money : " + Function::NumberToSpaceNumber(scenarioList->getScenarioData(i)->getMoneyObjective()) + " Euros", 30);

        ssContractDuration << scenarioList->getScenarioData(i)->getContractDuration();
        textareaContract[i].addText(Vector2f(textareaContract[i].getSize().x / 2, 0), "Objective : Contract duration : " + ssContractDuration.str() + " years", 30, Text::Underlined);
        textareaContract[i].addText(Vector2f(textareaContract[i].getSize().x / 2, 35), "Passenger objective : " + Function::NumberToSpaceNumber(scenarioList->getScenarioData(i)->getPassengerObjective()) + " on " + ssContractDuration.str() + " years", 30);
        textareaContract[i].addText(Vector2f(textareaContract[i].getSize().x / 2, 70), "Flight objective : " + Function::NumberToSpaceNumber(scenarioList->getScenarioData(i)->getFlightObjective()) + " on " + ssContractDuration.str() + " years", 30);
        textareaContract[i].addText(Vector2f(textareaContract[i].getSize().x / 2, 105), "Money objective : " + Function::NumberToSpaceNumber(scenarioList->getScenarioData(i)->getMoneyObjective()) + " on " + ssContractDuration.str() + " years", 30);

        airportName[i] = scenarioList->getScenarioData(i)->getAirportName();

        moneyContract[i] = scenarioList->getScenarioData(i)->getMoneyObjective();

        ssMoney.str("");
        ssContractDuration.str("");
    }

}
