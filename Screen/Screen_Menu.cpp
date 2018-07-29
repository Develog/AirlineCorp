#include "Screen_Menu.h"

Screen_Menu::Screen_Menu()
{
    width = config.getSetting(2);
    height = config.getSetting(3);

    if(!texBackground.loadFromFile("Resource/backgroundMenu2.png"))
    {
        cout << "error background" << endl;
    }

    background.setTexture(texBackground);

    buttonPlay.setSize(400, 220);
    space = (height - (buttonPlay.getHeight() * 3)) / 4;
    buttonPlay.setPosition(width / 2 - buttonPlay.getWidth() / 2, space);
    buttonPlay.setColor(130, 130, 130);
    buttonPlay.setSprite("Resource/PlaneButton.png");
    buttonPlay.setText("Play", 30);

    buttonSettings.setSize(400, 220);
    buttonSettings.setPosition(width / 2 - buttonPlay.getWidth() / 2, buttonPlay.getHeight() + space * 2);
    buttonSettings.setColor(130, 130, 130);
    buttonSettings.setSprite("Resource/PlaneButton.png");
    buttonSettings.setText("Settings", 30);

    buttonQuit.setSize(400, 220);
    buttonQuit.setPosition(width / 2 - buttonPlay.getWidth() / 2, buttonPlay.getHeight() * 2 + space *  3);
    buttonQuit.setColor(130, 130, 130);
    buttonQuit.setSprite("Resource/PlaneButton.png");
    buttonQuit.setText("Quit", 30);
}

Screen_Menu::~Screen_Menu()
{

}

bool Screen_Menu::buttonPlayIsClicked(Event *event, Vector2f *worldPos)
{
    if(buttonPlay.isClicked(event, worldPos))
        return true;
    else
        return false;
}

void Screen_Menu::buttonQuitIsClicked(Event *event, Vector2f *worldPos, RenderWindow *window)
{
    if(buttonQuit.isClicked(event, worldPos))
    {
        window->close();
    }
}
