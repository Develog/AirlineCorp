#include "CountryList.h"

CountryList::CountryList()
{
    // maxi de 48 pays par continent --> 6 * 8 = 48 donc 8 lignes de pays et idem pour les aéroports
    //(Monter à 60 si possible voir ) à tester 10 lignes

    ///EUROPE
    country [0] = new Country("Albania", "Europe"); country [1] = new Country("Austria", "Europe"); country [2] = new Country("Austria", "Europe"); country [3] = new Country("Belarus", "Europe");
    country [4] = new Country("Belgium", "Europe"); country [5] = new Country("Bosnia and Herzegovina", "Europe"); country [6] = new Country("Bulgaria", "Europe"); country [7] = new Country("Croatia", "Europe");
    country [8] = new Country("Czech Republic", "Europe"); country [9] = new Country("Denmark", "Europe"); country [10] = new Country("Estonia", "Europe"); country [11] = new Country("Finland", "Europe");
    country [12] = new Country("France", "Europe"); country [13] = new Country("Germany", "Europe"); country [14] = new Country("Greece", "Europe"); country [15] = new Country("Hungary", "Europe");
    country [16] = new Country("Iceland", "Europe"); country [17] = new Country("Ireland", "Europe"); country [18] = new Country("Italy", "Europe"); country [19] = new Country("Latvia", "Europe");
    country [20] = new Country("Lithuania", "Europe"); country [21] = new Country("Luxembourg", "Europe"); country [22] = new Country("Macedonia", "Europe"); country [23] = new Country("Malta", "Europe");
    country [24] = new Country("Moldova", "Europe"); country [25] = new Country("Montenegro", "Europe"); country [26] = new Country("Netherlands", "Europe"); country [27] = new Country("Norway", "Europe");
    country [28] = new Country("Poland", "Europe"); country [29] = new Country("Portugal", "Europe"); country [30] = new Country("Romania", "Europe"); country [31] = new Country("Russia", "Europe");
    country [32] = new Country("Serbia", "Europe"); country [33] = new Country("Slovakia", "Europe"); country [34] = new Country("Slovenia", "Europe"); country [35] = new Country("Spain", "Europe");
    country [36] = new Country("Sweden", "Europe"); country [37] = new Country("Switzerland", "Europe"); country [38] = new Country("Ukraine", "Europe"); country [39] = new Country("United Kingdom", "Europe");

    ///NORTH AMERICA
    country[40] = new Country("Bahamas", "North America"); country[41] = new Country("Canada", "North America"); country[42] = new Country("Costa Rica", "North America"); country[43] = new Country("Cuba", "North America");
    country[44] = new Country("Dominican Republic", "North America"); country[45] = new Country("El Savador", "North America"); country[46] = new Country("Guatemala", "North America"); country[47] = new Country("Haiti", "North America");
    country[48] = new Country("Honduras", "North America"); country[49] = new Country("Jamaica", "North America"); country[50] = new Country("Mexico", "North America"); country[51] = new Country("Nicaragua", "North America");
    country[52] = new Country("Panama", "North America"); country[53] = new Country("Trinidad and Tobago", "North America"); country[54] = new Country("United States", "North America");

    ///SOUTH AMERICA
    country[55] = new Country("Argentina", "South America"); country[56] = new Country("Bolivia", "South America"); country[57] = new Country("Brazil", "South America"); country[58] = new Country("Chile", "South America");
    country[59] = new Country("Colombia", "South America"); country[60] = new Country("Ecuador", "South America"); country[61] = new Country("Guyana", "South America"); country[62] = new Country("Paraguay", "South America");
    country[63] = new Country("Peru", "South America"); country[64] = new Country("Suriname", "South America"); country[65] = new Country("Uruguay", "South America"); country[66] = new Country("Venezuela", "South America");

}

CountryList::~CountryList()
{
    //dtor
}
