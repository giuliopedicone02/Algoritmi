#ifndef LINEAR_HASH_FUNCTION_H
#define LINEAR_HASH_FUNCTION_H

#include <iostream>
using namespace std;

template <class T>
class LinearHashFunction
{
protected:
    int computeHashFunction(T x, int i, int m)
    {
        return (((int)x % m) + i) % m;
    }
};

#endif