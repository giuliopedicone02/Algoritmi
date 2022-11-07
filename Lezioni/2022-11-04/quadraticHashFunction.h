#ifndef QUADRATIC_HASH_FUNCTION_H
#define QUADRATIC_HASH_FUNCTION_H

#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class QuadraticHashFunction
{
private:
    double c1;
    double c2;

protected:
    int computeHashFunction(T x, int i, int m)
    {
        return ((int)(((int)x % m) + this->getConstantC1() * i + this->getConstantC2() * pow(i, 2))) % m;
    }

public:
    QuadraticHashFunction(double x, double y)
    {
        c1 = x;
        c2 = y;
    }

    double getConstantC1()
    {
        return c1;
    }
    double getConstantC2()
    {
        return c2;
    }
};

#endif