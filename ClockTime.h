#ifndef CLOCKTIME_H
#define CLOCKTIME_H

#include <SFML/System/Clock.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ClockTime
{
    public:
        ClockTime();

        void updateTime();
        void setSpeed(float speed);

        float getSecondIG();
        float getMinuteIG();
        float getHourIG();
        int getDayIG();
        int getMonthIG();
        int getYearIG();

        static int _getDayIG();
        static int _getMonthIG();
        static int _getYearIG();

    private:
        Clock clock;
        Time time;

        float _speed = 1;
        float secondIG, minuteIG, hourIG;
        int second, minute, hour, day, month, year;
        int dayIG = 1, monthIG = 1, yearIG= 2017;
        static int _dayIG, _monthIG, _yearIG;
};

#endif // CLOCKTIME_H
