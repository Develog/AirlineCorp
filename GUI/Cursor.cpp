#include "Cursor.h"

Cursor::Cursor()
{
    //ctor
}

Cursor::~Cursor()
{
    //dtor
}

void Cursor::setSizeBackground(Vector2f sizeBackground)
{
    _sizeBackground = sizeBackground;
    rectBackground.setSize(_sizeBackground);
}
Vector2f Cursor::getSizeBackground()
{
    return _sizeBackground;
}

void Cursor::setSizeCursor(Vector2f sizeCursor)
{
    _sizeCursor = sizeCursor;
    rectCursor.setSize(_sizeCursor);
    rectCursor.setFillColor(Color::White);
    rectCursor.setPosition(_positionBackground);
}

void Cursor::setPositionBackground(Vector2f positionBackground)
{
    _positionBackground = positionBackground;
    rectBackground.setPosition(_positionBackground);
    rectBackground.setFillColor(Color(40, 130, 40));
    rectBackground.setOutlineThickness(2);
    rectBackground.setOutlineColor(Color::Black);
}

void Cursor::setPositionCursor(Vector2f positionCursor)
{
    _positionCursor = positionCursor;
}
