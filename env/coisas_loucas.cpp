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

int arr[(int)1e4 + 10];

vector<pair<int , int>> buckets[(int)1e4 + 10];
/*
    No primeiro bucket na posicao r vou colocar um par l, j
    com j sendo o index da querie l, r.

    for(int k = 1; k <= n; k++)
    {

        int minimo = INF;

        for(int i = k; i <= n; i++)
        {
            auto it = freq.lower_bound(arr[i])


            if(it != freq.begin())
                minimo = min(abs(prev(it)->first - arr[i]), minimo)

            if(it != freq.end())
                minimo = min(abs(it->first - arr[i]), minimo)

            freq[arr[i]]++

            for(auto [l, j] : buckets[i])
            {
                if(l == i)
                    ans[j] = minimo
            }
        }


    }

*/

void solve()
{

    int n; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int q; cin >> q;
    vector<int> ans(q);
    for(int i = 0; i < q; i++)
    {
        int l, r;

        cin >> l >> r;
        l--;r--;

        buckets[r].push_back({l, i});

    }

    for(int l = 0; l < n; l++)
    {
        set<int> freq; 

        int minimo = 1e8;

        for(int r = l; r < n; r++)
        {

            if(minimo > 0)
            {
                auto it = freq.lower_bound(arr[r]);

                if(it != freq.begin())
                    minimo = min(abs( *prev(it) - arr[r]), minimo);

                if(it != freq.end())
                    minimo = min(abs(*it - arr[r]), minimo);
                freq.insert(arr[r]);

            }
            else
            for(auto &[a, b] : buckets[r])
            {
                if(a == l)
                {
                    ans[b] = minimo;
                    // cout << "Entrou viu" << endl;
                }
            }
        }


    }

    for(auto a : ans)
        cout << a << endl;

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