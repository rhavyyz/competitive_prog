#include<bits/stdc++.h>

using namespace std;

/*

    The Fermat`s theorem states that

        a^(p-1)%p is always == 1 unless a % p == 0 or p % a == 0 
                        (but for a == 1 it obviously still works)

    Cool but based on this we are going to define (a/b) % p in a stable way to this mod space

    (1/a) % p 
    
    = a^-1 % p

    = a^-1 % p 
    
    = 1* (a^-1 % p)

    = (a^(p-1)%p) * (a^-1 % p)

    = (a ^(p-1) * a^-1) % p

    = (a^p-2) % p.

    Other applications of fermats theorm is the possiblilty to assume this pattern

    (assume all a`s are %p)

    a^0   , a^1   , . . ., a^p-3 , a^p-2 ,
    a^p-1 , a^p   , . . ., a^2p-4, a^2p-3,
    a^2p-2, a^2p-1, . . ., a^3p-5, a^3p-4,
    . . .

    We can assume that all values in the same column have the same value for every a in the matching conditions
    

    
*/


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