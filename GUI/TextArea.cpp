#include "TextArea.h"

TextArea::TextArea()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
    {
        cout << "Error font loading" << endl;
    }
}

TextArea::~TextArea()
{
    //dtor
}

void TextArea::setSize(Vector2f size)
{
    _size = size;
    rectArea.setSize(_size);
}
Vector2f TextArea::getSize()
{
    return _size;
}

void TextArea::setPosition(Vector2f position)
{
    _position = position;
    rectArea.setPosition(_position);
    for(int i = 0; i < vecText.size(); i++)
    {
        vecText[i].setPosition(Vector2f(vecPositionText[i].x + rectArea.getPosition().x, vecPositionText[i].y + rectArea.getPosition().y));
    }
    for(int i = 0; i < vecShape.size(); i++)
    {
        vecShape[i].setPosition(Vector2f(vecPositionShape[i].x + rectArea.getPosition().x, vecPositionShape[i].y + rectArea.getPosition().y));
    }
    for(int i = 0; i < vecSprite.size(); i++)
    {
        vecSprite[i].setPosition(Vector2f(vecPositionSprite[i].x + rectArea.getPosition().x, vecPositionSprite[i].y + rectArea.getPosition().y));
    }
    for(int i = 0; i < vecButton.size(); i++)
    {
        vecButton[i].setPosition(vecPositionButton[i].x + rectArea.getPosition().x, vecPositionButton[i].y + rectArea.getPosition().y);
    }

    gbArea = rectArea.getGlobalBounds();
}
Vector2f TextArea::getPosition()
{
    return _position;
}

void TextArea::setColor(Color color)
{
    rectArea.setFillColor(color);
}

void TextArea::setOutline(int outlineThickness, Color color)
{
    rectArea.setOutlineThickness(outlineThickness);
    rectArea.setOutlineColor(color);
}

void TextArea::addText(Vector2f position, string text, int characterSize)
{
    vecPositionText.push_back(positionText);
    vecPositionText[vecPositionText.size() - 1] = position;
    vecText.push_back(text1);
    vecText[vecText.size() - 1].setFont(font);
    vecText[vecText.size() - 1].setCharacterSize(characterSize);
    vecText[vecText.size() - 1].setPosition(Vector2f(vecPositionText[vecText.size() - 1].x + rectArea.getPosition().x, vecPositionText[vecText.size() - 1].y + rectArea.getPosition().y));
    vecText[vecText.size() - 1].setString(text);
    vecText[vecText.size() - 1].setColor(Color::Black);
}

void TextArea::addText(Vector2f position, string text, int characterSize, Uint32 style)
{
    vecPositionText.push_back(positionText);
    vecPositionText[vecPositionText.size() - 1] = position;
    vecText.push_back(text1);
    vecText[vecText.size() - 1].setFont(font);
    vecText[vecText.size() - 1].setCharacterSize(characterSize);
    vecText[vecText.size() - 1].setPosition(Vector2f(vecPositionText[vecText.size() - 1].x + rectArea.getPosition().x, vecPositionText[vecText.size() - 1].y + rectArea.getPosition().y));
    vecText[vecText.size() - 1].setString(text);
    vecText[vecText.size() - 1].setStyle(style);
}

void TextArea::addText(Vector2f position, string positionOnTextArea, string text, int characterSize, Uint32 style)
{
    vecPositionText.push_back(positionText);

    vecText.push_back(text1);
    vecText[vecText.size() - 1].setFont(font);
    vecText[vecText.size() - 1].setCharacterSize(characterSize);
    vecText[vecText.size() - 1].setString(text);
    vecText[vecText.size() - 1].setStyle(style);

    if(positionOnTextArea == "Center")
    {
        vecGBText.push_back(GBText);
        vecGBText[vecGBText.size() - 1] = vecText[vecText.size() - 1].getGlobalBounds();
        vecText[vecText.size() - 1].setPosition(Vector2f(rectArea.getPosition().x + rectArea.getSize().x / 2 - (vecGBText[vecGBText.size() - 1].width / 2), vecPositionText[vecText.size() - 1].y + rectArea.getPosition().y));
        vecPositionText[vecPositionText.size() - 1] = vecText[vecText.size() - 1].getPosition();
    }
}

void TextArea::addEditableText(Vector2f position, string text, int characterSize)
{
    vecPositionText.push_back(positionText);
    vecPositionText[vecPositionText.size() - 1] = position;

    vecText.push_back(text1);
    vecText[vecText.size() - 1].setFont(font);
    vecText[vecText.size() - 1].setCharacterSize(characterSize);
    vecText[vecText.size() - 1].setPosition(Vector2f(vecPositionText[vecText.size() - 1].x + rectArea.getPosition().x, vecPositionText[vecText.size() - 1].y + rectArea.getPosition().y));
    vecText[vecText.size() - 1].setString(text);

    vecIdEditableText.push_back(idEditableText);
    vecIdEditableText[vecIdEditableText.size() - 1] = vecText.size() - 1;
}

void TextArea::setTextEditableText(int id, string text)
{
    vecText[vecIdEditableText[id]].setString(text);
}

string TextArea::getTextValue(int id)
{
    return vecText[vecIdEditableText[id]].getString();
}

void TextArea::addShape(Vector2f position, Vector2f size, Color color)
{
    vecPositionShape.push_back(positionShape);
    vecPositionShape[vecPositionShape.size() - 1] = position;
    vecShape.push_back(shape1);
    vecShape[vecShape.size() - 1].setSize(size);
    vecShape[vecShape.size() - 1].setPosition(Vector2f(rectArea.getPosition().x + position.x, rectArea.getPosition().y + position.y));
    vecShape[vecShape.size() - 1].setFillColor(color);
}

void TextArea::setShapePosition(int idShape, Vector2f position)
{
    vecShape[idShape].setPosition(rectArea.getPosition().x + position.x, rectArea.getPosition().y + position.y);
    vecPositionShape[idShape] = position;
}

void TextArea::setShapeSize(int idShape, Vector2f size)
{
    vecShape[idShape].setSize(size);
}

void TextArea::setShapeColor(int idShape, Color color)
{
    vecShape[idShape].setFillColor(color);
}

void TextArea::addSprite(Vector2f position, Vector2f size, string spritePath)
{
    vecPositionSprite.push_back(positionSprite);
    vecPositionSprite[vecPositionSprite.size() - 1] = position;
    vecTexture.push_back(texture1);
    vecSprite.push_back(sprite1);
    vecTexture[vecTexture.size() - 1].loadFromFile(spritePath);
    vecSprite[vecSprite.size() - 1].setTexture(&vecTexture[vecTexture.size() - 1]);
    vecSprite[vecSprite.size() - 1].setSize(size);
    vecSprite[vecSprite.size() - 1].setPosition(rectArea.getPosition().x + position.x, rectArea.getPosition().y + position.y);
}

void TextArea::addButton(Vector2f position, Vector2f size, Color color, string text)
{
    vecPositionButton.push_back(positionButton);
    vecPositionButton[vecPositionButton.size() - 1] = position;
    vecButton.push_back(button1);
    vecButton[vecButton.size() - 1].setSize(size.x, size.y);
    vecButton[vecButton.size() - 1].setColor(color);
    vecButton[vecButton.size() - 1].setPosition(rectArea.getPosition().x + position.x, rectArea.getPosition().y + position.y);
    vecButton[vecButton.size() - 1].setText(text, 20);
}

void TextArea::updateEvent(Event *event, Vector2f *worldPos)
{
    for(int i = 0; i < vecButton.size(); i++)
    {
        if(vecButton[i].isClicked(event, worldPos))
        {
            idButton = i;
            //cout << idButton << endl;
        }
    }
}

bool TextArea::buttonIsClicked(Event *event, Vector2f *worldPos)
{
    for(int i = 0; i < vecButton.size(); i++)
    {
        if(vecButton[i].isClicked(event, worldPos))
        {
            return true;
        }
    }
}

bool TextArea::buttonIsClicked(Event *event, Vector2f *worldPos, int id)
{
    if(vecButton[id].isClicked(event, worldPos))
    {
        return true;
    }
}

int TextArea::whichButtonIsClicked()
{
    return idButton;
}

bool TextArea::isClicked(Event *event, Vector2f *worldPos)
{
    if((event->type == sf::Event::MouseButtonPressed) && (event->mouseButton.button == sf::Mouse::Left) && (gbArea.contains(worldPos->x, worldPos->y)))
        return true;
    else
        return false;
}
