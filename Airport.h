#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <SFML/System/Vector2.hpp>

using namespace std;
using namespace sf;

class Airport
{
    public:
        Airport();
        Airport(string country, string city, string name, string code, Vector2f lat, Vector2f lon, int categoryLevel, int closeInhabitant, float baseIndex);
        ~Airport();

        void setCountry(string country);
        void setCity(string city);
        void setName(string name);
        void setCode(string code);
        void setCloseInhabitant(int closeInhabitant);
        void setCategoryLevel(int categoryLevel);
        void setInfrastructureLevel(int infrastructureLevel);
        void setReputationLevel(int reputationLevel);
        void setAttractionIndex(float attractionIndex);
        void setPotentialPassengerIndex(float potentialPassengerIndex);

        string getCountry();
        string getCity();
        string getName();
        string getCode();
        Vector2f getLat();
        Vector2f getLon();
        int getCloseInhabitant();
        int getCategoryLevel();
        int getInfrastructureLevel();
        int getReputationLevel();
        float getAttractionIndex();
        float getPotentialPassengerIndex();

    private:
        string _city, _country, _name, _code;
        Vector2f _lat, _lon;
        int _closeInhabitant, _categoryLevel, _infrastructureLevel, _reputationLevel;
        float _attractionIndex, _potentialPassengerIndex;
};

#endif // AIRPORT_H
