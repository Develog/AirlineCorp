#ifndef GUI_LINEVIEW_H
#define GUI_LINEVIEW_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Config.h"
#include "LineList.h"

using namespace std;
using namespace sf;

class GUI_LineView : public Drawable
{
    public:
        GUI_LineView();
        ~GUI_LineView();

        void createNewLineView(LineList *lineList);
        void update(LineList *lineList);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            for(int i = 0; i < vecBackgroundView.size(); i++)
            {
                target.draw(vecBackgroundView[i], states);
                target.draw(vecTextOriginDestination[i], states);
                target.draw(vecTextPlaneQuantity[i], states);
            }
        }

        Config config;

        Font font;

        RectangleShape backgroundView;
        vector <RectangleShape> vecBackgroundView;

        Text textData;
        vector <Text> vecTextPlaneQuantity;
        vector <Text> vecTextOriginDestination;


        int width, height;
        int idLineInternational, idLineNational;

        stringstream ssDistance;
        stringstream ssPlaneQuantity;
};

#endif // GUI_LINEVIEW_H
