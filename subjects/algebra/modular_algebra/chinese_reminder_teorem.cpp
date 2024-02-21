#include<bits/stdc++.h>

using namespace std;

#define int long long

int power(int a, int n, int mod)
{
    if(n== 0)
        return 1;
    
    int half = power(a, n/2, mod);

    int res = (half * half) % mod;

    if(n % 2)
        res = (res * a) %mod;

    return res;
}

signed main()
{
    int p1, p2, r1, r2; cin >> p1 >> p2 >> r1 >> r2;

    if(r1 > r2)
    {
        swap(p1, p2);
        swap(r1, r2);
    }

    int c = r2 - r1;

    int ppow = power(p1, p2-2, p2);

    int k = (ppow * c) % p2;

    cout << k*p1 + r1<< endl;

    return 0;
}