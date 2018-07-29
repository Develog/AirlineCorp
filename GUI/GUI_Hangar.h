#ifndef GUI_HANGAR_H
#define GUI_HANGAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Plane.h"
#include "Button.h"
#include "LineList.h"
#include "Hangar.h"
#include "PlaneList.h"
#include "FlightList.h"
#include "Config.h"
#include "Cursor.h"
#include "TextBox.h"
#include "ScrollableArea.h"
#include "TextArea.h"
#include "Society.h"

using namespace sf;
using namespace std;

class GUI_Hangar : public Drawable
{
    public:
        GUI_Hangar();
        ~GUI_Hangar();

        void addPlane(Plane* plane);
        void updateEvent(Event *event, Vector2f *worldPos);
        void update(LineList *lineList, Hangar *hangar, PlaneList *planeList, FlightList *flighList);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(scrollAreaHangar, states);
            target.draw(textYourPlane, states);

            if(LineSelectionActivate)
            {
                target.draw(scrollAreaLine, states);
                target.draw(textLineList, states);

                for(unsigned int i = 0; i < vecRectLineSelection.size(); i++)
                {
                    target.draw(vecRectLineSelection[i], states);
                    target.draw(vecLineName[i], states);
                    target.draw(vecButtonAssign[i], states);
                }
            }
        }

        int _planeQuantity;
        int _lineQuantity;

        float departureHour;
        float departureMinute;

        Font font;

        Config config;

        Text textYourPlane;
        FloatRect gbTextYourPlane;

        ScrollableArea scrollAreaHangar;
        ScrollableArea scrollAreaLine;

        TextArea *textAreaLine[10000];
        vector <TextArea> vecTextAreaLine;
        TextArea *ptr_textAreaLine;


        TextArea *textArea[100000];

        RectangleShape planeView;
        vector <RectangleShape> vecPlaneView;

        Text textPlaneName;
        vector <Text> vecTextPlaneName;

        Button buttonAssignPlane;
        vector <Button> vecButtonAssignPlane;

        /// To draw line selection GUI
        RectangleShape backgroundLineSelection;

        Texture textureSchedule;

        FloatRect gbTextLineList;
        Text textLineList;

        RectangleShape rectLineSelection;
        vector <RectangleShape> vecRectLineSelection;

        Text textLineName;
        vector <Text> vecLineName;

        Button buttonAssign;
        vector <Button> vecButtonAssign;

        bool buttonAssignIsClicked, assignAreaDraw;
        bool assignLineDraw = false;
        vector <bool> vecButtonAssignIsClicked;


        int width, height;

        int lastLineQuantity = 0;
        int idButtonLine = 0;
        bool buttonAssignLineToPlane = false;

        int idButton = 0;
        int idLine = 0;
        bool buttonAssignPlaneIsClicked = false;
        bool LineSelectionActivate = false;

        int valueVec;
        float valueVecFloat;
        vector <int> vecValueHour;
        vector <int> vecValueMinute;
        vector <float> vecValue;

        float valueHour, valueMinute, value;
        stringstream strValueHour, strValueMinute;

        float time;

        int quantityOfFlightByPlane = 0;
        vector <int> vecQuantityOfFlightByPlane;
};

#endif // GUI_HANGAR_H
