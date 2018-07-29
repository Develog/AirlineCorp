#include "Hangar.h"

Hangar::Hangar()
{
    //ctor
}

Hangar::~Hangar()
{
    //dtor
}

void Hangar::newPlane(PlaneList *planeList, int ID, int planeID)
{
    hangarPlane.push_back(planeList->plane[ID]);
    hangarPlane[hangarPlane.size() - 1]->setName("Plane" + to_string(planeID));
    hangarPlane[hangarPlane.size() - 1]->setFlightQuantity(0);
    hangarPlane[hangarPlane.size() - 1]->setBuyingDate(ClockTime::_getMonthIG(), ClockTime::_getYearIG());
    _planeQuantity += 1;

    cout << hangarPlane[hangarPlane.size() - 1]->getPlaneName() << " - " << hangarPlane[hangarPlane.size() - 1]->getManufactureName() << " - plane ID : " << planeID << endl;
}
/*
Plane* Hangar::getPlane(PlaneList *planeList, int idPlane)
{
    return planeList->getPlaneData(idPlane);
}

Plane* Hangar::getPlaneID(PlaneList *planeList, int idPlane)
{
    return planeList->getPlaneData(hangarPlane[idPlane]->getID());
}*/

/*Plane* Hangar::getPlane(int planeID)
{
    for(int i = 0; i < hangarPlane.size(); i++)
    {
        //cout << "id : " << hangarPlane[i]->getPlaneID() << " id plane " << planeID << endl;
        if(hangarPlane[i]->getPlaneID() == planeID)
        {
            return hangarPlane[i];
        }
    }
}*/

Plane* Hangar::getPlane(int planeID)
{
    return hangarPlane[planeID];
}

void Hangar::addFlight(int planeID)
{
    hangarPlane[planeID]->setFlightQuantity(hangarPlane[planeID]->getFlightQuantity() + 1);
}

int Hangar::getFlightQuantity(int planeID)
{
    return hangarPlane[planeID]->getFlightQuantity();
}

/*int Hangar::getPlaneID(int PlaneID)
{
    hangarPlane[PlaneID]->setPlaneName("Plane" + to_string(PlaneID));
    //cout << "plane id :   " << hangarPlane[PlaneID]->getPlaneID() << endl;
    return hangarPlane[PlaneID]->getPlaneID();
}*/

int Hangar::getPlaneQuantity()
{
   return _planeQuantity;
}
