#ifndef HANGAR_H
#define HANGAR_H

#include "PlaneList.h"
#include "Plane.h"
#include "ClockTime.h"
#include <vector>

using namespace std;

class Hangar
{
    public:
        Hangar();
        ~Hangar();

        void newPlane(PlaneList *planeList, int ID, int planeID);

        void addFlight(int planeID);
        int getFlightQuantity(int planeID);

        //Plane* getPlane(PlaneList *planeList, int idPlane);
        //Plane* getPlaneID(PlaneList *planeList, int idPlane);
        Plane* getPlane(int planeID);
        //Plane* getPlane(int planeID);

        int getPlaneQuantity();

        int getPlaneID(int PlaneID);

    private:

        int _planeQuantity;

        Plane plane;
        vector<Plane*> hangarPlane;
};

#endif // HANGAR_H
