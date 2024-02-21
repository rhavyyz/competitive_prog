#include <bits/stdc++.h>

using namespace std;

#define int long long

// Fixando um vetor 2x2
array<array<int, 2>, 2> mul(
    array<array<int, 2>, 2> a, 
    array<array<int, 2>, 2> b
    )
{
    array<array<int, 2>, 2> res;

    res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    cout << res[0][0] << res[0][1] << endl << res[1][0] << res[1][1] << endl;

    return res;
}

array<array<int, 2>, 2> exp(array<array<int, 2>, 2> a, int b)
{
    if(b == 1)
        return a;

    auto h = exp(a, b/2);

    if(b%2 == 1)
        return  mul(mul(h, h), a);
    
    return mul(h, h);
}

signed main()
{

    

    return 0;
}