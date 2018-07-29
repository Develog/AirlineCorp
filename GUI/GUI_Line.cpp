#include "GUI_Line.h"

GUI_Line::GUI_Line()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    width = config.getSetting(2);
    height = config.getSetting(3);

    strContinent[0] = "Europe";
    strContinent[1] = "North America";
    strContinent[2] = "South America";
    strContinent[3] = "Asia";
    strContinent[4] = "Oceania";
    strContinent[5] = "Africa";
}

GUI_Line::~GUI_Line()
{
    //dtor
}

void GUI_Line::drawLineCreator(Society *society, int width, int height)
{
    activate = true;
    newLineDraw = true;
    societyAirport = society->getSocietyAirport();

    textOrigin.setFont(font);
    textOrigin.setCharacterSize(45);
    textOrigin.setString("Departure Hub");
    gbTextOrigin = textOrigin.getGlobalBounds();
    textOrigin.setPosition(Vector2f(width / 2 - width / 4 - gbTextOrigin.width / 2, 250));
    textOrigin.setStyle(Text::Underlined);

    textOriginAirport.setFont(font);
    textOriginAirport.setCharacterSize(45);
    textOriginAirport.setString(societyAirport);
    gbTextOriginAirport = textOriginAirport.getGlobalBounds();
    textOriginAirport.setPosition(Vector2f(width / 2 - width / 4 - gbTextOriginAirport.width / 2, 300));


    textDestination.setFont(font);
    textDestination.setCharacterSize(45);
    textDestination.setString("Arrival Airport");
    gbTextDestination = textDestination.getGlobalBounds();
    textDestination.setPosition(Vector2f(width / 2 + width / 4 - gbTextDestination.width / 2, 250));
    textDestination.setStyle(Text::Underlined);

    textDestinationAirport.setFont(font);
    textDestinationAirport.setCharacterSize(45);
    textDestinationAirport.setString("");

    for(int i = 0; i < 6; i++)
    {
        buttonContinent[i].setFont("Resource/Arial.ttf");
        buttonContinent[i].setSize(width / 6, 50);
        buttonContinent[i].setColor(100, 100, 100);
        buttonContinent[i].setPosition(i * width / 6, 400);
    }

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int id = j * 6 + i;
            buttonCountry[id].setFont("Resource/Arial.ttf");
            buttonCountry[id].setSize(width / 6 - 5, 40);
            buttonCountry[id].setColor(48, 48, 48);
            buttonCountry[id].setPosition(i * (width / 6 + 1), 455 + j * 45);

            buttonAirport[id].setFont("Resource/Arial.ttf");
            buttonAirport[id].setSize(width / 6 - 5, 40);
            buttonAirport[id].setColor(48, 48, 48);
            buttonAirport[id].setPosition(i * (width / 6 + 1), 455 + j * 45);
        }
    }


    textDistanceLine.setFont(font);
    textDistanceLine.setCharacterSize(40);

    textPPIOriginAirport.setFont(font);
    textPPIOriginAirport.setCharacterSize(40);

    textPPIDestinationAirport.setFont(font);
    textPPIDestinationAirport.setCharacterSize(40);

    textAIOriginAirport.setFont(font);
    textAIOriginAirport.setCharacterSize(40);

    textAIDestinationAirport.setFont(font);
    textAIDestinationAirport.setCharacterSize(40);

    lineCenter.setSize(Vector2f(4, height - buttonContinent[0].getPosition().y - 200));
    lineCenter.setFillColor(Color::Black);
    lineCenter.setPosition(Vector2f(width / 2, buttonContinent[0].getPosition().y + buttonContinent[0].getHeight() * 2));

    buttonSubmit.setSize(width / 3, 90);
    buttonSubmit.setColor(120, 120, 120);
    buttonSubmit.setPosition(width / 2 - buttonSubmit.getWidth() / 2, height - buttonSubmit.getHeight() - 50);
    buttonSubmit.setText("Create new line", 30);
}

void GUI_Line::updateEvent(Event *event, Vector2f *worldPos)
{
    if(buttonSubmit.isClicked(event, worldPos) && activate)
    {
        activate = false;
        newLineDraw = false;
        airportSelection = false;
        countrySelection = true;
        lineInformation = false;
        countryNumber = 0;
        textDistanceLine.setString("");
    }

    //Selection of the country
    for(int i = 0; i < 6; i++)
    {
        buttonContinent[i].setText(strContinent[i], 20);

        if(buttonContinent[i].isHoover(worldPos))
        {
            buttonContinent[i].setColor(120, 120, 120);
        }
        else
        {
            buttonContinent[i].setColor(100, 100, 100);
        }

        if(buttonContinent[i].isClicked(event, worldPos))
        {
            countryNumber = 0;
            buttonContinentIsClicked = true;
            airportSelection = false;
            countrySelection = true;
            lineInformation = false;
            int k = 0;
            for(int l = 0; l < 60; l++)
            {
                strCountry[l] = "";
                buttonCountry[l].setText(strCountry[i], 18);
            }
            for(int j = 0; j < 67; j++)
            {
                if(countryList.country[j]->getContinentName() == strContinent[i])
                {
                    strCountry[k] = countryList.country[j]->getCountryName();
                    countryNumber++;
                    k++;
                }
            }
            for(int i = 0; i < 60; i++)
            {
                buttonCountry[i].setText(strCountry[i], 18);
            }
        }
    }

    //Selection of the airport
    for(int i = 0; i < countryNumber; i++)
    {
        if(buttonCountry[i].isHoover(worldPos))
        {
            buttonCountry[i].setColor(70, 70, 70);
        }
        else
        {
            buttonCountry[i].setColor(48, 48, 48);
        }

        if(buttonCountry[i].isClicked(event, worldPos)  && countrySelection)
        {
            airportNumber = 0;
            airportSelection = true;
            countrySelection = false;
            int m = 0;
            for(int l = 0; l < 60; l++)
            {
                strAirport[l] = "";
                buttonAirport[l].setText(strAirport[l], 18);
            }
            for(int j = 0; j < airportQuantity; j++)
            {
                if(airportList.airport[j]->getCountry() == strCountry[i])
                {
                    strAirport[m] = airportList.airport[j]->getName();
                    airportNumber++;
                    m++;
                }
            }

            for(int i = 0; i < 60; i++)
            {
                buttonAirport[i].setText(strAirport[i], 18);
            }
        }
    }


    for(int i = 0; i < airportNumber; i++)
    {
        if(buttonAirport[i].isHoover(worldPos))
        {
            buttonAirport[i].setColor(70, 70, 70);

        }
        else
        {
            buttonAirport[i].setColor(48, 48, 48);
        }

        if(buttonCountry[i].isClicked(event, worldPos))
        {
            id = i;
            if(id == i)
            {
                if(buttonAirport[i].isClicked(event, worldPos) && airportSelection && !firstClick)
                {
                    airportDestination = strAirport[id];
                    textDestinationAirport.setString(airportDestination);
                    gbTextDestinationAirport = textDestinationAirport.getGlobalBounds();
                    textDestinationAirport.setPosition(Vector2f(width / 2 + width / 4 - gbTextDestinationAirport.width / 2, 300));
                    lineInformation = true;
                    firstClick = true;
                    isEnter = true;
                }

                if(buttonContinentIsClicked)
                {
                    firstClick = false;
                    buttonContinentIsClicked = false;
                }

                if(buttonAirport[id].isClicked(event, worldPos) && airportSelection && firstClick && !isEnter)
                {
                    firstClick = false;
                    isEnter = false;
                }
            }
            else
            {
                if(buttonAirport[i].isClicked(event, worldPos) && airportSelection)
                {
                    airportDestination = strAirport[i];
                    textDestinationAirport.setString(airportDestination);
                    gbTextDestinationAirport = textDestinationAirport.getGlobalBounds();
                    textDestinationAirport.setPosition(Vector2f(width / 2 + width / 4 - gbTextDestinationAirport.width / 2, 300));
                    lineInformation = true;
                    firstClick = true;
                }
            }
        }
    }
}

void GUI_Line::updateLine(LineList *lineList)
{
    lineList->getLine(idLine)->setOrigin(societyAirport);
    lineList->getLine(idLine)->setDestination(airportDestination);

    for(int i = 0; i < airportList.getNumberOfAirport(); i++)
    {
        if(societyAirport == airportList.getName(i))
        {idOrigin = i;}
    }

    for(int i = 0; i < airportList.getNumberOfAirport(); i++)
    {
        if(airportDestination == airportList.getName(i))
        {idDestination = i;}
    }

    if(airportList.getCountry(idOrigin) == airportList.getCountry(idDestination))
    {
        lineList->getLine(idLine)->setCategory("National");
    }
    else if(airportList.getCountry(idOrigin) != airportList.getCountry(idDestination))
    {
        lineList->getLine(idLine)->setCategory("International");
    }

    lineList->getLine(idLine)->setDistance(airportList.getDistance(lineList->getLine(idLine)->getOrigin(), lineList->getLine(idLine)->getDestination()));

    idLine += 1;
}

void GUI_Line::update()
{
    this->simulateLine();
}

void GUI_Line::simulateLine()
{
    if(lineInformation)
    {
        for(int i = 0; i < airportList.getNumberOfAirport(); i++)
        {
            if(societyAirport == airportList.getName(i))
            {idOrigin = i;}
        }
        for(int i = 0; i < airportList.getNumberOfAirport(); i++)
        {
            if(airportDestination == airportList.getName(i))
            {idDestination = i;}
        }


        ssDistance.str("");
        ssDistance << airportList.getDistance(societyAirport, airportDestination);
        textDistanceLine.setString("Distance : " + ssDistance.str() + " km");
        gbTextDistanceLine = textDistanceLine.getGlobalBounds();
        textDistanceLine.setPosition(Vector2f(width / 2 - gbTextDistanceLine.width / 2, buttonContinent[0].getPosition().y + buttonContinent[0].getHeight()));

        ssPPIOrigin.str("");
        ssPPIOrigin << floor(airportList.getAirportData(idOrigin)->getCloseInhabitant() * airportList.getAirportData(idOrigin)->getPotentialPassengerIndex() / 365);
        textPPIOriginAirport.setString("Potential Passenger : " + ssPPIOrigin.str() + " per day");
        textPPIOriginAirport.setPosition(Vector2f(20, 500));

        ssPPIDestination.str("");
        ssPPIDestination << floor(airportList.getAirportData(idDestination)->getCloseInhabitant() * airportList.getAirportData(idDestination)->getPotentialPassengerIndex() / 365);
        textPPIDestinationAirport.setString("Potential Passenger : " + ssPPIDestination.str() + " per day");
        textPPIDestinationAirport.setPosition(Vector2f(lineCenter.getPosition().x + 20, 500));

        ssAIOrigin.str("");
        ssAIOrigin << floor(airportList.getAirportData(idOrigin)->getCloseInhabitant() * airportList.getAirportData(idOrigin)->getAttractionIndex() / 365);
        textAIOriginAirport.setString("Passenger Attraction : " + ssAIOrigin.str() + " per day");
        textAIOriginAirport.setPosition(Vector2f(20, 600));

        ssAIDestination.str("");
        ssAIDestination << floor(airportList.getAirportData(idDestination)->getCloseInhabitant() * airportList.getAirportData(idDestination)->getAttractionIndex() / 365);
        textAIDestinationAirport.setString("Passenger Attraction : " + ssAIDestination.str() + " per day");
        textAIDestinationAirport.setPosition(Vector2f(lineCenter.getPosition().x + 20, 600));
    }
}

bool GUI_Line::isSubmit(Event *event, Vector2f *worldPos)
{
    if(buttonSubmit.isClicked(event, worldPos))
    {
        textboxOrigin.Reset();
        textboxDestination.Reset();
        //firstClick = false;
        return true;
    }
    else
        return false;
}

bool GUI_Line::isNewLineDraw()
{
    return newLineDraw;
}

