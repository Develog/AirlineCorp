#include "Scenario.h"

Scenario::Scenario()
{
    //ctor
}

Scenario::Scenario(string cityName, string countryName, string airportName, string airportCode, int categoryLevel, int closeInhabitant, int passengerObjective, int flightObjective, int moneyObjective, int contractDuration)
{
    _cityName = cityName;
    _countryName = countryName;
    _airportName = airportName;
    _airportCode = airportCode;
    _categoryLevel = categoryLevel;
    _closeInhabitant = closeInhabitant;
    _passengerObjective = passengerObjective;
    _flightObjective = flightObjective;
    _moneyObjective = moneyObjective;
    _contractDuration = contractDuration;
}

Scenario::~Scenario()
{
    //dtor
}


void Scenario::setCityName(string cityName)
{
    _cityName = cityName;
}
string Scenario::getCityName()
{
    return _cityName;
}


void Scenario::setCountryName(string countryName)
{
    _countryName = countryName;
}
string Scenario::getCountryName()
{
    return _countryName;
}


void Scenario::setAirportName(string airportName)
{
    _airportName = airportName;
}
string Scenario::getAirportName()
{
    return _airportName;
}


void Scenario::setAirportCode(string airportCode)
{
    _airportCode = airportCode;
}
string Scenario::getAirportCode()
{
    return _airportCode;
}


void Scenario::setCategoryLevel(int categoryLevel)
{
    _categoryLevel = categoryLevel;
}
int Scenario::getCategoryLevel()
{
    return _categoryLevel;
}







void Scenario::setPassengerObjective(int passengerObjective)
{
    _passengerObjective = passengerObjective;
}
int Scenario::getPassengerObjective()
{
    return _passengerObjective;
}


void Scenario::setFlightObjective(int flightObjective)
{
    _flightObjective = flightObjective;
}
int Scenario::getFlightObjective()
{
    return _flightObjective;
}


void Scenario::setMoneyObjective(int moneyObjective)
{
    _moneyObjective = moneyObjective;
}
int Scenario::getMoneyObjective()
{
    return _moneyObjective;
}


void Scenario::setContractDuration(int contractDuration)
{
    _contractDuration = contractDuration;
}
int Scenario::getContractDuration()
{
    return _contractDuration;
}
