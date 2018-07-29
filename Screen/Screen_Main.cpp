#include "Screen_Main.h"

Screen_Main::Screen_Main()
{
    width = config.getSetting(2);
    height = config.getSetting(3);

    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    if(!texPlane1.loadFromFile("Resource/Plane1.png"))
        cout << "Error loading plane1.png" << endl;

    if(!texPlane2.loadFromFile("Resource/Plane2.png"))
        cout << "Error loading plane2.png" << endl;

    if(!texCEO.loadFromFile("Resource/CEO.png"))
        cout << "Error loading CEO.png" << endl;

    if(!texEarth.loadFromFile("Resource/Earth.png"))
        cout << "Error loading Earth.png" << endl;

    if(!texMoney.loadFromFile("Resource/Money.png"))
        cout << "Error loading Money.png" << endl;

    if(!texClock.loadFromFile("Resource/Clock.png"))
        cout << "Error loading Clock.png" << endl;

    plane1.setTexture(texPlane1);
    //plane1.setColor(Color(180, 180, 180));

    plane2.setTexture(texPlane2);
    //plane2.setColor(Color(180, 180, 180));

    sprCEO.setTexture(texCEO);
    sprCEO.setPosition(Vector2f(0, 0));

    sprEarth.setTexture(texEarth);
    sprEarth.setPosition(Vector2f(0, 50));

    sprMoney.setTexture(texMoney);
    sprMoney.setPosition(Vector2f(0, 100));

    sprClock.setTexture(texClock);
    sprClock.setPosition(Vector2f(width - width / 6, 0));

    rect.setSize(Vector2f(width, 140));
    rect.setFillColor(Color(100, 100, 100));

    textBossName.setFont(font);
    textBossName.setPosition(Vector2f(texCEO.getSize().x + 15, 0));
    textBossName.setCharacterSize(30);

    textSocietyName.setFont(font);
    textSocietyName.setCharacterSize(40);

    textAirportName.setFont(font);
    textAirportName.setCharacterSize(30);
    textAirportName.setPosition(Vector2f(texEarth.getSize().x + 15, 50));

    textTime.setFont(font);
    textTime.setCharacterSize(25);

    textDate.setFont(font);
    textDate.setCharacterSize(25);

    textMoney.setFont(font);
    textMoney.setCharacterSize(30);

    buttonLineView.setSize(width / 7 - 1, 100);
    buttonLineView.setPosition(0, rect.getSize().y);
    buttonLineView.setColor(75, 75, 75);
    buttonLineView.setText("Line view", 25);

    buttonHangar.setSize(width / 7 - 2, 100);
    buttonHangar.setPosition(width / 7 + 1, rect.getSize().y);
    buttonHangar.setColor(75, 75, 75);
    buttonHangar.setText("Hangar", 25);

    buttonObjective.setSize(width / 7 - 2, 100);
    buttonObjective.setPosition((width / 7) * 2 + 1, rect.getSize().y);
    buttonObjective.setColor(75, 75, 75);
    buttonObjective.setText("Objective", 25);

    buttonUpgrade.setSize(width / 7 - 2, 100);
    buttonUpgrade.setPosition((width / 7) * 3 + 1, rect.getSize().y);
    buttonUpgrade.setColor(75,75,75);
    buttonUpgrade.setText("Upgrade", 25);

    buttonNewLine.setSize(width / 7 - 2, 100);
    buttonNewLine.setPosition((width / 7) * 4 + 1, rect.getSize().y);
    buttonNewLine.setColor(75, 75, 75);
    buttonNewLine.setText("New Line", 25);

    buttonNewEmployee.setSize(width / 7 - 2, 100);
    buttonNewEmployee.setPosition((width / 7) * 5 + 1, rect.getSize().y);
    buttonNewEmployee.setColor(75, 75, 75);
    buttonNewEmployee.setText("New Employee", 25);

    buttonNewPlane.setSize(width / 7 - 1, 100);
    buttonNewPlane.setPosition((width / 7) * 6 + 1, rect.getSize().y);
    buttonNewPlane.setColor(75, 75, 75);
    buttonNewPlane.setText("New Plane", 25);

    buttonSpeed1.setSize(60, 40);
    buttonSpeed1.setSprite("Resource/Speed1.png");

    buttonSpeed2.setSize(60, 40);
    buttonSpeed2.setSprite("Resource/Speed2.png");

    buttonSpeed3.setSize(60, 40);
    buttonSpeed3.setSprite("Resource/Speed3.png");

    highLine.setSize(Vector2f(width, 2));
    highLine.setPosition(Vector2f(0, rect.getSize().y + buttonNewLine.getHeight()));
    highLine.setFillColor(Color::White);

    middleLine.setSize(Vector2f(2, height));
    middleLine.setFillColor(Color::White);
    middleLine.setPosition(Vector2f(width / 2, highLine.getPosition().y));

    textInternational.setFont(font);
    textInternational.setCharacterSize(35);
    textInternational.setString("International Flight");
    textInternational.setStyle(Text::Underlined);
    gbTextInternational = textInternational.getGlobalBounds();
    textInternational.setPosition(Vector2f(width / 4 - gbTextInternational.width / 2, highLine.getPosition().y + 10));

    textNational.setFont(font);
    textNational.setCharacterSize(35);
    textNational.setString("National Flight");
    textNational.setStyle(Text::Underlined);
    gbTextNational = textNational.getGlobalBounds();
    textNational.setPosition(Vector2f(width / 4 + width / 2 - gbTextNational.width / 2, highLine.getPosition().y + 10));
}

Screen_Main::~Screen_Main()
{

}

void Screen_Main::updateEvent(Event *event, Vector2f *worldPos, AirportList *airportList)
{
    if(buttonLineView.isClicked(event, worldPos))
    {
        hangarDraw = false;
        lineViewDraw = true;
        objectiveDraw = false;
        planeStoreDraw = false;
        newLineDraw = false;
    }
    if(buttonHangar.isClicked(event, worldPos))
    {
        hangarDraw = true;
        lineViewDraw = false;
        objectiveDraw = false;
        planeStoreDraw = false;
        newLineDraw = false;
    }

    if(buttonObjective.isClicked(event, worldPos))
    {
        hangarDraw = false;
        lineViewDraw = false;
        objectiveDraw = true;
        planeStoreDraw = false;
        newLineDraw = false;
    }

    if(buttonNewPlane.isClicked(event, worldPos))
    {
        hangarDraw = false;
        lineViewDraw = false;
        objectiveDraw = false;
        planeStoreDraw = true;
        newLineDraw = false;
        buttonNewPlaneIsClicked = true;
    }

    if(buttonNewLine.isClicked(event, worldPos))
    {
        hangarDraw = false;
        lineViewDraw = false;
        objectiveDraw = false;
        planeStoreDraw = false;
        newLineDraw = true;
    }

    if(GUI_PlaneStore.isStoreDraw())
    {
        GUI_PlaneStore.updateEvent(event, worldPos);
    }


    if(buttonNewLine.isClicked(event, worldPos))
    {
        //lineList.drawLineCreator(&GUI_Line);
    }
    if(buttonNewLine.isClicked(event, worldPos) && !GUI_Line.isNewLineDraw())
    {
        buttonNewLineIsClicked = true;
    }
    if(GUI_Line.isNewLineDraw())
    {
        GUI_Line.updateEvent(event, worldPos);
        if(GUI_Line.isSubmit(event, worldPos))
        {
            lineList.createNewLine();
            GUI_Line.updateLine(&lineList);
            GUI_LineView.createNewLineView(&lineList);
            lineViewDraw = true;
        }
    }


    if(buttonSpeed1.isClicked(event, worldPos))
    {
        buttonSpeed1IsClicked = true;
    }
    if(buttonSpeed2.isClicked(event, worldPos))
    {
        buttonSpeed2IsClicked = true;
    }
    if(buttonSpeed3.isClicked(event, worldPos))
    {
        buttonSpeed3IsClicked = true;
    }

    //lineList.updateEventNewLineCreator(event, worldPos, airportList, &GUI_Line);

    if(hangarDraw)
    {
        GUI_Hangar.updateEvent(event, worldPos);
    }
}

void Screen_Main::update(Society *society, ClockTime *clockTime, PlaneList *planeList, Money *money, Hangar *hangar)
{
    if(buttonNewPlaneIsClicked)
    {
        GUI_PlaneStore.drawPlaneStore(&config, planeList);
        buttonNewPlaneIsClicked = false;
    }
    if(buttonNewLineIsClicked)
    {
        GUI_Line.drawLineCreator(society, width, height);
        buttonNewLineIsClicked = false;
    }

    if(buttonSpeed1IsClicked)
    {
        clockTime->setSpeed(1);
        buttonSpeed1IsClicked = false;
    }
    if(buttonSpeed2IsClicked)
    {
        clockTime->setSpeed(0.1);
        buttonSpeed2IsClicked = false;
    }
    if(buttonSpeed3IsClicked)
    {
        clockTime->setSpeed(0.01);
        buttonSpeed3IsClicked = false;
    }

    if(hangarDraw)
    {
        GUI_Hangar.update(&lineList, hangar, planeList, &flightList);
    }

    if(planeStoreDraw)
    {
        GUI_PlaneStore.update(planeList, money, hangar, &GUI_Hangar);
    }

    if(newLineDraw)
    {
        GUI_Line.update();
    }

    if(lineViewDraw)
    {
        GUI_LineView.update(&lineList);
    }

    if(objectiveDraw)
    {
        GUI_Objective.update(money, society);
    }

    //lineList.updateMoney(money, clockTime);

    flightList.updateMoney(money, clockTime, hangar, society);


    textBossName.setString("CEO : " + society->getBossName());
    textSocietyName.setString(society->getSocietyName());
    textAirportName.setString("Departure Hub : " + society->getDepartureCity());

    ssDayIG.str("");
    ssMonthIG.str("");
    ssYearIG.str("");
    ssHourIG.str("");
    ssMinuteIG.str("");

    ssDayIG << clockTime->getDayIG();
    ssMonthIG << clockTime->getMonthIG();
    ssYearIG << clockTime->getYearIG();
    ssHourIG << clockTime->getHourIG();
    ssMinuteIG << clockTime->getMinuteIG();

    if(clockTime->getMinuteIG() < 10)
        ssMinuteIG.str("0" + ssMinuteIG.str());
    if(clockTime->getHourIG() < 10)
        ssHourIG.str("0" + ssHourIG.str());
    if(clockTime->getDayIG() < 10)
        ssDayIG.str("0" + ssDayIG.str());
    if(clockTime->getMonthIG() < 10)
        ssMonthIG.str("0" + ssMonthIG.str());

    textDate.setString(ssDayIG.str() + "/" + ssMonthIG.str() + "/" + ssYearIG.str());
    textTime.setString("Monday - " + ssHourIG.str() + " h " + ssMinuteIG.str());

    textMoney.setString("Money : " + Function::NumberToSpaceNumber(money->getMoney()));
    gbTextMoney = textMoney.getGlobalBounds();
    textMoney.setPosition(Vector2f(texMoney.getSize().x + 10, 100));

    if(firstUpdate)
    {
        gbTextTime = textTime.getGlobalBounds();
        textTime.setPosition(Vector2f(width / 2 - gbTextTime.width / 2, plane1.getPosition().y + texPlane1.getSize().y + 20));
        textTime.setPosition(Vector2f(sprClock.getPosition().x + texClock.getSize().x + 10, 0));
        textDate.setPosition(Vector2f(sprClock.getPosition().x + texClock.getSize().x + 10, 50));
        buttonSpeed1.setPosition(width / 2 - buttonSpeed1.getWidth() - buttonSpeed1.getWidth() / 2, textTime.getPosition().y + gbTextTime.height + 20);
        buttonSpeed2.setPosition(width / 2 - buttonSpeed2.getWidth() / 2, textTime.getPosition().y + gbTextTime.height + 20);
        buttonSpeed3.setPosition(width / 2 + buttonSpeed3.getWidth() / 2, textTime.getPosition().y + gbTextTime.height + 20);
        firstUpdate = false;
    }

    gbTextSocietyName = textSocietyName.getGlobalBounds();
    textSocietyName.setPosition(Vector2f(width / 2 - gbTextSocietyName.width / 2, 0));

    plane1.setPosition(Vector2f(width / 2 - gbTextSocietyName.width / 2 - 60, 15));
    plane2.setPosition(Vector2f(width / 2 + gbTextSocietyName.width / 2 + 6, 15));
}

