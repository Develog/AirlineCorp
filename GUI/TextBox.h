#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
using namespace sf;

class TextBox : public Drawable
{
    public:
        TextBox(Vector2f size, Vector2f position, string value);
        TextBox();

        void setSize(Vector2f size);
        void setPosition(Vector2f position);
        void setValue(string value);
        void Reset();
        void setFontSize(int size);

        Vector2f getSize();
        Vector2f getPosition();

        string getValue();
        int getIntValue();

        void getKeyboardValue(Event *event, Vector2f *worldPos);
    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(rectTextBox, states);
            target.draw(textTextBox, states);
        }

        string _value = "";
        Vector2f _position, _size;

        bool firstTime = true;
        bool firstCharacter = true;

        int move = 0;
        int lastVerticalPositionText = 0;
        char number[30] = {' '};

        bool activate = false;

        RectangleShape rectTextBox;

        Text textTextBox;

        Font font;

        FloatRect gbText;
        FloatRect gbBox;
};

#endif // TEXTBOX_H

