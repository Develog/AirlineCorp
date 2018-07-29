#include "Flight.h"

Flight::Flight()
{
    //ctor
}

Flight::~Flight()
{
    //dtor
}


void Flight::setDepartureTime(float departureTime)
{
    _departureTime = departureTime;
}
float Flight::getDepartureTime()
{
    return _departureTime;
}

void Flight::setDuration(float duration)
{
    _duration = duration;
}
float Flight::getDuration()
{
    return _duration;
}

void Flight::setFlightName(string flightName)
{
    _flightName = flightName;
}
string Flight::getFlightName()
{
    return _flightName;
}

void Flight::setPlaneID(int planeID)
{
    _planeID = planeID;
}
int Flight::getPlaneID()
{
    return _planeID;
}

void Flight::setDepartureAirport(string departureAirport)
{
    _departureAirport = departureAirport;
}
string Flight::getDepartureAirport()
{
    return _departureAirport;
}

void Flight::setArrivalAirport(string arrivalAirport)
{
    _arrivalAirport = arrivalAirport;
}
string Flight::getArrivalAirport()
{
    return _arrivalAirport;
}

void Flight::setPrice(int price)
{
    _price = price;
}
int Flight::getPrice()
{
    return _price;
}

