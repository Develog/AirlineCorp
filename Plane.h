#ifndef PLANE_H
#define PLANE_H

#include <iostream>

using namespace std;

class Plane
{
    public:
        Plane();
        Plane(string planeName, string category, string manufactureName, int speed, int capacity, int price, int releaseDate, int radius, int fuelCapacity, int id);
        Plane(string planeName, string category, string manufactureName, int speed, int capacity, int price, int releaseDate, int radius, int fuelCapacity, float consumption, int id, string filePath);
        ~Plane();

        void setPlaneName(string planeName);
        void setName(string name);
        void setCategory(string category);
        void setManufactureName(string manufactureName);
        void setSpeed(int speed);
        void setSeatCapacity(int capacity);
        void setPrice(int price);
        void setReleaseDate(int releaseDate);
        void setRadius(int radius);
        void setState(string state);
        void setConsumptionPer100KmPerPassenger(float consumption);
        void isAssign(bool isAssign, float departureTime, float duration);
        void setID(int id);
        void addFlight(float departureTime, float duration);
        void setFlightQuantity(int flightQuantity);
        void addFlight();
        void setPlaneID(int planeID);
        void setBuyingDate(int buyingMonth, int buyingYear);

        string getPlaneName();
        string getName();
        string getCategory();
        string getManufactureName();
        int getSpeed();
        int getSeatCapacity();
        int getPrice();
        int getReleaseDate();
        int getRadius();
        int getFuelCapacity();
        float getConsumptionPerKm();
        float getConsumptionPer100KmPerPassenger();
        string getState();
        bool isAssign();
        int getID();
        int getFlightQuantity();
        int getPlaneID();
        string getFilePath();
        string getBuyingDate();

    private:

        string _planeName, _name, _category, _manufactureName, _state, _filePath, buyingDate;
        int _speed, _capacity, _price, _releaseDate, _radius, _fuelCapacity, _id, _flightQuantity = 0, _planeID, buyingMonth, buyingYear;
        float _consumption;
        //bool _isAssign = false;

        bool _isAssign[24][60];

};

#endif // PLANE_H
