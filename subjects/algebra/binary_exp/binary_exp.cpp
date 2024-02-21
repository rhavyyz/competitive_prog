#include <bits/stdc++.h>

using namespace std;

#define int long long

int exp(int a, int b)
{

    if(b == 1)
        return a;

    int h = exp(a, b/2);

    if(b%2 == 1)
        return  h * h * a;
    
    return h * h;
}

signed main()
{


    cout << exp(15, 8) << endl;


    return 0;
}