#include "Airport.h"

Airport::Airport()
{

}

Airport::Airport(string country, string city, string name, string code, Vector2f lat, Vector2f lon, int categoryLevel, int closeInhabitant, float baseIndex)
{
    _country = country;
    _city = city;
    _name = name;
    _code = code;
    _lat = lat;
    _lon = lon;
    _categoryLevel = categoryLevel;
    _closeInhabitant = closeInhabitant;
    _attractionIndex = baseIndex;
    _potentialPassengerIndex = baseIndex;
}

Airport::~Airport()
{
    //dtor
}

///SETTERS
void Airport::setCountry(string country)
{
    _country = country;
}

void Airport::setCity(string city)
{
    _city = city;
}

void Airport::setName(string name)
{
    _name = name;
}

void Airport::setCode(string code)
{
    _code = code;
}

void Airport::setCloseInhabitant(int closeInhabitant)
{
    _closeInhabitant = closeInhabitant;
}

void Airport::setCategoryLevel(int categoryLevel)
{
    _categoryLevel = categoryLevel;
}

void Airport::setInfrastructureLevel(int infrastructureLevel)
{
    _infrastructureLevel = infrastructureLevel;
}

void Airport::setReputationLevel(int reputationLevel)
{
    _reputationLevel = reputationLevel;
}

void Airport::setAttractionIndex(float attractionIndex)
{
    _attractionIndex = attractionIndex;
}

void Airport::setPotentialPassengerIndex(float potentialPassengerIndex)
{
    _potentialPassengerIndex = potentialPassengerIndex;
}

///GETTERS
string Airport::getCountry()
{
    return _country;
}

string Airport::getCity()
{
    return _city;
}

string Airport::getName()
{
    return _name;
}

string Airport::getCode()
{
    return _code;
}

Vector2f Airport::getLat()
{
    return _lat;
}

Vector2f Airport::getLon()
{
    return _lon;
}

int Airport::getCloseInhabitant()
{
    return _closeInhabitant;
}

int Airport::getCategoryLevel()
{
    return _categoryLevel;
}

int Airport::getInfrastructureLevel()
{
    return _infrastructureLevel;
}

int Airport::getReputationLevel()
{
    return _reputationLevel;
}

float Airport::getAttractionIndex()
{
    return _attractionIndex;
}

float Airport::getPotentialPassengerIndex()
{
    return _potentialPassengerIndex;
}
