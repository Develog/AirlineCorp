#ifndef SCREEN_MAIN_H
#define SCREEN_MAIN_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Society.h"
#include "Config.h"
#include "Button.h"
#include "ClockTime.h"
#include "LineList.h"
#include "GUI_PlaneStore.h"
#include "PlaneList.h"
#include "GUI_Hangar.h"
#include "GUI_Line.h"
#include "GUI_LineView.h"
#include "GUI_Objective.h"
#include "Function.h"

using namespace sf;

class Screen_Main : public Drawable
{
    public:
        Screen_Main();
        ~Screen_Main();

        void updateEvent(Event *event, Vector2f *worldPos, AirportList *airportList);
        void update(Society *society, ClockTime *clockTime, PlaneList *planeList, Money *money, Hangar *hangar);
    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            if(planeStoreDraw)
            {
                target.draw(GUI_PlaneStore, states);
            }

            if(newLineDraw)
            {
                target.draw(GUI_Line, states);
            }

            if(hangarDraw)
            {
                target.draw(GUI_Hangar, states);
            }

            if(objectiveDraw)
            {
                target.draw(GUI_Objective, states);
            }

            target.draw(rect, states);
            target.draw(highLine, states);
            target.draw(textBossName, states);
            target.draw(sprCEO, states);
            target.draw(sprEarth, states);
            target.draw(sprMoney, states);
            target.draw(sprClock, states);
            target.draw(textSocietyName, states);
            target.draw(textAirportName, states);
            target.draw(textTime, states);
            target.draw(textDate, states);
            target.draw(textMoney, states);
            target.draw(plane1, states);
            target.draw(plane2, states);
            target.draw(buttonLineView, states);
            target.draw(buttonHangar, states);
            target.draw(buttonObjective, states);
            target.draw(buttonUpgrade, states);
            target.draw(buttonNewLine, states);
            target.draw(buttonNewEmployee, states);
            target.draw(buttonNewPlane, states);
            target.draw(buttonSpeed1, states);
            target.draw(buttonSpeed2, states);
            target.draw(buttonSpeed3, states);
            if(lineViewDraw)
            {
                target.draw(middleLine, states);
                target.draw(textInternational, states);
                target.draw(textNational, states);
                target.draw(lineList, states);
                target.draw(GUI_LineView, states);
            }
        }

        GUI_PlaneStore GUI_PlaneStore;
        GUI_Hangar GUI_Hangar;
        GUI_Line GUI_Line;
        GUI_LineView GUI_LineView;
        GUI_Objective GUI_Objective;

        AirportList airportList;
        LineList lineList;
        FlightList flightList;

        RectangleShape rect;
        RectangleShape highLine;
        RectangleShape middleLine;

        Font font;

        Sprite plane1;
        Sprite plane2;

        Texture texPlane1;
        Texture texPlane2;

        Sprite sprCEO;
        Texture texCEO;

        Sprite sprEarth;
        Texture texEarth;

        Sprite sprMoney;
        Texture texMoney;

        Sprite sprClock;
        Texture texClock;

        Text textBossName;
        Text textSocietyName;
        Text textAirportName;

        FloatRect gbTextSocietyName;
        FloatRect gbTextTime;

        Button buttonLineView;
        Button buttonHangar;
        Button buttonObjective;
        Button buttonUpgrade;
        Button buttonNewLine;
        Button buttonNewEmployee;
        Button buttonNewPlane;

        Button buttonSpeed1;
        Button buttonSpeed2;
        Button buttonSpeed3;

        Text textInternational;
        Text textNational;

        FloatRect gbTextInternational;
        FloatRect gbTextNational;

        Config config;

        Text textDate;
        Text textTime;
        stringstream ssDayIG;
        stringstream ssMonthIG;
        stringstream ssYearIG;
        stringstream ssHourIG;
        stringstream ssMinuteIG;

        Text textMoney;
        stringstream ssMoney;
        FloatRect gbTextMoney;

        int width, height;

        bool lineViewDraw = true;
        bool hangarDraw = false;
        bool objectiveDraw = false;
        bool planeStoreDraw = false;
        bool newLineDraw = false;

        bool firstUpdate = true;
        bool buttonNewPlaneIsClicked = false, buttonNewLineIsClicked = false;
        bool buttonSpeed1IsClicked = false, buttonSpeed2IsClicked = false, buttonSpeed3IsClicked = false, buttonHangarIsClicked = false;
};

#endif // SCREEN_MAIN_H

