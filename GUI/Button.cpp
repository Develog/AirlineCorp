#include "Button.h"

Button::Button(int width, int height, int posX, int posY, int r, int g, int b, bool shadow, std::string text)
{
    if (!font.loadFromFile("Resources/Arial.ttf"))
    {
        std::cout << "erreur font" << std::endl;
    }
    button_text.setFont(font);

    button.setSize(sf::Vector2f(width, height));
    button.setPosition(posX, posY);
    button.setFillColor(sf::Color(r,g,b));

    button_GB = button.getGlobalBounds();

    button_text.setCharacterSize(100);
    button_text.setString(text);
    button_text.setColor(sf::Color::White);

    text_GB = button_text.getGlobalBounds();
    button_text.setPosition(posX + ((width - text_GB.width)/ 2) , posY + ((height - text_GB.height)/ 2 - (text_GB.height / 2)));

    if (shadow == true)
    {
        button_shadow.setSize(sf::Vector2f(width, height));
        button_shadow.setPosition(posX + 2, posY + 2);
        button_shadow.setFillColor(sf::Color(r,g,b-80));
    }
}

Button::Button()
{
    if (!font.loadFromFile("Resource/Arial.ttf"))
    {
        std::cout << "Font Error. Can't find basic font" << std::endl;
    }
    button_text.setFont(font);
}

void Button::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
    button.setSize(sf::Vector2f(width, height));
    button_GB = button.getGlobalBounds();
}

void Button::setPosition(int posX, int posY)
{
    _position.x = posX;
    _position.y = posY;
    m_posX = posX;
    m_posY = posY;
    button.setPosition(posX, posY);
    button_GB = button.getGlobalBounds();
    button_text.setPosition(_position.x + ((m_width - text_GB.width)/ 2) , _position.y + m_height / 2 - text_GB.height/ 2);
}
Vector2f Button::getPosition()
{
    return _position;
}

void Button::setColor(int red, int green, int blue)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
    button.setFillColor(sf::Color(red,green,blue));
}

void Button::setColor(Color color)
{
    button.setFillColor(color);
}

void Button::setText(string text, int characterSize)
{
    button_text.setString("");
    m_text = text;
    button_text.setCharacterSize(characterSize);
    button_text.setString(text);
    button_text.setColor(sf::Color::White);

    text_GB = button_text.getGlobalBounds();
    button_text.setPosition(_position.x + ((m_width - text_GB.width)/ 2) , _position.y + m_height / 2 - text_GB.height/ 2); //  m_posY + ((m_height - text_GB.height)/ 2 - (text_GB.height / 2))
}

string Button::getText()
{
    return m_text;
}

void Button::setShadow(bool activate)
{
    if (activate == true)
    {
        button_shadow.setSize(sf::Vector2f(m_width, m_height));
        button_shadow.setPosition(m_posX + 2, m_posY + 2);
        button_shadow.setFillColor(sf::Color(m_red, m_green, m_blue-80));
    }
}

void Button::setSprite(string filepath)
{
    if (!button_spr_texture.loadFromFile(filepath))
    {
        std::cout << "erreur texture button" << std::endl;
    }
    button.setTexture(&button_spr_texture);
}

void Button::setFont(string filepath)
{
    if(!font.loadFromFile(filepath))
        cout << "Font error" << endl;
}

bool Button::isClicked(sf::Event *event, sf::Vector2f *worldPos)
{
    if((event->type == sf::Event::MouseButtonPressed) && (event->mouseButton.button == sf::Mouse::Left) && (button_GB.contains(worldPos->x, worldPos->y)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Button::isHoover(Vector2f *worldPos)
{
    if(button_GB.contains(worldPos->x, worldPos->y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Button::getWidth()
{
    return m_width;
}

int Button::getHeight()
{
    return m_height;
}


