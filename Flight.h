#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>

using namespace std;

class Flight
{
    public:
        Flight();
        ~Flight();

        void setDepartureTime(float departureTime);
        float getDepartureTime();

        void setDuration(float duration);
        float getDuration();

        void setFlightName(string flightName);
        string getFlightName();

        void setPlaneID(int planeID);
        int getPlaneID();

        void setDepartureAirport(string departureAirport);
        string getDepartureAirport();

        void setArrivalAirport(string arrivalAirport);
        string getArrivalAirport();

        void setPrice(int price);
        int getPrice();

    protected:

    private:

        int _price;
        float _departureTime, _duration, _planeID;
        string _flightName, _departureAirport, _arrivalAirport;
};

#endif // FLIGHT_H
