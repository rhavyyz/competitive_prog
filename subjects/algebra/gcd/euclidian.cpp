// #include<bits/stdc++.h>
#include <iostream>

using namespace std;

/*

It stated that gcd(a, b) = gcd(b, a%b), and that 

gcd(a, 0) = a

So there is a recursive way to find gcd(a, b) in O(log n)

*/

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