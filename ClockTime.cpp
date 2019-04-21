#include "ClockTime.h"

int ClockTime::_dayIG = 1;
int ClockTime::_monthIG = 1;
int ClockTime::_yearIG = 2017;

ClockTime::ClockTime()
{

}

void ClockTime::updateTime()
{
    time = clock.getElapsedTime();

    if(time.asSeconds() >= _speed)
    {
        secondIG += 1;
        clock.restart();
    }

    if(secondIG >= 1)
    {
        minuteIG += 5;
        secondIG = 0;
    }
    if(minuteIG >= 60)
    {
        hourIG += 1;
        minuteIG = 0;
    }
    if(hourIG >= 24)
    {
        dayIG += 1;
        hourIG = 0;
    }

    switch(monthIG)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if(dayIG > 31)
        {
            monthIG += 1;
            dayIG = 1;
        }
        break;
    case 4: case 6: case 9: case 11:
        if(dayIG > 30)
        {
            monthIG += 1;
            dayIG = 1;
        }
        break;
    case 2:
        if(dayIG > 28)
        {
            monthIG += 1;
            dayIG = 1;
        }
        break;
    }

    if(monthIG > 12)
    {
        yearIG += 1;
        monthIG = 1;
    }

    _dayIG = dayIG;
    _monthIG = monthIG;
    _yearIG = yearIG;
}

void ClockTime::setSpeed(float speed)
{
    _speed = speed;
}

float ClockTime::getSecondIG()
{
    return secondIG;
}

float ClockTime::getMinuteIG()
{
    return minuteIG;
}

float ClockTime::getHourIG()
{
    return hourIG;
}

int ClockTime::getDayIG()
{
    return dayIG;
}

int ClockTime::getMonthIG()
{
    return monthIG;
}

int ClockTime::getYearIG()
{
    return yearIG;
}

int ClockTime::_getDayIG()
{
    return _dayIG;
}

int ClockTime::_getMonthIG()
{
    return _monthIG;
}

int ClockTime::_getYearIG()
{
    return _yearIG;
}

