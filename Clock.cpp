#include "Clock.h"

Clock::Clock()
{
    // démarre le chrono
    Time elapsed1 = clockTime.getElapsedTime();
    cout << elapsed1.asSeconds() << endl;
    clockTime.restart();
}
