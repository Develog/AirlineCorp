#include "Function.h"

string Function::spaceNumber = "";
string Function::tmpNumber = "";
int Function::modulo = 0;
int Function::firstNumber = 0;
int Function::startingNumber = 0;
int Function::quantityOfUnit = 0;

Function::Function()
{
    //ctor
}

Function::~Function()
{
    //dtor
}

string Function::NumberToSpaceNumber(int number)
{
    tmpNumber = to_string(number);
    spaceNumber = tmpNumber;
    quantityOfUnit = tmpNumber.length() / 3;
    for(int i = 0; i < quantityOfUnit; i++)
    {
        spaceNumber += ' ';
    }

    int indexTmp = 0;

    for(int i = 1; i <= spaceNumber.length(); i++)
    {
        if(i == 4 || i == 8 || i == 12)
        {
            spaceNumber[spaceNumber.length() - i] = ' ';
        }
        else
        {
            indexTmp++;
            spaceNumber[spaceNumber.length() - i] = tmpNumber[tmpNumber.length() - indexTmp];
        }

    }

    /*spaceNumber[spaceNumber.length() - 1] = tmpNumber[tmpNumber.length() - 1];
    spaceNumber[spaceNumber.length() - 2] = tmpNumber[tmpNumber.length() - 2];
    spaceNumber[spaceNumber.length() - 3] = tmpNumber[tmpNumber.length() - 3];
    spaceNumber[spaceNumber.length() - 4] = ' ';
    spaceNumber[spaceNumber.length() - 5] = tmpNumber[tmpNumber.length() - 4];
    spaceNumber[spaceNumber.length() - 6] = tmpNumber[tmpNumber.length() - 5];
    spaceNumber[spaceNumber.length() - 7] = tmpNumber[tmpNumber.length() - 6];
    spaceNumber[spaceNumber.length() - 8] = ' ';
    spaceNumber[spaceNumber.length() - 9] = tmpNumber[tmpNumber.length() - 7];
    spaceNumber[spaceNumber.length() - 10] = tmpNumber[tmpNumber.length() - 8];
    spaceNumber[spaceNumber.length() - 11] = tmpNumber[tmpNumber.length() - 9];
    spaceNumber[spaceNumber.length() - 12] = ' ';
    spaceNumber[spaceNumber.length() - 13] = tmpNumber[tmpNumber.length() - 10];*/

    return spaceNumber;
}
