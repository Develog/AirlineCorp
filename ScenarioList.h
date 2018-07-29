#ifndef SCENARIOLIST_H
#define SCENARIOLIST_H

#include "Scenario.h"
#include "AirportList.h"

#define NUMBEROFSCENARIO 6

class ScenarioList
{
    public:
        ScenarioList();
        ~ScenarioList();

        Scenario *scenario[NUMBEROFSCENARIO];

        Scenario* getScenarioData(int idScenario);

    private:

        AirportList airportList;
};

#endif
