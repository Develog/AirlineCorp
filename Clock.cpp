#include "Clock.h"

Clock::Clock()
{
    // d�marre le chrono
    Time elapsed1 = clockTime.getElapsedTime();
    cout << elapsed1.asSeconds() << endl;
    clockTime.restart();
}
