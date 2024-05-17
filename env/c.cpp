#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define IOS ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false); 
#define endl '\n'
#define bug(x)  cerr << #x << " >>> " << x << endl;
#define all(A) A.begin(), A.end()

int values[(int)1e6] = {0};

void solve()
{
   int n; cin  >> n;

    multiset<pair<int, int>> s;

    for(int i = 0; i < n; i++)
    {
        cin >> values[i];
        s.insert({values[i], -i});
    }

    
}

 
signed main()
{
    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    } 
    
    return 0;
}


