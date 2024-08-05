#pragma once

#include <cmath>

struct point2D
{
    float x, y;

    point2D(float x, float y) : x(x), y(y) 
    {}

    float operator *(point2D  p)
    {
        return x * p.x + y * p.y; 
    }

    point2D operator *(float c)
    {
        return point2D(x*c, y*c); 
    }

    float norm()
    {
        return std::sqrt((*this) * (*this));
    }
};

struct point3D 
{
    float x, y, z;

    point3D(float x, float y, float z) : x(x), y(y), z(z)
    {}

    float operator *(point3D  p)
    {
        return x * p.x + y * p.y + z * p.z; 
    }

    point3D operator *(float c)
    {
        return point3D(x*c, y*c, z*c); 
    }

    float norm()
    {
        return std::sqrt ((*this) * (*this));
    }
};
