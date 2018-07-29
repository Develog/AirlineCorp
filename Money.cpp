#include "Money.h"

Money::Money()
{

}

Money::~Money()
{
    //dtor
}

void Money::setMoney(int quantity)
{
    _money = quantity;
}
int Money::getMoney()
{
    return _money;
}

void Money::addFlightIncome(int flightIncome)
{
    _flightIncome += flightIncome;
    _money += flightIncome;
}

void Money::setFlightIncome(int flightIncome)
{
    _flightIncome = flightIncome;
}
int Money::getFlightIncome()
{
    return _flightIncome;
}

void Money::setCost(int cost)
{
    this->setMoney(this->getMoney() - cost);
}
