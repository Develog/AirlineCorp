#ifndef SOCIETY_H
#define SOCIETY_H

#include <iostream>

using namespace std;

class Society
{
    public:
        Society();
        ~Society();

        static void setSocietyName(string societyName);
        static string getSocietyName();

        static void setBossName(string bossName);
        static string getBossName();

        //Exemple : Air France --> AFR
        static void setICAO_Code(string ICAO);
        static string getICAO_Code();

        //Exemple : Air France --> AF
        static void setIATA_Code(string IATA);
        static string getIATA_Code();

        static void setDepartureCity(string city);
        static string getDepartureCity();

        static void setSocietyAirport(string airportName);
        static string getSocietyAirport();

        static void setContractID(int contractID);
        static int getContractID();

        void addTotalPassenger(int totalPassenger);
        int getTotalPassenger();

        static string _societyName, _bossName, _ICAO, _IATA, _departureCity, _societyAirport;
        static int _contractID;
    private:

        int _totalPassenger = 0;
};

#endif // SOCIETY_H
