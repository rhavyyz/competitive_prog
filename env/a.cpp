#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; //required 
using namespace std;
 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#define int long long 
#define IOS ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false); 
#define endl '\n'
#define bug(x)  cerr << #x << " >>> " << x << endl;
#define all(A) A.begin(), A.end()

// int n;
const int INF = 1e17;

int vals[6];

int possible = false;

void solve()
{
    for(int i = 0; i < 6; i++)
        cin >> vals[i];
    sort(vals, vals+6);

    int t1 = vals[5];
    int t2 = vals[3] + vals[4];
    int t3 = vals[0] + vals[1] + vals[2];

    bool ok = false;

    if(t1 == t2 && t2 == t3) ok = true;

    while(next_permutation(vals, vals+6))
    {
        t1 = vals[5];
        t2 = vals[3] + vals[4];
        t3 = vals[0] + vals[1] + vals[2];
        if(t1 == t2 && t2 == t3) ok = true;
    }

    if(ok)
        cout << 'S' << endl;
    else
        cout << 'N' << endl;


}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;    

    while(t--)
    {
        solve();
    } 
    

    return 0;
}