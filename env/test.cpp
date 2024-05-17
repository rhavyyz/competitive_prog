#include <bits/stdc++.h>
 
using namespace std;
 
// #define int long long

int solve()
{  
    int n; cin >> n;

    set<int> s;
    while(n--)
    {
        int aux; cin >> aux;
        s.insert(aux);
    }

    cout << s.size() << endl;
}

signed main()
{

    int t = 1; 
    // cin >> t;

    while(t--)
        solve();

    
    return 0;
}   