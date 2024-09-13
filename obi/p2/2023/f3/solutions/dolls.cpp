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

int n, k;
int memo[10010][3010];

int vals[10010];

int dp(int pos, int selected)
{
    // cout << "OK1" << endl;
    if(selected == k)
        return 0;
    // cout << "OK2" << endl;

    if(pos >= n-2 || n-pos < (k-selected)*3)
        return INF;

    if(memo[pos][selected] != INF)
        return memo[pos][selected];
    
    return memo[pos][selected] = min(
        dp(pos+1, selected),
        dp(pos+2, selected+1) + ((vals[pos+1]-vals[pos]) * (vals[pos+1]-vals[pos]))
    );
}

int solve()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> vals[i];

    sort(vals, vals+n);
    for(int i = 0; i <= n+5; i++)
    {
        for(int j = 0; j <= k+5; j++)
            memo[i][j] = INF;
    }

    cout << dp(0, 0) << endl;


    return 0;
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