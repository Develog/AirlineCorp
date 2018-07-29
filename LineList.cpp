#include "LineList.h"

LineList::LineList()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    width = config.getSetting(2);
    height = config.getSetting(3);
}

LineList::~LineList()
{
    //dtor
}

void LineList::createNewLine()
{
    vecLine.push_back(line);
}

//USELESS
void LineList::updateMoney(Money *money, ClockTime *clockTime)
{
    clockTime->getSecondIG();
    if(vecLine.size() > 0)
    {
        for(int i = 0; i < vecLine.size(); i++)
        {
            vecLine[i].autoTicketPrice();

            if(vecLine[i].getPlaneQuantity() > 0)
            {
                if(clockTime->getHourIG() == vecLine[i].getScheduleHour() && clockTime->getMinuteIG() == vecLine[i].getScheduleMinute() && _actualTime != clockTime->getMinuteIG())
                {
                    cout << "line price : " << vecLine[i].getTicketPrice() << endl;
                    money->setMoney(money->getMoney() + vecLine[i].getTicketPrice() * vecLine[i].getPlaneCapacity());
                }
            }
        }
        _actualTime = clockTime->getMinuteIG();
    }
}
/*
void LineList::drawLineCreator(GUI_Line *guiLine)
{
    guiLine->drawLineCreator(width, height);
}
*/
void LineList::drawLineGUI() //Classe pour créer les views de chaque ligne
{
    //guiLine.drawLineView(this);

    /*vecGuiLine.push_back(guiLine);
    vecGuiLine[vecGuiLine.size() - 1].drawLineView(&vecLine[vecLine.size() - 1], this->getLineQuantity("National"), this->getLineQuantity("International"), width, &font);*/
}

int LineList::getLineQuantity(string category)
{
    if(category == "International")
    {
        return _lineQuantityInternational;
    }
    else if(category == "National")
    {
        return _lineQuantityNational;
    }
    else
    {
        return _lineQuantityInternational + _lineQuantityNational;
    }
}
int LineList::getLineQuantity()
{
    //cout << "size : " << vecLine.size();
    return vecLine.size();
}

Line* LineList::getLine(int idLine)
{
    return &vecLine[idLine];
}
