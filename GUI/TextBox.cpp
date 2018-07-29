#include "TextBox.h"

TextBox::TextBox(Vector2f size, Vector2f position, string value)
{
    _size = size;
    _position = position;
    _value = value;

    gbBox = rectTextBox.getGlobalBounds();

    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    rectTextBox.setSize(_size);
    rectTextBox.setPosition(_position);
    rectTextBox.setFillColor(Color::White);
    rectTextBox.setOutlineThickness(4);
    rectTextBox.setOutlineColor(Color::Black);

    textTextBox.setCharacterSize(_size.y - 10);
    textTextBox.setColor(Color::Black);
    gbText = textTextBox.getGlobalBounds();
    textTextBox.setPosition(_position.x + ((_size.x - gbText.width)/ 2) , _position.y + (_size.y + (rectTextBox.getOutlineThickness() * 2) - gbText.height * 2));
    textTextBox.setFont(font);
    textTextBox.setString(value);
}

TextBox::TextBox()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    rectTextBox.setFillColor(Color::White);
    rectTextBox.setOutlineThickness(4);
    rectTextBox.setOutlineColor(Color::Black);

    textTextBox.setCharacterSize(10);
    textTextBox.setColor(Color::Black);
    textTextBox.setFont(font);

    //this->setValue("");
}

void TextBox::setSize(Vector2f size)
{
    _size = size;
    rectTextBox.setSize(_size);
    textTextBox.setCharacterSize(_size.y - 20);
    gbBox = rectTextBox.getGlobalBounds();
    gbText = textTextBox.getGlobalBounds();
    textTextBox.setPosition(_position.x + ((_size.x - gbText.width)/ 2) , _position.y + ((_size.y / 2 - gbText.height)/ 2) + 4);
}
Vector2f TextBox::getSize()
{
    return _size;
}

void TextBox::setPosition(Vector2f position)
{
    _position = position;
    rectTextBox.setPosition(_position);
    gbText = textTextBox.getGlobalBounds();
    textTextBox.setPosition(_position.x + ((_size.x - gbText.width)/ 2) , _position.y + ((_size.y / 2 - gbText.height)/ 2) + 4);
    gbBox = rectTextBox.getGlobalBounds();
}
Vector2f TextBox::getPosition()
{
    return _position;
}

void TextBox::setValue(string value)
{
    _value = value;
    textTextBox.setString(_value);

    gbText = textTextBox.getGlobalBounds();
    if(firstCharacter)
    {
        lastVerticalPositionText = gbText.height;
        firstCharacter = false;
    }

    textTextBox.setPosition(_position.x + ((_size.x - gbText.width)/ 2) , _position.y + ((_size.y / 2 - lastVerticalPositionText)/ 2) + 4);
}

void TextBox::Reset()
{
    for(int i = 0; i < 31; i++)
    {
        number[i] = NULL;
        move = 0;

    }
    //this->setValue("");
}

void TextBox::setFontSize(int size)
{
    textTextBox.setCharacterSize(size);
}

string TextBox::getValue()
{
    return _value;
}

int TextBox::getIntValue()
{
    int val = atoi(_value.c_str());
    return val;
}

void TextBox::getKeyboardValue(Event *event, Vector2f *worldPos)
{
    if(activate)
    {
        rectTextBox.setFillColor(Color(200, 200, 200));
        if(firstTime)
        {
            this->setValue("");
            firstTime = false;
        }

        if ((event->type == Event::TextEntered) && !(Keyboard::isKeyPressed(Keyboard::BackSpace)) && !(Keyboard::isKeyPressed(Keyboard::Return)) && !(Keyboard::isKeyPressed(Keyboard::Tab)))
        {
            if (event->text.unicode < 128)
            {
                if(move > 30)
                {
                    move = 0;
                    for(int i = 0; i < 31; i++)
                        number[i] = ' ';
                }
                number[move] = static_cast<char>(event->text.unicode);
                this->setValue(number);
                move += 1;
            }
        }
        if((event->type == Event::KeyPressed) && (event->key.code == Keyboard::BackSpace))
        {
            move -= 1;
            if(move < 0)
                move = 0;
            number[move] = NULL;
            this->setValue(number);
        }
    }
    else
    {
        rectTextBox.setFillColor(Color(255, 255, 255));
    }
    if((event->type == Event::MouseButtonPressed) && (event->mouseButton.button == Mouse::Left))
    {
        if (gbBox.contains(worldPos->x, worldPos->y))
        {
            if (activate == false)
            {
                activate = true;
            }
            else
            {
                activate = false;
            }
        }
        else
        {
            activate = false;
            rectTextBox.setFillColor(Color::White);
        }
    }
}
