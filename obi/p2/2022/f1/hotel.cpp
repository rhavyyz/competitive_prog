#include<bits/stdc++.h>

#define int long long

using namespace std;



signed main()
{

    int d, a, n; cin >> d >> a >> n;

    int diaria = n;

    if(diaria > 15)
        diaria = 15;

    diaria--;

    diaria *= a;
    
    diaria+= d;


    int tot_dias = 32 - n;

    cout << tot_dias * diaria << endl;


    return 0;
}