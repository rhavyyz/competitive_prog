#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{

    int D, C,R; cin >> D >> C >> R;

    int tot = R; // Ele vai sempre conseguir fazer todas as atividades
    // que dao energia a ele entao podemos usar de valor incial

    vector<int> tiring(C);

    for(auto &v: tiring)
        cin >> v;

    // Como ele faz todas as atividades que dao energia
    // apenas as somarei no valor total de energia
    while(R--)
    {
        int aux; cin >> aux;
        D += aux;
    }
    for(auto v: tiring)
    {
        if(v > D)
            break;
        D-=v;
        tot++;
    }

    cout << tot << endl;
}

signed main()
{
    int t = 1; 
    // cin >> t;

    while(t--)
        solve();

    return 0;
}