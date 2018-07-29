#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include "Country.h"

#define NUMBEROFCOUNTRY 200

class CountryList
{
    public:
        CountryList();
        virtual ~CountryList();

        Country *country[NUMBEROFCOUNTRY];

    private:
};

#endif // COUNTRYLIST_H
