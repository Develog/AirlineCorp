#include "FlightList.h"

FlightList::FlightList()
{
    //ctor
}

FlightList::~FlightList()
{
    //dtor
}

void FlightList::addFlight()
{
    vecFlight.push_back(flight);
}

void FlightList::addFlight(float departureTime, float duration, string departureAirport, string arrivalAirport, int planeID, string flightName)
{
    vecFlight.push_back(flight);
    vecFlight[vecFlight.size() - 1].setDepartureTime(departureTime);
    vecFlight[vecFlight.size() - 1].setDuration(duration);
    vecFlight[vecFlight.size() - 1].setDepartureAirport(departureAirport);
    vecFlight[vecFlight.size() - 1].setArrivalAirport(arrivalAirport);
    vecFlight[vecFlight.size() - 1].setPlaneID(planeID);
    vecFlight[vecFlight.size() - 1].setFlightName(flightName);

    vecFlightIdByPlane.push_back(vector<int>());
    vecFlightIdByPlane[0].push_back(99999);

    cout << vecFlightIdByPlane[0][0] << endl;


    cout << "Flight name : " << flightName << endl;
}

int FlightList::getNumberOfFlight(int planeID)
{
    numberOfFlight = 0;
    for(int i = 0; i < vecFlight.size(); i++)
    {
        if(vecFlight[i].getPlaneID() == planeID)
        {
            numberOfFlight += 1;
        }
    }

    return numberOfFlight;
}

int FlightList::getTotalNumberOfFlight()
{
    return vecFlight.size();
}

int FlightList::getFlightID(float departureTime, int planeID)
{
    ///Pour avoir l'id du vol, on prend l'id de l'avion et on vérifie que l'heure de départ corresponde

}

Flight FlightList::getFlightData(int idFlight)
{
    copyFlight = vecFlight[idFlight];
    return copyFlight;
}

Flight FlightList::getFlightData(int idFlight, int planeID)
{
    if(vecFlight[idFlight].getPlaneID() == planeID)
    {
        copyFlight = vecFlight[idFlight];
        return copyFlight;
    }
}



void FlightList::updateMoney(Money *money, ClockTime * clockTime, Hangar *hangar, Society *society)
{
    if(vecFlight.size() > 0)
    {
        for(int i = 0; i < vecFlight.size(); i++)
        {
            vecFlight[i].setPrice(ceil(airportList.getDistance(vecFlight[i].getDepartureAirport(), vecFlight[i].getArrivalAirport()) / 10));

            float departureTime = clockTime->getHourIG() + clockTime->getMinuteIG() / 60;


            if(departureTime == vecFlight[i].getDepartureTime() && _actualTime != clockTime->getMinuteIG())
            {
                //money->setMoney(money->getMoney() + vecFlight[i].getPrice() * hangar->getPlane(vecFlight[i].getPlaneID())->getSeatCapacity());
                money->addFlightIncome(vecFlight[i].getPrice() * hangar->getPlane(vecFlight[i].getPlaneID())->getSeatCapacity());
                society->addTotalPassenger(hangar->getPlane(vecFlight[i].getPlaneID())->getSeatCapacity());
            }

            float departureTime2 = round(((vecFlight[i].getDepartureTime() + vecFlight[i].getDuration() / 2.f) - floor(vecFlight[i].getDepartureTime() + vecFlight[i].getDuration() / 2.f)) * 100) / 100 + floor(vecFlight[i].getDepartureTime() + vecFlight[i].getDuration() / 2.f);

            if(departureTime == departureTime2 && _actualTime != clockTime->getMinuteIG())
            {
                money->addFlightIncome(vecFlight[i].getPrice() * hangar->getPlane(vecFlight[i].getPlaneID())->getSeatCapacity());
                society->addTotalPassenger(hangar->getPlane(vecFlight[i].getPlaneID())->getSeatCapacity());
            }

        }
        _actualTime = clockTime->getMinuteIG();
    }
}
