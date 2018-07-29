#include "Plane.h"

Plane::Plane()
{

}

Plane::Plane(string planeName, string category, string manufactureName, int speed, int capacity, int price, int releaseDate, int radius, int fuelCapacity, int id)
{
    _planeName = planeName;
    _category = category;
    _manufactureName = manufactureName;
    _speed = speed;
    _capacity = capacity;
    _price = price;
    _releaseDate = releaseDate;
    _radius = radius;
    _fuelCapacity = fuelCapacity;
    _id = id;
}

Plane::Plane(string planeName, string category, string manufactureName, int speed, int capacity, int price, int releaseDate, int radius, int fuelCapacity, float consumption, int id, string filePath)
{
    _planeName = planeName;
    _category = category;
    _manufactureName = manufactureName;
    _speed = speed;
    _capacity = capacity;
    _price = price;
    _releaseDate = releaseDate;
    _radius = radius;
    _fuelCapacity = fuelCapacity;
    _consumption = consumption;
    _id = id;
    _filePath = filePath;
}

Plane::~Plane()
{
    //dtor
}


void Plane::setPlaneName(string planeName)
{
    _planeName = planeName;
}
string Plane::getPlaneName()
{
    return _planeName;
}

void Plane::setName(string name)
{
    _name = name;
}
string Plane::getName()
{
    return _name;
}

void Plane::setCategory(string category)
{
    _category = category;
}
string Plane::getCategory()
{
    if(_category == "CC") // 3
        return "Short Haul";
    else if(_category == "MC") // 2
        return "Medium Haul";
    else if(_category == "LC") // 1
        return "Long Haul";
}

void Plane::setManufactureName(string manufactureName)
{
    _manufactureName = manufactureName;
}
string Plane::getManufactureName()
{
    return _manufactureName;
}

void Plane::setSpeed(int speed)
{
    _speed = speed;
}
int Plane::getSpeed()
{
    return _speed;
}

void Plane::setSeatCapacity(int capacity)
{
    _capacity = capacity;
}
int Plane::getSeatCapacity()
{
    return _capacity;
}

void Plane::setPrice(int price)
{
    _price = price;
}
int Plane::getPrice()
{
    return _price;
}

void Plane::setReleaseDate(int releaseDate)
{
    _releaseDate = releaseDate;
}
int Plane::getReleaseDate()
{
    return _releaseDate;
}

void Plane::setRadius(int radius)
{
    _radius = radius;
}
int Plane::getRadius()
{
    return _radius;
}

int Plane::getFuelCapacity()
{
    return _fuelCapacity;
}

float Plane::getConsumptionPerKm()
{
    return _fuelCapacity / _radius;
}

void Plane::setConsumptionPer100KmPerPassenger(float consumption)
{
    _consumption = consumption;
}
float Plane::getConsumptionPer100KmPerPassenger()
{
    return _consumption;
}

void Plane::setState(string state)
{
    _state = state;
}
string Plane::getState()
{
    return _state;
}

void Plane::isAssign(bool isAssign, float departureTime, float duration)
{
    //_isAssign = isAssign;
    /*int minute = (departureTime - floor(departureTime)) * 60;
    for(int i = 0; i < floor(departureTime); i++)
    {
        for(int j = 0; j < minute; j++)
        {
            _isAssign[floor(departureTime) + i][minute + j] = true;
        }
    }
    while()*/
}
bool Plane::isAssign()
{
    return _isAssign;
}

void Plane::setID(int id)
{
    _id = id;
}
int Plane::getID()
{
    return _id;
}


void Plane::addFlight(float departureTime, float duration)
{
    //_flightQuantity += 1;
}

void Plane::setFlightQuantity(int flightQuantity)
{
    _flightQuantity = flightQuantity;
}

void Plane::addFlight()
{
    _flightQuantity += 1;
}

int Plane::getFlightQuantity()
{
    return _flightQuantity;
}


void Plane::setPlaneID(int planeID)
{
    _planeID = planeID;
}
int Plane::getPlaneID()
{
    return _planeID;
}

string Plane::getFilePath()
{
    return _filePath;
}

void Plane::setBuyingDate(int buyingMonth, int buyingYear)
{
    if(buyingMonth > 10)
        buyingDate = to_string(buyingMonth) + " / " + to_string(buyingYear);
    else
        buyingDate = "0" + to_string(buyingMonth) + " / " + to_string(buyingYear);
}


string Plane::getBuyingDate()
{
    return buyingDate;
}
