#include "GUI_PlaneStore.h"

GUI_PlaneStore::GUI_PlaneStore()
{
    if(!font.loadFromFile("Resource/Arial.ttf"))
        cout << "Error font" << endl;

    for(int i = 0; i < planeQuantity; i++)
    {
        buttonBuy[i] = new Button();
    }

    width = config.getSetting(2);
    height = config.getSetting(3);


    ///Buying confirmation
    backgroundBuyingConfirmation.setSize(Vector2f(width / 4, height / 4));
    backgroundBuyingConfirmation.setPosition(Vector2f(width / 2 - backgroundBuyingConfirmation.getSize().x / 2, height / 2 - backgroundBuyingConfirmation.getSize().y / 2));
    backgroundBuyingConfirmation.setFillColor(Color(100, 100, 100));
    backgroundBuyingConfirmation.setOutlineColor(Color::Black);
    backgroundBuyingConfirmation.setOutlineThickness(2);

    textBuyingConfirmation.setFont(font);
    textBuyingConfirmation.setCharacterSize(20);
    textBuyingConfirmation.setString("Do you really want to buy this plane ?");
    gbTextBuyingConfirmation = textBuyingConfirmation.getGlobalBounds();
    textBuyingConfirmation.setPosition(Vector2f(backgroundBuyingConfirmation.getPosition().x + backgroundBuyingConfirmation.getSize().x / 2 - gbTextBuyingConfirmation.width / 2, backgroundBuyingConfirmation.getPosition().y + 20));

    textBuyingPlaneName.setFont(font);
    textBuyingPlaneName.setCharacterSize(20);

    textBuyingPrice.setFont(font);
    textBuyingPrice.setCharacterSize(20);

    buttonBuyYes.setSize(backgroundBuyingConfirmation.getSize().x / 4, backgroundBuyingConfirmation.getSize().y / 4);
    buttonBuyYes.setText("YES", 20);
    buttonBuyYes.setColor(Color::Black);
    buttonBuyYes.setPosition(backgroundBuyingConfirmation.getPosition().x + backgroundBuyingConfirmation.getSize().x / 4 - buttonBuyYes.getWidth() / 2, backgroundBuyingConfirmation.getPosition().y + backgroundBuyingConfirmation.getSize().y - (2 * buttonBuyYes.getWidth()) / 2.5);


    buttonBuyNo.setSize(backgroundBuyingConfirmation.getSize().x / 4, backgroundBuyingConfirmation.getSize().y / 4);
    buttonBuyNo.setText("NO", 20);
    buttonBuyNo.setColor(Color::Black);
    buttonBuyNo.setPosition(backgroundBuyingConfirmation.getPosition().x + backgroundBuyingConfirmation.getSize().x / 2 + buttonBuyNo.getWidth() / 2, backgroundBuyingConfirmation.getPosition().y + backgroundBuyingConfirmation.getSize().y - (2 * buttonBuyNo.getWidth()) / 2.5);

    scrollArea.setSize(Vector2f(width - 100, height - 350));
    scrollArea.setPosition(Vector2f(50, height / 2 - 220));
    scrollArea.setColor(Color::White);
    scrollArea.setBackgroundColor(Color(48, 48, 48));

    for(int i = 0; i < PLANEQUANTITY; i++)
    {
        textAreaPlane[i].setSize(Vector2f(scrollArea.getSize().x - 20 - scrollArea.getScrollBarSize().x, 150));
        textAreaPlane[i].setPosition(Vector2f(scrollArea.getPosition().x + 10, i * 160 + scrollArea.getPosition().y + 10));
        textAreaPlane[i].setColor(Color(200, 200, 200));
        textAreaPlane[i].setOutline(3, Color::Black);
        scrollArea.addTextArea(&textAreaPlane[i]);
    }
}

GUI_PlaneStore::~GUI_PlaneStore()
{
    //dtor
}


void GUI_PlaneStore::drawPlaneStore(Config *config, PlaneList *planeList)
{
    activate = true;
    storeDraw = true;

    for(int i = 0; i < planeQuantity; i++)
    {
        textPlaneName[i].setFont(font);
        textPlaneName[i].setCharacterSize(20);
        textPlaneName[i].setString(planeList->plane[i]->getPlaneName() + " - " + planeList->plane[i]->getManufactureName());
        gbTextPlaneName[i] = textPlaneName[i].getGlobalBounds();

        textAreaPlane[i].addText(Vector2f(textAreaPlane[i].getSize().x / 2 - gbTextPlaneName[i].width / 2 , 10), planeList->plane[i]->getPlaneName() + " - " + planeList->plane[i]->getManufactureName(), 20);
        textAreaPlane[i].addShape(Vector2f(0, 40), Vector2f(textAreaPlane[i].getSize().x, 3), Color::Black);
        textAreaPlane[i].addSprite(Vector2f(0, 43), Vector2f(350, 107), planeList->plane[i]->getFilePath());
        textAreaPlane[i].addText(Vector2f(400, 45), " - Category : " + planeList->plane[i]->getCategory(), 20);

        ssSpeed.str("");
        ssSpeed << planeList->plane[i]->getSpeed();
        textAreaPlane[i].addText(Vector2f(400, 70), " - Speed : " + ssSpeed.str() + " km/h", 20);

        ssPassengers.str("");
        ssPassengers << planeList->plane[i]->getSeatCapacity();
        textAreaPlane[i].addText(Vector2f(400, 95), " - Passengers : " + ssPassengers.str(), 20);

        textAreaPlane[i].addText(Vector2f(400, 120), " - Consumption : " + to_string(planeList->plane[i]->getConsumptionPer100KmPerPassenger()) + " L/100km/pax", 20);

        ssReleaseDate.str("");
        ssReleaseDate << planeList->plane[i]->getReleaseDate();
        textAreaPlane[i].addText(Vector2f(1000, 45), " - Release date : " + ssReleaseDate.str(), 20);

        textAreaPlane[i].addText(Vector2f(1000, 80), " - Radius : " + Function::NumberToSpaceNumber(planeList->plane[i]->getRadius()) + " km", 20);

        textAreaPlane[i].addText(Vector2f(1000, 115), " - Price : " + Function::NumberToSpaceNumber(planeList->plane[i]->getPrice()) + " euros", 20);

        textAreaPlane[i].addButton(Vector2f(1630, 44), Vector2f(130, 105), Color(100, 100, 100), "BUY");
    }
}

void GUI_PlaneStore::updateEvent(Event *event, Vector2f *worldPos)
{
    for(int i = 0; i < PLANEQUANTITY; i++)
    {
        if(textAreaPlane[i].buttonIsClicked(event, worldPos))
        {
            id = i;
            buttonBuyIsClicked = true;
        }
    }

    if(buttonBuyYes.isClicked(event, worldPos))
    {
        buttonBuyYesIsClicked = true;
    }
    if(buttonBuyNo.isClicked(event, worldPos))
    {
        buttonBuyNoIsClicked = true;
    }

    scrollArea.updateEvent(event, worldPos);
    scrollArea.update();
}

void GUI_PlaneStore::update(PlaneList *planeList, Money *money, Hangar *hangar, GUI_Hangar *gui_Hangar)
{
    if(buttonBuyIsClicked && money->getMoney() >= planeList->plane[id]->getPrice())
    {
        buyingConfirmation = true;

        textBuyingPlaneName.setString(planeList->plane[id]->getManufactureName() + " - " + planeList->plane[id]->getPlaneName());
        gbTextBuyingPlaneName = textBuyingPlaneName.getGlobalBounds();
        textBuyingPlaneName.setPosition(Vector2f(backgroundBuyingConfirmation.getPosition().x + backgroundBuyingConfirmation.getSize().x / 2 - gbTextBuyingPlaneName.width / 2, backgroundBuyingConfirmation.getPosition().y + backgroundBuyingConfirmation.getSize().y / 4));

        ssPriceBuyingPlane.str("");
        ssPriceBuyingPlane << planeList->plane[id]->getPrice();
        textBuyingPrice.setString(ssPriceBuyingPlane.str() + " Euros");
        gbTextBuyingPrice = textBuyingPrice.getGlobalBounds();
        textBuyingPrice.setPosition(Vector2f(backgroundBuyingConfirmation.getPosition().x + backgroundBuyingConfirmation.getSize().x / 2 - gbTextBuyingPrice.width / 2, backgroundBuyingConfirmation.getPosition().y + backgroundBuyingConfirmation.getSize().y / 2));
    }

    if(buttonBuyYesIsClicked)
    {
        hangar->newPlane(planeList, id, planeID);
        gui_Hangar->addPlane(hangar->getPlane(planeID));
        money->setCost(planeList->plane[id]->getPrice());
        planeID += 1;

        buttonBuyIsClicked = false;
        buyingConfirmation = false;
        buttonBuyYesIsClicked = false;
    }
    if(buttonBuyNoIsClicked)
    {
        buttonBuyIsClicked = false;
        buyingConfirmation = false;
        buttonBuyNoIsClicked = false;
    }
}

bool GUI_PlaneStore::isStoreDraw()
{
    return storeDraw;
}


