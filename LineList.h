#ifndef LINELIST_H
#define LINELIST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Line.h"
#include "Config.h"
#include "AirportList.h"

#include "Money.h"
#include "ClockTime.h"

using namespace std;
using namespace sf;

class LineList : public Drawable
{
    public:
        LineList();
        ~LineList();

        void createNewLine();
        //void updateEventNewLineCreator(Event *event, Vector2f *worldPos, AirportList *airportList, GUI_Line *guiLine);
        void updateMoney(Money *money, ClockTime *clockTime);
        void update();

        //void drawLineCreator(GUI_Line *guiLine);
        void drawLineGUI();

        int getLineQuantity(string category);
        int getLineQuantity();

        Line* getLine(int idLine);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            /*for(unsigned int i = 0; i < vecGuiLine.size(); i++)
            {
                //target.draw(vecGuiLine[i], states);
            }

            //target.draw(guiLine);*/
        }
        Font font;

        Config config;
        int width, height;

        Line line;
        vector<Line> vecLine;

/*        GUI_Line guiLine;
        vector<GUI_Line> vecGuiLine;*/

        int _lineQuantityNational = 0;
        int _lineQuantityInternational = 0;

        int _actualTime = 0;
};

#endif // LINELIST_H
