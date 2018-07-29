#include "Country.h"

Country::Country()
{
    //ctor
}

Country::Country(string countryName, string continentName)
{
    _countryName = countryName;
    _continentName = continentName;
}

Country::~Country()
{
    //dtor
}

string Country::getCountryName()
{
    return _countryName;
}

string Country::getContinentName()
{
    return _continentName;
}
