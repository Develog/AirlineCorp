#include "Society.h"

string Society::_societyName = "";
string Society::_bossName = "";
string Society::_ICAO = "";
string Society::_IATA = "";
string Society::_departureCity = "";
string Society::_societyAirport = "";
int Society::_contractID = 0;

Society::Society()
{
    //ctor
}

Society::~Society()
{
    //dtor
}

void Society::setSocietyName(string societyName)
{
    _societyName = societyName;
}
string Society::getSocietyName()
{
    return _societyName;
}


void Society::setBossName(string bossName)
{
    _bossName = bossName;
}
string Society::getBossName()
{
    return _bossName;
}

void Society::setICAO_Code(string ICAO)
{
    _ICAO = ICAO;
}
string Society::getICAO_Code()
{
    return _ICAO;
}

void Society::setIATA_Code(string IATA)
{
    _IATA = IATA;
}
string Society::getIATA_Code()
{
    return _IATA;
}


void Society::setDepartureCity(string city)
{
    _departureCity = city;
}
string Society::getDepartureCity()
{
    return _departureCity;
}

void Society::setSocietyAirport(string airportName)
{
    _societyAirport = airportName;
}
string Society::getSocietyAirport()
{
    return _societyAirport;
}

void Society::setContractID(int contractID)
{
    _contractID = contractID;
}
int Society::getContractID()
{
    return _contractID;
}

void Society::addTotalPassenger(int totalPassenger)
{
    _totalPassenger += totalPassenger;
}
int Society::getTotalPassenger()
{
    return _totalPassenger;
}
