#ifndef FLIGHTLIST_H
#define FLIGHTLIST_H

#include <vector>
#include "Flight.h"
#include "Money.h"
#include "ClockTime.h"
#include "Hangar.h"
#include "AirportList.h"
#include "Society.h"

class FlightList
{
    public:
        FlightList();
        ~FlightList();

        void addFlight();
        void addFlight(float departureTime, float duration, string departureAirport, string arrivalAirport, int planeID, string flightName);

        int getNumberOfFlight(int planeID);
        int getTotalNumberOfFlight();

        int getFlightID(float departureTime, int planeID);

        Flight getFlightData(int idFlight);
        Flight getFlightData(int idFlight, int planeID);

        void updateMoney(Money *money, ClockTime * clockTime, Hangar *hangar, Society *society);

    private:

        Flight flight;
        vector <Flight> vecFlight;

        //planeID, IdFlightByPlane;
        vector<vector<int>> vecFlightIdByPlane;

        Flight copyFlight;

        AirportList airportList;

        int numberOfFlight = 0;

        float _actualTime;
};

#endif // FLIGHTLIST_H
