#ifndef COPPIE_H
#define COPPIE_H

#include <iostream>
using namespace std;
template <typename T>
class Coppia
{
private:
    T x;
    T y;

public:
    Coppia(T x, T y) : x(x), y(y){};

    T getX()
    {
        return x;
    }

    T getY()
    {
        return y;
    }

    bool operator>(Coppia c)
    {
        if (this->x > c.x)
        {
            return true;
        }

        if (this->x == c.x && this->y > c.y)
        {
            return true;
        }

        if (this->x == c.x && this->y == c.y)
        {
            return false;
        }

        return false;
    }

    friend ostream &operator<<(ostream &output, Coppia &coppia)
    {
        return output << "(" << coppia.x << " " << coppia.y << ")";
    }
};

#endif