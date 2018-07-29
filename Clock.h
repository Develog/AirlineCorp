#ifndef CLOCK_H
#define CLOCK_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Clock
{
    public:
        Clock();

    private:

        sf::Clock clockTime;
};

#endif // CLOCK_H
