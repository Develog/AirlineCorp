#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Cursor : public Drawable
{
    public:
        Cursor();
        ~Cursor();

        void setSizeBackground(Vector2f sizeBackground);
        Vector2f getSizeBackground();

        void setSizeCursor(Vector2f sizeCursor);
        void setPositionBackground(Vector2f positionBackground);
        void setPositionCursor(Vector2f positionCursor);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(rectBackground, states);
            target.draw(rectCursor, states);
        }

        RectangleShape rectBackground;
        RectangleShape rectCursor;

        Vector2f _sizeBackground, _sizeCursor, _positionBackground, _positionCursor;

};

#endif // CURSOR_H
