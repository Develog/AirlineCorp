#include "GUI_Hangar.h"

GUI_Hangar::GUI_Hangar()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    width = config.getSetting(2);
    height = config.getSetting(3);

    scrollAreaHangar.setSize(Vector2f(width - 20, height /2 + height / 4 - 100));
    scrollAreaHangar.setBackgroundColor(Color(48,48,48));
    scrollAreaHangar.setColor(Color(48,48,48));
    scrollAreaHangar.setPosition(Vector2f(10, height / 4 + 40));
    scrollAreaHangar.activateOutline(false);

    scrollAreaLine.setSize(Vector2f(width - 20, height /2 + height / 4 - 100));
    scrollAreaLine.setBackgroundColor(Color(48,48,48));
    scrollAreaLine.setColor(Color(48,48,48));
    scrollAreaLine.setPosition(Vector2f(10, height / 4 + 40));
    scrollAreaLine.activateOutline(false);

    textLineList.setFont(font);
    textLineList.setCharacterSize(30);
    textLineList.setString("Line selection");
    gbTextLineList = textLineList.getGlobalBounds();
    textLineList.setPosition(Vector2f(width / 2 - gbTextLineList.width / 2, backgroundLineSelection.getPosition().y + 10));

    textYourPlane.setFont(font);
    textYourPlane.setCharacterSize(35);
    textYourPlane.setString("Your plane(s) :");
    textYourPlane.setStyle(Text::Underlined);
    gbTextYourPlane = textYourPlane.getGlobalBounds();
    textYourPlane.setPosition(Vector2f(width / 2 - gbTextYourPlane.width / 2, scrollAreaHangar.getPosition().y - 60));



    if(!textureSchedule.loadFromFile("Resource/Schedule.png"))
        cout << "error texture" << endl;
}

GUI_Hangar::~GUI_Hangar()
{
    //dtor
}

//Add a plane to the hangar GUI
void GUI_Hangar::addPlane(Plane* plane)
{
    textArea[_planeQuantity] = new TextArea();
    textArea[_planeQuantity]->setSize(Vector2f(scrollAreaHangar.getSize().x - 20 - scrollAreaHangar.getScrollBarSize().x, 150));
    textArea[_planeQuantity]->setPosition(Vector2f(scrollAreaHangar.getPosition().x + 10, scrollAreaHangar.getPosition().y + 10 + _planeQuantity * 155));
    textArea[_planeQuantity]->setColor(Color(100, 100, 100));
    scrollAreaHangar.addTextArea(textArea[_planeQuantity]);

    textArea[_planeQuantity]->addText(Vector2f(0, 0), plane->getManufactureName() + " - " + plane->getPlaneName(), 25);
    textArea[_planeQuantity]->addText(Vector2f(0, 25), plane->getName(), 25);
    textArea[_planeQuantity]->addText(Vector2f(0, 50), "Buying date : " + plane->getBuyingDate(), 25);
    textArea[_planeQuantity]->addText(Vector2f(0, 100), "Condition : 100 %", 25);
    textArea[_planeQuantity]->addShape(Vector2f(textArea[_planeQuantity]->getSize().x - 1450, 50), Vector2f(1200, 75), Color::Red);
    textArea[_planeQuantity]->addButton(Vector2f(textArea[_planeQuantity]->getSize().x - 125, 25), Vector2f(100, 100), Color::Blue, "Assign");

    vecQuantityOfFlightByPlane.push_back(0);

    _planeQuantity += 1;
}

void GUI_Hangar::updateEvent(Event *event, Vector2f *worldPos)
{
    scrollAreaHangar.updateEvent(event, worldPos);
    scrollAreaHangar.update();

    //Si le bouton assign d'un avion est cliqué alors on affiche les rectangles en fonction des vols de cet avion
    //on récupère le nombre de flight sur l'avion, si plus qu'actuellement alors on addShape et ensuite on récupère l'horaire et la durée de chaque vol

    for(int i = 0; i < _planeQuantity; i++)
    {
        if(textArea[i]->buttonIsClicked(event, worldPos) && !assignLineDraw)
        {
            assignLineDraw = true;
            idButton = i;
            buttonAssignPlaneIsClicked = true;
            LineSelectionActivate = true;
        }
    }

    for(int i = 0; i < _lineQuantity; i++)
    {
        if(textAreaLine[i]->buttonIsClicked(event, worldPos, 0) && assignLineDraw)
        {
            cout << "click " << endl;
            assignLineDraw = false;
            idButtonLine = i;
            buttonAssignLineToPlane = true;
            LineSelectionActivate = false;
        }

        //hour
        if(textAreaLine[i]->buttonIsClicked(event, worldPos, 1) && stoi(textAreaLine[i]->getTextValue(0)) >= 1)
        {
            vecValueHour[i] = stoi(textAreaLine[i]->getTextValue(0)) - 1;
            textAreaLine[i]->setTextEditableText(0, to_string(vecValueHour[i]));
            textAreaLine[i]->setShapePosition(0, Vector2f(10 + 38 * (float(vecValueHour[i]) + (float(vecValueMinute[i]) / 60)), 40));
        }

        if(textAreaLine[i]->buttonIsClicked(event, worldPos, 2) && stoi(textAreaLine[i]->getTextValue(0)) <= 22)
        {
            vecValueHour[i] = stoi(textAreaLine[i]->getTextValue(0)) + 1;
            textAreaLine[i]->setTextEditableText(0, to_string(vecValueHour[i]));
            textAreaLine[i]->setShapePosition(0, Vector2f(10 + 38 * (float(vecValueHour[i]) + (float(vecValueMinute[i]) / 60)), 40));
        }

        //minute
        if(textAreaLine[i]->buttonIsClicked(event, worldPos, 3) && stoi(textAreaLine[i]->getTextValue(1)) >= 1)
        {
            vecValueMinute[i] = stoi(textAreaLine[i]->getTextValue(1)) - 15;
            textAreaLine[i]->setTextEditableText(1, to_string(vecValueMinute[i]));
            textAreaLine[i]->setShapePosition(0, Vector2f(10 + 38 * (float(vecValueHour[i]) + (float(vecValueMinute[i]) / 60)), 40));
        }

        if(textAreaLine[i]->buttonIsClicked(event, worldPos, 4) && stoi(textAreaLine[i]->getTextValue(1)) <= 30)
        {
            vecValueMinute[i] = stoi(textAreaLine[i]->getTextValue(1)) + 15;
            textAreaLine[i]->setTextEditableText(1, to_string(vecValueMinute[i]));
            textAreaLine[i]->setShapePosition(0, Vector2f(10 + 38 * (float(vecValueHour[i]) + (float(vecValueMinute[i]) / 60)), 40));
        }
        vecValue[i] = float(vecValueHour[i]) + (float(vecValueMinute[i]) / 60);
    }
}

void GUI_Hangar::update(LineList *lineList, Hangar *hangar, PlaneList *planeList, FlightList *flighList)
{
    if(assignLineDraw)
    {
        _lineQuantity = lineList->getLineQuantity();
    }

    if(lastLineQuantity != _lineQuantity)
    {
        ///Create a textArea for each line
        ///TODO Need to draw only the lines which are reachable by the plane
        for(int i = lastLineQuantity; i < _lineQuantity; i++)
        {
            vecValueHour.push_back(valueVec);
            vecValueMinute.push_back(valueVec);
            vecValue.push_back(valueVecFloat);

            vecValueHour[vecValueHour.size() - 1] = 0;
            vecValueMinute[vecValueMinute.size() - 1] = 0;
            vecValue[vecValue.size() - 1] = 0;

            textAreaLine[i] = new TextArea();

            textAreaLine[i]->setSize(Vector2f((scrollAreaLine.getSize().x - 20 - scrollAreaLine.getScrollBarSize().x) / 2, 150));
            textAreaLine[i]->setPosition(Vector2f((scrollAreaLine.getPosition().x + 5) + (textAreaLine[i]->getSize().x + 5) * (i % 2), scrollAreaLine.getPosition().y + 5 + (i / 2) * 155));
            textAreaLine[i]->setColor(Color(100, 100, 100));
            scrollAreaLine.addTextArea(textAreaLine[i]);

            textAreaLine[i]->addText(Vector2f(0, 0), "Center", lineList->getLine(i)->getOrigin() + " <--> " + lineList->getLine(i)->getDestination(), 25, Style::None);
            textAreaLine[i]->addText(Vector2f(textAreaLine[i]->getSize().x / 4, 80), "Hour", 25);
            textAreaLine[i]->addEditableText(Vector2f(textAreaLine[i]->getSize().x / 4, 110), "00", 25);
            textAreaLine[i]->addText(Vector2f(textAreaLine[i]->getSize().x / 4 + textAreaLine[i]->getSize().x / 2, 80), "Minute", 25);
            textAreaLine[i]->addEditableText(Vector2f(textAreaLine[i]->getSize().x / 4 + textAreaLine[i]->getSize().x / 2, 110), "30", 25);
            textAreaLine[i]->setTextEditableText(1, "00");
            textAreaLine[i]->addButton(Vector2f(textAreaLine[i]->getSize().x / 2 - 75, 90), Vector2f(150, 50), Color::Red, "Assign");

            textAreaLine[i]->addButton(Vector2f(textAreaLine[i]->getSize().x / 4 - 30, 115), Vector2f(20, 20), Color::Red, "");
            textAreaLine[i]->addButton(Vector2f(textAreaLine[i]->getSize().x / 4 + 40, 115), Vector2f(20, 20), Color::Red, "");

            textAreaLine[i]->addButton(Vector2f(textAreaLine[i]->getSize().x / 4 + textAreaLine[i]->getSize().x / 2 - 30, 115), Vector2f(20, 20), Color::Red, "");
            textAreaLine[i]->addButton(Vector2f(textAreaLine[i]->getSize().x / 4 + textAreaLine[i]->getSize().x / 2 + 40, 115), Vector2f(20, 20), Color::Red, "");

            textAreaLine[i]->addSprite(Vector2f(5, 35), Vector2f(920, 50), "Resource/Test2.png");
            textAreaLine[i]->addShape(Vector2f(10 + 38 * vecValueHour[i], 40), Vector2f(38 * (2 * (float(lineList->getLine(idButtonLine)->getDistance()) / float(hangar->getPlane(idButton)->getSpeed()) + 0.66f)), 40), Color::Green);
        }

        lastLineQuantity = _lineQuantity;
    }

    if(_lineQuantity > 0 && vecQuantityOfFlightByPlane[idButton] < flighList->getNumberOfFlight(idButton))
    {
        while(flighList->getNumberOfFlight(idButton) > vecQuantityOfFlightByPlane[idButton])
        {
            for(int i = 0; i < _lineQuantity; i++)
            {
                cout << "new shape" << endl;
                textAreaLine[i]->addShape(Vector2f(0, 0), Vector2f(0, 0), Color(0, 0, 0, 0));
            }
            vecQuantityOfFlightByPlane[idButton]++;
        }
    }


    //When we clicked on a plane
    ///PARTIE IMPORTANTE
    if(buttonAssignPlaneIsClicked)
    {
        cout << " clmizcax " << endl;

        for(int i = 0; i < _lineQuantity; i++)
        {
            textAreaLine[i]->setShapeSize(0 ,Vector2f(38 * (2 * (float(lineList->getLine(i)->getDistance()) / float(hangar->getPlane(idButton)->getSpeed()) + 0.66f)), 40));

            for(int j = 0; j < flighList->getNumberOfFlight(idButton); j++)
            {
                textAreaLine[i]->setShapeSize(j + 1, Vector2f(100, 100));

                cout << "important : " << idButton << " | " << j << " | " << flighList->getFlightData(j, idButton).getDepartureTime() << endl;
                textAreaLine[i]->setShapePosition(j + 1, Vector2f(10 + 38 * flighList->getFlightData(j, idButton).getDepartureTime(), 40));
                textAreaLine[i]->setShapeSize(j + 1, Vector2f(38 * flighList->getFlightData(j, idButton).getDuration(), 40));
                textAreaLine[i]->setShapeColor(j + 1, Color::Red);
            }
        }
        buttonAssignPlaneIsClicked = false;
    }

    if(buttonAssignLineToPlane)
    {
        if(hangar->getPlane(idButton)->getRadius() > lineList->getLine(idButtonLine)->getDistance())
        {
            time = (2 * (float(lineList->getLine(idButtonLine)->getDistance()) / float(hangar->getPlane(idButton)->getSpeed()) + 0.66f));
            lineList->getLine(idButtonLine)->addFlight(hangar->getPlane(idButton), vecValue[idButtonLine]);
            flighList->addFlight(vecValue[idButtonLine], time, lineList->getLine(idButtonLine)->getOrigin(), lineList->getLine(idButtonLine)->getDestination(), idButton, Society::getICAO_Code() + to_string(flighList->getTotalNumberOfFlight()));
            hangar->getPlane(idButton)->addFlight();

            ///hangar->getPlane(idButton)->isAssign(true, vecValue[idButtonLine], time); NE FAIT RIEN
            cout << "Duration of flight : " << (2 * (float(lineList->getLine(idButtonLine)->getDistance()) / float(hangar->getPlane(idButton)->getSpeed()) + 0.66f)) << endl;
            cout << "Number of airline flight : " << flighList->getTotalNumberOfFlight() << endl;
            cout << "Number of plane flight : " << flighList->getNumberOfFlight(idButton) << endl;

            for(int i = 0; i < _lineQuantity; i++)
            {
                vecValue[i] = 0;
                vecValueHour[i] = 0;
                vecValueMinute[i] = 0;
                textAreaLine[i]->setShapePosition(0, Vector2f(10 + 38 * vecValueHour[i], 40));
                textAreaLine[i]->setTextEditableText(0, "0");
                textAreaLine[i]->setTextEditableText(1, "0");
            }
        }
        else
        {
            cout << "Can't assign because the plane's radius is too small" << endl;
        }
        buttonAssignLineToPlane = false;
        buttonAssignPlaneIsClicked = false;
    }
}
