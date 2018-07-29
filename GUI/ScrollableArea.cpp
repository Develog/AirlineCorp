#include "ScrollableArea.h"

ScrollableArea::ScrollableArea()
{
    width = config.getSetting(2);
    height = config.getSetting(3);

    if(!texScrollBar.loadFromFile("Resource/scrollBar.png"))
        cout << "Error scrollbar texture" << endl;

    rectScrollBar.setFillColor(Color(160, 160, 160));
    rectScrollingBar.setFillColor(Color(120, 120, 120));

    rectOutline.setFillColor(Color(0, 0, 0, 0));
    rectOutline.setOutlineThickness(4);
    rectOutline.setOutlineColor(Color::Black);

    rectScrollBar.setTexture(&texScrollBar);
    rectScrollingBar.setTexture(&texScrollBar);

    buttonScrollUp.setSize(40, 40);
    buttonScrollUp.setSprite("Resource/scrollButton.png");

    buttonScrollDown.setSize(40, 40);
    buttonScrollDown.setSprite("Resource/scrollButtonDown.png");
}

ScrollableArea::~ScrollableArea()
{
    //dtor
}

void ScrollableArea::setSize(Vector2f size)
{
    _size = size;
    rectArea.setSize(_size);
    rectScrollBar.setSize(Vector2f(20, rectArea.getSize().y));
    _scrollBarSize = rectScrollBar.getSize();
    rectOutline.setSize(Vector2f(_size.x, _size.y));
}
Vector2f ScrollableArea::getSize()
{
    return _size;
}

void ScrollableArea::setScrollBarSize(Vector2f scrollBarSize)
{
    _scrollBarSize = scrollBarSize;

}
Vector2f ScrollableArea::getScrollBarSize()
{
    return _scrollBarSize;
}

void ScrollableArea::setPosition(Vector2f position)
{
    _position = position;
    rectArea.setPosition(_position);
    rectOutline.setPosition(Vector2f(_position.x, _position.y));
    rectScrollBar.setPosition(Vector2f(rectArea.getPosition().x + rectArea.getSize().x - rectScrollBar.getSize().x - 5, rectArea.getPosition().y));
    rectScrollingBar.setPosition(Vector2f(rectArea.getPosition().x + rectArea.getSize().x - rectScrollBar.getSize().x - 5, rectArea.getPosition().y));
    buttonScrollUp.setPosition(rectScrollBar.getPosition().x, rectScrollBar.getPosition().y);
    buttonScrollDown.setPosition(rectScrollBar.getPosition().x, rectScrollBar.getPosition().y + rectScrollBar.getSize().y - buttonScrollDown.getHeight());

    rectTop.setSize(Vector2f(rectArea.getSize().x, rectArea.getPosition().y));
    rectTop.setPosition(Vector2f(_position.x, 0));

    rectBottom.setSize(Vector2f(rectArea.getSize().x, rectArea.getPosition().y));
    rectBottom.setPosition(Vector2f(_position.x, rectArea.getPosition().y + rectArea.getSize().y));
}
Vector2f ScrollableArea::getPosition()
{
    return _position;
}

void ScrollableArea::setColor(Color color)
{
    rectArea.setFillColor(color);
}

void ScrollableArea::setBackgroundColor(Color color)
{
    rectTop.setFillColor(color);
    rectBottom.setFillColor(color);
}

void ScrollableArea::activateOutline(bool activateOutline)
{
    _activateOutline = activateOutline;
}

void ScrollableArea::addTextArea(TextArea *textArea)
{
    if(firstTime)
    {
        firstTime = false;
    }

    vecTextArea.push_back(textArea1);
    vecTextArea[vecTextArea.size() - 1] = textArea;
    totalSizeOfTextArea = (vecTextArea[vecTextArea.size() - 1]->getPosition().y + vecTextArea[vecTextArea.size() - 1]->getSize().y) - vecTextArea[0]->getPosition().y;
    sizeOfScrollingBar = (rectArea.getSize().y / totalSizeOfTextArea) * rectArea.getSize().y;
    rectScrollingBar.setSize(Vector2f(rectScrollBar.getSize().x, sizeOfScrollingBar));
    gbRectScrollingBar = rectScrollingBar.getGlobalBounds();
}

void ScrollableArea::update()
{
    if(vecTextArea.size() > 0)
    {
        if(scrollUp && (vecTextArea[vecTextArea.size() - 1]->getPosition().y + vecTextArea[vecTextArea.size() - 1]->getSize().y) >= (rectArea.getPosition().y + rectArea.getSize().y))
        {
            for(int i = 0; i < vecTextArea.size(); i++)
            {
                vecTextArea[i]->setPosition(Vector2f(vecTextArea[i]->getPosition().x, vecTextArea[i]->getPosition().y - 20));
                scrollUp = false;
            }
        }
        if(scrollDown && vecTextArea[0]->getPosition().y <= rectArea.getPosition().y)
        {
            for(int i = 0; i < vecTextArea.size(); i++)
            {
                vecTextArea[i]->setPosition(Vector2f(vecTextArea[i]->getPosition().x, vecTextArea[i]->getPosition().y + 20));
                scrollDown = false;
            }
        }
    }
    /*if(textArea1.getPosition().y < rectArea.getPosition().y - 140)
    {
        drawing = false;
    }
    else
    {
        drawing = true;
    }*/
}

void ScrollableArea::updateEvent(Event *event, Vector2f *worldPos)
{
    if (event->type == sf::Event::MouseWheelMoved)
    {
        if(event->mouseWheel.delta > 0)
        {
            scrollDown = true;
        }
        else
        {
            scrollUp = true;
        }
    }
    if((event->type == Event::MouseButtonPressed) && (event->mouseButton.button == Mouse::Left) && (gbRectScrollingBar.contains(worldPos->x, worldPos->y)))
    {
        scrollingBarIsClicked = true;
        mousePosition = worldPos->y;
    }
    else if((event->type == Event::MouseButtonReleased) && (event->mouseButton.button == Mouse::Left))
    {
        scrollingBarIsClicked = false;
        mouseDelta = 0;
    }

    if(scrollingBarIsClicked)
    {

        if(rectScrollingBar.getPosition().y >= rectScrollBar.getPosition().y && rectScrollingBar.getPosition().y + rectScrollingBar.getSize().y <= rectScrollBar.getPosition().y + rectScrollBar.getSize().y)
        {
            for(int i = 0; i < vecTextArea.size(); i++)
            {
                vecTextArea[i]->setPosition(Vector2f(vecTextArea[i]->getPosition().x, vecTextArea[i]->getPosition().y - (totalSizeOfTextArea / rectArea.getSize().y) * mouseDelta));
            }
            mouseDelta = worldPos->y - mousePosition;
            cout << "delta : " << mouseDelta << endl;
            rectScrollingBar.setPosition(Vector2f(rectScrollingBar.getPosition().x, rectScrollingBar.getPosition().y + mouseDelta));
            mousePosition = worldPos->y;
        }

        if(rectScrollingBar.getPosition().y < rectScrollBar.getPosition().y)
        {
            rectScrollingBar.setPosition(Vector2f(rectScrollingBar.getPosition().x, rectScrollBar.getPosition().y));
            mouseDelta = 0;
        }
        if(rectScrollingBar.getPosition().y + rectScrollingBar.getSize().y > rectScrollBar.getPosition().y + rectScrollBar.getSize().y)
        {
            rectScrollingBar.setPosition(Vector2f(rectScrollingBar.getPosition().x, rectScrollBar.getPosition().y + rectScrollBar.getSize().y - rectScrollingBar.getSize().y));
            mouseDelta = 0;
        }
    }

    if(buttonScrollUp.isClicked(event, worldPos))
    {
        scrollDown = true;
    }
    if(buttonScrollDown.isClicked(event, worldPos))
    {
        scrollUp = true;
    }
}
