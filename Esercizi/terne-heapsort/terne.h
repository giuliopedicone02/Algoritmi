#ifndef COPPIE_H
#define COPPIE_H

#include <iostream>
using namespace std;
template <typename T>
class Terne
{
private:
    T x;
    T y;
    T z;

public:
    Terne(T x, T y, T z) : x(x), y(y), z(z){};

    T getX()
    {
        return x;
    }

    T getY()
    {
        return y;
    }

    T getZ()
    {
        return z;
    }

    bool operator>(Terne c)
    {
        if (this->x > c.x)
        {
            return true;
        }

        if (this->x == c.x && this->y > c.y)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y && this->z > c.z)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y && this->z == c.z)
        {
            return false;
        }

        return false;
    }

    friend ostream &operator<<(ostream &output, Terne &coppia)
    {
        return output << "(" << coppia.x << " " << coppia.y << " " << coppia.z << ")";
    }
};

#endif