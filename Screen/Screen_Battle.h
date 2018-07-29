#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screen.h"

using namespace std;

class Screen_Battle : public Screen
{
    public:
        Screen_Battle(void);
        virtual int Run(sf::RenderWindow &window);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {

        }

};
