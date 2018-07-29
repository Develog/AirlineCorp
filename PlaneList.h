#ifndef PLANELIST_H
#define PLANELIST_H

#include "Plane.h"
#include <vector>

#define NUMBEROFPLANE 15

class PlaneList
{
    public:
        PlaneList();
        ~PlaneList();

        Plane *plane[NUMBEROFPLANE];

        Plane* getPlaneData(int idPlane);

    private:

        vector<Plane*> vecPlane;
};

#endif // PLANELIST_H
