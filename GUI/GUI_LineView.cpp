#include "GUI_LineView.h"

GUI_LineView::GUI_LineView()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    width = config.getSetting(2);
    height = config.getSetting(3);
}

GUI_LineView::~GUI_LineView()
{
    //dtor
}

void GUI_LineView::createNewLineView(LineList *lineList)
{
    //cout << "size : " << lineList->getLineQuantity() << endl;
    vecBackgroundView.push_back(backgroundView);
    vecBackgroundView[vecBackgroundView.size() - 1].setFillColor(Color(100, 100, 100));
    vecBackgroundView[vecBackgroundView.size() - 1].setSize(Vector2f(width / 2 - 20, 100));
    vecBackgroundView[vecBackgroundView.size() - 1].setOutlineThickness(2);
    vecBackgroundView[vecBackgroundView.size() - 1].setOutlineColor(Color::Black);


    if(lineList->getLine(vecBackgroundView.size() - 1)->getCategory() == "International")
    {
        idLineInternational += 1;
        vecBackgroundView[vecBackgroundView.size() - 1].setPosition(Vector2f(10, 250 + idLineInternational * 110));
    }
    else if(lineList->getLine(vecBackgroundView.size() - 1)->getCategory() == "National")
    {
        idLineNational += 1;
        vecBackgroundView[vecBackgroundView.size() - 1].setPosition(Vector2f(width / 2 + 10, 250 + idLineNational * 110));
    }

    ssDistance << lineList->getLine(vecBackgroundView.size() - 1)->getDistance();

    vecTextOriginDestination.push_back(textData);
    vecTextOriginDestination[vecTextOriginDestination.size() - 1].setFont(font);
    vecTextOriginDestination[vecTextOriginDestination.size() - 1].setCharacterSize(30);
    vecTextOriginDestination[vecTextOriginDestination.size() - 1].setString(lineList->getLine(vecBackgroundView.size() - 1)->getOrigin() + " <-> " + lineList->getLine(vecBackgroundView.size() - 1)->getDestination() + "   " + ssDistance.str() + " km");
    vecTextOriginDestination[vecTextOriginDestination.size() - 1].setPosition(vecBackgroundView[vecBackgroundView.size() - 1].getPosition().x + 10, vecBackgroundView[vecBackgroundView.size() - 1].getPosition().y + 5);

    ssPlaneQuantity << lineList->getLine(vecBackgroundView.size() - 1)->getPlaneQuantity();

    vecTextPlaneQuantity.push_back(textData);
    vecTextPlaneQuantity[vecTextPlaneQuantity.size() - 1].setFont(font);
    vecTextPlaneQuantity[vecTextPlaneQuantity.size() - 1].setCharacterSize(30);
    vecTextPlaneQuantity[vecTextPlaneQuantity.size() - 1].setPosition(vecBackgroundView[vecBackgroundView.size() - 1].getPosition().x + 10, vecBackgroundView[vecBackgroundView.size() - 1].getPosition().y + 50);
    vecTextPlaneQuantity[vecTextPlaneQuantity.size() - 1].setString("0 flight(s) on this line");

    ssDistance.str("");
    ssPlaneQuantity.str("");
}

void GUI_LineView::update(LineList *lineList)
{
    for(int i = 0; i < vecTextPlaneQuantity.size(); i++)
    {
        //SHOW THE NUMBER OF FLIGHT AND NOT THE NUMBER OF PLANE ON THE LINE
        ssPlaneQuantity.str("");
        ssPlaneQuantity << lineList->getLine(i)->getPlaneQuantity();
        vecTextPlaneQuantity[i].setString(ssPlaneQuantity.str() + " flight(s) on this line");
    }
}
