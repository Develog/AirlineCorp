#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>

using namespace std;

class Country
{
    public:
        Country();
        Country(string countryName, string continentName);
        ~Country();

        string getCountryName();
        string getContinentName();

    private:
        string _countryName, _continentName;
};

#endif // COUNTRY_H
