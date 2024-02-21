// #include<bits/stdc++.h>
#include <iostream>

using namespace std;


// template<class T>
// void swap(T a, T b)
// {
//     T aux = a;
//     a = b;
//     b = aux;
// }

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

signed main()
{


    return 0;
}