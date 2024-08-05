#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

// To do LCM you just need to know that
//
//      a*b = lcm(a,b)*gcd(a,b)
//
// So
//
//      lcm(a,b) = a*b/gcd(a,b) 


int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{


    return 0;
}