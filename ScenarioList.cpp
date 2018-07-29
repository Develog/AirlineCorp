#include "ScenarioList.h"

ScenarioList::ScenarioList()
{
    //If objective = 0 then it's not an objective
    ///POITIERS
    scenario[0] = new Scenario(airportList.getAirportData(3)->getCity(), airportList.getAirportData(3)->getCountry(), airportList.getAirportData(3)->getName(), airportList.getAirportData(3)->getCode(), 2, 260000, 500000, 0, 40000000, 5);

    ///PERPIGNAN
    scenario[1] = new Scenario("Perpignan", "France", "Perpignan-Rivesaltes", "PGF", 1, 320000, 750000, 0, 60000000, 5);

    ///BORDEAUX
    scenario[2] = new Scenario(airportList.getAirportData(0)->getCity(), airportList.getAirportData(0)->getCountry(), airportList.getAirportData(0)->getName(), airportList.getAirportData(0)->getCode(), 1, 1200000, 5000000, 0, 100000000, 5);

    ///LYON
    scenario[3] = new Scenario(airportList.getAirportData(2)->getCity(), airportList.getAirportData(2)->getCountry(), airportList.getAirportData(2)->getName(), airportList.getAirportData(2)->getCode(), 1, 2250000, 8000000, 0, 500000000, 5);

    ///PARIS 66M passangers
    scenario[4] = new Scenario(airportList.getAirportData(1)->getCity(), airportList.getAirportData(1)->getCountry(), airportList.getAirportData(1)->getName(), airportList.getAirportData(1)->getCode(), 1, 12400000, 25000000, 0, 1000000000, 5);

    ///LONDON 75,5M passangers
    scenario[5] = new Scenario(airportList.getAirportData(10)->getCity(), airportList.getAirportData(10)->getCountry(), airportList.getAirportData(10)->getName(), airportList.getAirportData(10)->getCode(), 1, 13900000, 30000000, 0, 1200000000, 5);
}

ScenarioList::~ScenarioList()
{
    //dtor
}


Scenario* ScenarioList::getScenarioData(int idScenario)
{
    return scenario[idScenario];
}
