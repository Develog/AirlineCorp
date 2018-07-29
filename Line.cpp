#include "Line.h"

Line::Line()
{
    //ctor
}

Line::~Line()
{
    //dtor
}

void Line::setOrigin(string origin)
{
    _origin = origin;
}
string Line::getOrigin()
{
    return _origin;
}

void Line::setDestination(string destination)
{
    _destination = destination;
}
string Line::getDestination()
{
    return _destination;
}

void Line::setCategory(string category)
{
    _category = category;
}
string Line::getCategory()
{
    return _category;
}

void Line::setDistance(int distance)
{
    _distance = distance;
}
int Line::getDistance()
{
    return _distance;
}

void Line::setTicketPrice(int price)
{
    _ticketPrice = price;
}
void Line::autoTicketPrice()
{
    _ticketPrice = _distance / 10;
}
int Line::getTicketPrice()
{
    return _ticketPrice;
}

void Line::setPassengerCapacity(int capacity)
{
    _passengerCapacity = capacity / 1000;
}
int Line::getPassengerCapacity()
{
    return _passengerCapacity;
}

void Line::addFlight(Plane* plane, float schedule)
{
    this->setScheduleHour(int(schedule));
    this->setScheduleMinute((schedule - int(schedule)) * 60);
    cout << plane->getPlaneName() << " - " << plane->getManufactureName() << " is assign" << endl;
    _planeCapacity = plane->getSeatCapacity();
    _planeQuantity += 1;
}

void Line::setScheduleHour(int scheduleHour)
{
    _scheduleHour = scheduleHour;
}
int Line::getScheduleHour()
{
    return _scheduleHour;
}

void Line::setScheduleMinute(int scheduleMinute)
{
    _scheduleMinute = scheduleMinute;
}
int Line::getScheduleMinute()
{
    return _scheduleMinute;
}

int Line::getPlaneCapacity()
{
    return _planeCapacity;
}

int Line::getPlaneQuantity()
{
    return _planeQuantity;
}
