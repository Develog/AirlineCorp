#ifndef GUI_PLANESTORE_H
#define GUI_PLANESTORE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <locale>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "PlaneList.h"
#include "Money.h"
#include "Button.h"
#include "Hangar.h"
#include "GUI_Hangar.h"
#include "GUI/ScrollableArea.h"
#include "Function.h"

#define PLANEQUANTITY 15

using namespace std;
using namespace sf;

class GUI_PlaneStore : public Drawable
{
    public:
        GUI_PlaneStore();
        ~GUI_PlaneStore();

        void drawPlaneStore(Config *config, PlaneList *planeList);
        void drawBuyingConfirmation();
        void updateEvent(Event *event, Vector2f *worldPos);
        void update(PlaneList *planeList, Money *money, Hangar *hangar, GUI_Hangar *gui_Hangar);
        bool isStoreDraw();

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            if(activate)
            {
                target.draw(scrollArea, states);
                if(buyingConfirmation)
                {
                    target.draw(backgroundBuyingConfirmation, states);
                    target.draw(textBuyingConfirmation, states);
                    target.draw(buttonBuyYes, states);
                    target.draw(buttonBuyNo, states);
                    target.draw(textBuyingPlaneName, states);
                    target.draw(textBuyingPrice, states);
                }

                for(int i = 0; i < planeQuantity; i++)
                {
                    target.draw(*buttonBuy[i], states);
                }
            }
        }

        int planeQuantity = PLANEQUANTITY;

        bool activate = false;
        bool storeDraw = false;
        bool buyingConfirmation = false;

        Font font;

        Button buttonQuit;

        RectangleShape backgroundStore;

        RectangleShape *planeView[PLANEQUANTITY];
        RectangleShape *lineUnderName[PLANEQUANTITY];

        Button *buttonBuy[PLANEQUANTITY];


        RectangleShape backgroundBuyingConfirmation;
        Text textBuyingConfirmation;
        Text textBuyingPlaneName;
        Text textBuyingPrice;
        FloatRect gbTextBuyingConfirmation;
        FloatRect gbTextBuyingPlaneName;
        FloatRect gbTextBuyingPrice;
        Button buttonBuyYes;
        Button buttonBuyNo;

        ScrollableArea scrollArea;
        TextArea textAreaPlane[PLANEQUANTITY];

        Text textPlaneName[PLANEQUANTITY];
        FloatRect gbTextPlaneName[PLANEQUANTITY];

        stringstream ssSpeed;
        stringstream ssPassengers;
        stringstream ssReleaseDate;
        stringstream ssRadius;
        stringstream ssPrice;
        stringstream ssPlaneID;
        stringstream ssPriceBuyingPlane;

        int first, second, third;
        int planeID = 0;
        //int n = 0;

        bool buttonBuyIsClicked = false;
        bool buttonBuyYesIsClicked = false;
        bool buttonBuyNoIsClicked = false;
        int id = 0;

        Config config;
        int width, height;
};

#endif // GUI_PLANESTORE_H
