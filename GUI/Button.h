#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Button : public Drawable
{
    public:
        Button(int width, int height, int posX, int posY, int r, int g, int b, bool shadow, std::string text);
        Button();

        void setSize(int width, int height);
        void setPosition(int posX, int posY);
        Vector2f getPosition();
        void setColor(int red, int green, int blue);
        void setColor(Color color);
        void setText(string text, int characterSize);
        void setShadow(bool activate);
        void setSprite(string filepath);
        void setFont(string filepath);

        int getWidth();
        int getHeight();
        string getText();

        bool isClicked(Event *event, Vector2f *worldPos);
        bool isReleased(Event *event, Vector2f *worldPos);
        bool isHoover(Vector2f *worldPos);

    private:

        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(button_shadow, states);
            target.draw(button, states);
            target.draw(button_text, states);
        }

        int m_width = 0;
        int m_height = 0;
        int m_posX = 0;
        int m_posY = 0;
        int m_red = 0;
        int m_green = 0;
        int m_blue = 0;
        string m_text = "";
        bool m_activate = false;

        Vector2f _position;

        sf::RectangleShape button;
        sf::RectangleShape button_shadow;

        sf::Text button_text;

        sf::FloatRect text_GB;
        sf::FloatRect button_GB;

        sf::Font font;

        sf::Texture button_spr_texture;
};

#endif // BUTTON_H
