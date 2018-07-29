#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>

using namespace std;

class Scenario
{
    public:
        Scenario();
        //Here passengerQuantity is not really interesting
        Scenario(string cityName, string countryName, string airportName, string airportCode, int categoryLevel, int closeInhabitant, int passengerObjective, int flightObjective, int moneyObjective, int contractDuration);
        ~Scenario();

        void setCityName(string cityName);
        string getCityName();

        void setCountryName(string countryName);
        string getCountryName();

        void setAirportName(string airportName);
        string getAirportName();

        void setAirportCode(string airportCode);
        string getAirportCode();

        void setCategoryLevel(int categoryLevel);
        int getCategoryLevel();

        void setRenown(int renown);
        int getRenown();

        void setCloseInhabitant(int closeInhabitant);
        int getCloseInhabitant();

        void setActualPassengerQuantity(int actualPassengerQuantity);
        int getActualPassengerQuantity();

        void setPassengerObjective(int passengerObjective);
        int getPassengerObjective();

        void setFlightObjective(int flightObjective);
        int getFlightObjective();

        void setMoneyObjective(int moneyObjective);
        int getMoneyObjective();

        void setContractDuration(int contractDuration);
        int getContractDuration();

    private:

        string _cityName, _countryName, _airportName, _airportCode;
        int _categoryLevel, _renown, _closeInhabitant, _actualPassengerQuantity, _passengerObjective, _flightObjective, _moneyObjective, _contractDuration;
};

#endif // SCENARIO_H
