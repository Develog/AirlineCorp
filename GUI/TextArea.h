#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Button.h"

using namespace std;
using namespace sf;

class TextArea : public Drawable
{
    public:
        TextArea();
        ~TextArea();

        void setSize(Vector2f size);
        Vector2f getSize();

        void setPosition(Vector2f position);
        Vector2f getPosition();

        void setColor(Color color);

        void setOutline(int outlineThickness, Color color);

        void addText(Vector2f position, string text, int characterSize);
        void addText(Vector2f position, string text, int characterSize, Uint32 style);
        void addText(Vector2f position, string positionOnTextArea, string text, int characterSize, Uint32 style);

        void addEditableText(Vector2f position, string text, int characterSize);
        void setTextEditableText(int id, string text);
        string getTextValue(int id);

        void addShape(Vector2f position, Vector2f size, Color color);
        void setShapePosition(int idShape, Vector2f position);
        void setShapeSize(int idShape, Vector2f size);
        void setShapeColor(int idShape, Color color);

        void addSprite(Vector2f position, Vector2f size, string spritePath);

        void addButton(Vector2f position, Vector2f size, Color color, string text);

        bool isClicked(Event *event, Vector2f *worldPos);

        bool buttonIsClicked(Event *event, Vector2f *worldPos);
        bool buttonIsClicked(Event *event, Vector2f *worldPos, int id);
        void updateEvent(Event *event, Vector2f *worldPos);
        int whichButtonIsClicked();

    private:
        virtual void draw(RenderTarget& target, RenderStates states) const
        {
            target.draw(rectArea, states);
            for(unsigned int i = 0; i < vecText.size(); i++)
            {
                target.draw(vecText[i], states);
            }
            for(unsigned int i = 0; i < vecShape.size(); i++)
            {
                target.draw(vecShape[i], states);
            }
            for(unsigned int i = 0; i < vecSprite.size(); i++)
            {
                target.draw(vecSprite[i], states);
            }
            for(unsigned int i = 0; i < vecButton.size(); i++)
            {
                target.draw(vecButton[i], states);
            }
        }

        Font font;

        Text text1;
        vector <Text> vecText;

        Vector2f positionText;
        vector<Vector2f> vecPositionText;

        FloatRect GBText;
        vector<FloatRect> vecGBText;

        int idEditableText;
        vector<int> vecIdEditableText;

        RectangleShape shape1;
        vector <RectangleShape> vecShape;

        Vector2f positionShape;
        vector <Vector2f> vecPositionShape;

        Texture texture1;
        vector <Texture> vecTexture;

        RectangleShape sprite1;
        vector <RectangleShape> vecSprite;

        Vector2f positionSprite;
        vector <Vector2f> vecPositionSprite;

        Button button1;
        vector <Button> vecButton;

        Vector2f positionButton;
        vector <Vector2f> vecPositionButton;

        RectangleShape rectArea;

        Vector2f _size, _position;

        FloatRect gbArea;

        int idButton = 0;
};

#endif // TEXTAREA_H
