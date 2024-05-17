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
#define all(A) 

pair<int , int> values[2 * (int)1e6];

void solve()
{

    int n; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> values[i].first >> values[i].second;

    sort(values, values+n);

    ordered_set<int> ds;

    int tot = 0;

    for(int i = n-1; i >= 0; i--)
    {
        if(!ds.empty())
            tot += ds.order_of_key(values[i].second);


        ds.insert(values[i].second);
    }

    cout << tot << endl;

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