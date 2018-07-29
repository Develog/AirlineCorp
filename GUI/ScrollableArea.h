#ifndef SCROLLABLEAREA_H
#define SCROLLABLEAREA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUI/Button.h"
#include "GUI/TextArea.h"
#include "Config.h"

using namespace std;
using namespace sf;

class ScrollableArea : public Drawable
{
    public:
        ScrollableArea();
        ~ScrollableArea();

        void setSize(Vector2f size);
        Vector2f getSize();

        void setScrollBarSize(Vector2f scrollBarSize);
        Vector2f getScrollBarSize();

        void setPosition(Vector2f position);
        Vector2f getPosition();

        void setColor(Color color);

        void setBackgroundColor(Color color);

        void activateOutline(bool activateOutline);

        void addTextArea(TextArea *textArea);

        void update();

        void updateEvent(Event *event, Vector2f *worldPos);

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {

            target.draw(rectArea, states);
            target.draw(rectScrollBar, states);
            target.draw(rectScrollingBar, states);
            //target.draw(buttonScrollUp, states);
            //target.draw(buttonScrollDown, states);
            if(drawing && !firstTime)
            {

                for(unsigned int i = 0; i < vecTextArea.size(); i++)
                {
                    target.draw(*vecTextArea[i], states);
                }
            }
            target.draw(rectLeft, states);
            target.draw(rectRight, states);
            target.draw(rectTop, states);
            target.draw(rectLeft, states);
            target.draw(rectBottom, states);
            if(_activateOutline)
            {
                target.draw(rectOutline, states);
            }
        }

        RectangleShape rectOutline;

        RectangleShape rectLeft;
        RectangleShape rectRight;
        RectangleShape rectTop;
        RectangleShape rectBottom;

        RectangleShape rectArea;
        RectangleShape rectScrollBar;
        RectangleShape rectScrollingBar;

        Button buttonScrollUp;
        Button buttonScrollDown;

        Texture texScrollBar;

        Vector2f _position, _size, _scrollBarSize;

        bool scrollUp = false, scrollDown = false;
        bool firstTime = true;
        bool drawing = true;

        TextArea *textArea1;
        vector <TextArea*> vecTextArea;

        int width, height;
        int totalSizeOfTextArea, sizeOfScrollingBar;

        FloatRect gbRectScrollingBar;
        bool scrollingBarIsClicked;
        int mousePosition;
        int mouseDelta;
        int firstTextAreaPosition, lastTextAreaPosition;

        bool _activateOutline = true;

        Config config;
};

#endif // SCROLLABLEAREA_H

