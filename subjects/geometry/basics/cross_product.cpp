#include "./points.cpp"

#pragma once

/*

    The idea of cross product is to describe a operation that outputs a vector from other two

    This outputed vector has some properties. 
        - It needs to be orthogonal to both input vectors
        - Its norm is numerically equal to the area of the parallelogram created from the input vectors
        - Its norm is defined by |A||B|sin(θ)

*/

// This is equivalent to calculating that weird "determinant"
point3D cross(point3D a, point3D b) {
    return point3D(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}

// "Mixed product"

float mixed(point3D A, point3D B, point3D C)
{
    return A * cross(B, C);
}
