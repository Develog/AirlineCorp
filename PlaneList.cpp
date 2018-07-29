#include "PlaneList.h"

PlaneList::PlaneList()
{
    //1 USD --> 0.8 EURO
    // NAME | TYPE | BRAND NAME | SPEED (km/h) | SEAT | PRICE (EURO) | RELEASE DATE | RANGE (km) | FUEL CAPACITY (L) | CONSUMPTION | ID
    //SHORT HAUL < 3000 km
    //MEDIUM HAUL < 7500 km
    //LONG HAUL > 7500 km
    plane[2] = new Plane("42 - 500", "CC", "ATR", 550, 50, 12000000, 1985, 1500, 5600, 3.15f, 2, "TEST/ATR42-500.png");

    ///BOMBARDIER
    plane[3] = new Plane("CRJ-200", "MC", "Bombardier", 790, 50, 20000000, 1992, 3150, 8000, 4.32f, 3, "TEST/CRJ 200.png");
    plane[4] = new Plane("CRJ-700", "MC", "Bombardier", 830, 78, 39500000, 2001, 3600, 11000, 3.75f, 4, "TEST/CRJ 700.png");
    plane[5] = new Plane("CRJ-900", "MC", "Bombardier", 850, 90, 43800000, 2003, 3400, 11000, 3.58f, 5, "TEST/CRJ900.png");
    plane[6] = new Plane("CRJ-1000", "MC", "Bombardier", 830, 104, 46600000, 2011, 3000, 11000, 3.33f, 6, "TEST/CRJ1000.png");
    plane[7] = new Plane("CS100", "MC", "Bombardier", 830, 125, 72000000, 2016, 5740, 14100, 2.14f, 7, "TEST/CS100.png");
    plane[8] = new Plane("CS300", "MC", "Bombardier", 830, 160, 80700000, 2016, 6100, 13770, 1.92f, 8, "TEST/CS300.png");

    ///AIRBUS
    plane[10] = new Plane("A318-100", "MC","Airbus", 830, 110, 61500000, 2003, 5750, 24000, 2.91f, 10, "TEST/A318.png");
    plane[11] = new Plane("A319-100", "MC","Airbus", 830, 124, 73300000, 1996, 6800, 29800, 2.95f, 11, "TEST/A319.png");
    plane[0] = new Plane("A320-200", "MC", "Airbus", 830, 150, 80200000, 1988, 6100, 25000, 2.43f, 0, "TEST/A320.png");
    plane[12] = new Plane("A321-200", "MC", "Airbus", 830, 220, 94000000, 1994, 5600, 29500, 2.5f, 12, "TEST/A320.png");
    plane[13] = new Plane("A330-300", "LC", "Airbus", 860, 375, 209200000, 1995, 10500, 139000, 2.37f, 13, "TEST/A330-300.png");
    plane[14] = new Plane("A350-1000", "LC", "Airbus", 1050, 440, 290260000, 2018, 15600, 156000, 2.f, 14, "TEST/A350-1000.png");
    plane[1] = new Plane("A380-800", "LC", "Airbus", 900, 525, 353800000, 2007, 15700, 320000, 3.27f, 1, "TEST/A380.png");

    ///BOEING


    ///BOOM
    plane[9] = new Plane("Boom Supersonic (PROJECT)", "LC", "BOOM", 2300, 50, 100000000, 2020, 5000, 50000, 20.00f, 9, "TEST/BOOM.png");
}

PlaneList::~PlaneList()
{
    //dtor
}

Plane* PlaneList::getPlaneData(int idPlane)
{
    return plane[idPlane];
}
