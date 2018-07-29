#ifndef GUI_LINE_H
#define GUI_LINE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include "LineList.h"
#include "Line.h"
#include "Button.h"
#include "TextBox.h"
#include "AirportList.h"
#include "Config.h"
#include "CountryList.h"
#include "AirportList.h"
#include "Society.h"

using namespace sf;

class GUI_Line : public Drawable
{
    public:
        GUI_Line();
        ~GUI_Line();

        void drawLineCreator(Society *society, int width, int height);
        void updateEvent(Event *event, Vector2f *worldPos);
        void updateLine(LineList *lineList);
        void updateLine(Line *line, AirportList *airportList);
        void drawLineView(Line *line, int idLineNational, int idLineInternational, int windowWidth, Font *font);
        void createNewLineView(LineList *lineList);
        void updateLineView(Line *line);
        void update();
        void simulateLine();

        bool isSubmit(Event *event, Vector2f *worldPos);
        bool isNewLineDraw();

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            if(activate)
            {
                target.draw(textOrigin, states);
                target.draw(textDestination, states);
                target.draw(textOriginAirport, states);
                target.draw(textDestinationAirport, states);

                for(int i = 0; i < 6; i++)
                {
                    target.draw(buttonContinent[i], states);
                }
                for(int i = 0; i < 60; i++)
                {
                    if(!airportSelection)
                        target.draw(buttonCountry[i], states);
                }
                for(int i = 0; i < 60; i++)
                {
                    if(!countrySelection && !lineInformation)
                        target.draw(buttonAirport[i], states);
                }

                if(lineInformation)
                {
                    target.draw(textDistanceLine, states);
                    target.draw(lineCenter, states);
                    target.draw(textPPIOriginAirport, states);
                    target.draw(textPPIDestinationAirport, states);
                    target.draw(textAIOriginAirport, states);
                    target.draw(textAIDestinationAirport, states);
                }

                target.draw(buttonSubmit, states);
            }
        }
        bool activate = false;
        bool newLineDraw = false;

        Font font;

        Text textOrigin;
        Text textDestination;

        Text textOriginAirport;
        Text textDestinationAirport;

        FloatRect gbTextOrigin;
        FloatRect gbTextDestination;

        FloatRect gbTextOriginAirport;
        FloatRect gbTextDestinationAirport;


        Text textDistanceLine;
        FloatRect gbTextDistanceLine;
        RectangleShape lineCenter;

        Text textPPIOriginAirport;
        Text textPPIDestinationAirport;
        Text textAIOriginAirport;
        Text textAIDestinationAirport;

        TextBox textboxOrigin;
        TextBox textboxDestination;

        bool countrySelection = true;
        bool airportSelection = false;
        bool firstClick = true;
        bool isEnter = false;
        bool buttonContinentIsClicked = false;

        Button buttonContinent[6];
        Button buttonCountry[60];
        Button buttonAirport[60];

        string strContinent[6];
        string strCountry[60];
        string strAirport[60];

        int countryNumber, airportNumber;
        int airportQuantity = 17;

        string airportDestination;
        string societyAirport;

        stringstream ssDistance;
        stringstream ssPPIOrigin;
        stringstream ssPPIDestination;
        stringstream ssAIOrigin;
        stringstream ssAIDestination;

        bool lineInformation = false;

        CountryList countryList;
        AirportList airportList;

        Button buttonSubmit;

        Config config;

        int width, height;
        int posX, posY;
        int idLine = 0;

        int id;

        int idOrigin = 0;
        int idDestination = 0;
};

#endif // GUI_LINE_H
