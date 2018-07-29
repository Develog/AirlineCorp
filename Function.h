#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Function
{
    public:
        Function();
        ~Function();

        static string NumberToSpaceNumber(int number);

    private:

        static string spaceNumber, tmpNumber;
        static int modulo;
        static int firstNumber, startingNumber, quantityOfUnit;
};

#endif // FUNCTION_H
