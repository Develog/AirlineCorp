#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <string>
#include "Plane.h"

using namespace std;

class Line
{
    public:
        Line();
        ~Line();

        void setOrigin(string origin); //AeroportList
        void setDestination(string destination);
        void setCategory(string category);
        void setDistance(int distance);
        void setTicketPrice(int price);
        void autoTicketPrice();
        void setPassengerCapacity(int capacity);
        void addFlight(Plane* plane, float schedule);
        void setScheduleHour(int scheduleHour);
        void setScheduleMinute(int scheduleMinute);

        string getOrigin();
        string getDestination();
        string getCategory();

        int getDistance();
        int getTicketPrice();
        int getPassengerCapacity();
        int getPlaneCapacity();
        int getPlaneQuantity();
        int getScheduleHour();
        int getScheduleMinute();
    private:

        string _origin, _destination, _category;
        int _distance, _ticketPrice, _passengerCapacity, _planeCapacity;
        int _planeQuantity;
        int _scheduleHour, _scheduleMinute;
};

#endif // LINE_H
