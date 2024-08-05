#include "./points.cpp"

#pragma once

/*

    To start we need to know that

    The cross product of A and B is equal to

    |A||B|cos(θ) = A.x * B.x + A.y * B.y + A.z * B.z

    we can see that when θ = 90°, the cross prod = 0.


*/

point3D project(point3D& A, point3D& B)
{
    auto normalizedB = B * (1/B.norm());

    auto Acos = (A* B)/B.norm();

    return normalizedB * Acos;
}

float cosValBetween(point3D& A, point3D& B)
{
    return (A*B) / (A.norm(), B.norm());
}

