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

int solve(){
    int n, a, b; cin >> n >> a >> b;
    
    int n_b = b-a + 1;

    // cout << n_b << ' ';

    if(n_b < 0)
        return cout << n * a << endl, 0;


    if(n_b > n)
    {
        n_b = n;
        a = b-n+1;
    }


    int tot_b = (b + a)* n_b / 2;
    // cout <<  (b + a)* n_b / 2 << ' ';

    cout << tot_b + (n-n_b) * a << endl;


    return 1;
}
 
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;    

    while(t--)
        solve();
    
    return 0;
}