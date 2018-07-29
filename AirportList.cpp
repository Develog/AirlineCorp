#include "AirportList.h"

AirportList::AirportList()
{
    ///OUEST --> Negatif | SUD --> Negatif
    ///+NORD / +EST
    ///-SUD / - OUEST
    ///INDEX --> passenger / inhabitant

    ///France
    airport[0] = new Airport("France", "Bordeaux", "Bordeaux - Mérignac", "BOD", Vector2f(44, 49), Vector2f(0, 42), 1, 1200000, 4.8f);
    airport[1] = new Airport("France", "Paris", "Paris - Charles de Gaulle", "CDG", Vector2f(49, 00), Vector2f(2, 32), 1, 12400000, 5.3f);
    airport[2] = new Airport("France", "Lyon", "Lyon - Saint Exupery", "LYS", Vector2f(45, 43), Vector2f(5, 4), 1, 2200000, 4.3f);
    airport[3] = new Airport("France", "Poitiers", "Poitiers - Biard", "PIS", Vector2f(46, 35), Vector2f(0, 18), 3, 260000, 0.4f);
    airport[4] = new Airport("France", "Paris", "Paris - Orly", "ORY", Vector2f(48, 43), Vector2f(2, 21), 1, 12400000, 2.5f);
    airport[5] = new Airport("France", "Nice", "Nice - Côte d'Azur", "NCE", Vector2f(43, 39), Vector2f(7, 12), 1, 1000000, 12.f);
    airport[6] = new Airport("France", "Marseille", "Marseille - Provence", "MRS", Vector2f(43, 26), Vector2f(5, 12), 1, 1900000, 4.5f);
    airport[7] = new Airport("France", "Toulouse", "Toulouse - Blagnac", "TLS", Vector2f(43, 38), Vector2f(1, 22), 1, 1300000, 6.2f);
    airport[8] = new Airport("France", "Mulhouse", "Bâle - Mulhouse - Fribourg", "EAP", Vector2f(47, 35), Vector2f(7, 31), 1, 700000, 10.4f);
    airport[9] = new Airport("France", "Nantes", "Nantes - Atlantique", "NTE", Vector2f(47, 9), Vector2f(-1, -36), 1, 900000, 5.33f);
    airport[14] = new Airport("France", "Beauvais", "Paris - Beauvais", "BVA", Vector2f(49, 27), Vector2f(2, 6), 1, 12400000, 0.33f);
    airport[15] = new Airport("France", "Guadeloupe", "Guadeloupe - Pôle Caraïbes", "PTP", Vector2f(16, 15), Vector2f(-61, -31), 1, 400000, 5.6f);
    airport[16] = new Airport("France", "Réunion", "Réunion - Roland-Garros", "RUN", Vector2f(-20, -53), Vector2f(55, 30), 1, 840000, 2.5f);

    ///ALBANIA
    airport[13] = new Airport("Albania", "Tirana", "Tirana International Airport", "TIA", Vector2f(41, 24), Vector2f(19, 43), 1, 600000, 3.7f);




    airport[10] = new Airport("United Kingdom", "London", "London - Heathrow", "LHR",Vector2f(51, 28), Vector2f(-0, -27), 1, 12000000, 6.3f);

    airport[11] = new Airport("United States", "New York", "New York - John F. Kennedy Airport" , "JFK", Vector2f(40, 38), Vector2f(73, 46), 1, 23600000, 2.5f);

    airport[12] = new Airport("China", "Shanghai", "Shangai-Pudong Airport", "PVG", Vector2f(31, 8), Vector2f(121,48), 1, 24250000, 2.7f);
}

AirportList::~AirportList()
{
    //dtor
}

float AirportList::getDistance(string Airport1, string Airport2)
{
    for(int i = 0; i < numberOfAirport; i++)
    {
        if(Airport1 == airport[i]->getName())
        {
            idAirport1 = i;
        }
        if(Airport2 == airport[i]->getName())
        {
            idAirport2 = i;
        }
    }

    double lat1 = (airport[idAirport1]->getLat().x + airport[idAirport1]->getLat().y / 60)* 0.0174533;
    double lat2 = (airport[idAirport2]->getLat().x + airport[idAirport2]->getLat().y / 60)* 0.0174533;

    double lon1 = (airport[idAirport1]->getLon().x + airport[idAirport1]->getLon().y / 60) * 0.0174533;
    double lon2 = (airport[idAirport2]->getLon().x + airport[idAirport2]->getLon().y / 60) * 0.0174533;

    double dif = (lon2 - lon1);

    distance = 60 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dif)) / 0.0174533;
    distance *= 1.852;
    return distance;
}

string AirportList::getCity(int ID)
{
    return airport[ID]->getCity();
}

string AirportList::getCountry(int ID)
{
    return airport[ID]->getCountry();
}

string AirportList::getName(int ID)
{
    return airport[ID]->getName();
}

int AirportList::getNumberOfAirport()
{
    return numberOfAirport;
}

Airport* AirportList::getAirportData(int idAirport)
{
    return airport[idAirport];
}

