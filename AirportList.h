#ifndef AIRPORTLIST_H
#define AIRPORTLIST_H

#include <iostream>
#include <math.h>
#include "Airport.h"

#define NUMBEROFAIRPORT 17

using namespace std;

class AirportList
{
    public:
        AirportList();
        ~AirportList();

        Airport *airport[NUMBEROFAIRPORT];

        Airport* getAirportData(int idAirport);

        float getDistance(string Airport1, string Airport2);

        string getCity(int ID);
        string getCountry(int ID);
        string getName(int ID);

        int getNumberOfAirport();
    private:

        int numberOfAirport = NUMBEROFAIRPORT;
        int distance;
        int idAirport1, idAirport2;
};

#endif // AIRPORTLIST_H
