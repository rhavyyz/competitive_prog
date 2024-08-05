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

struct state
{
    int rest_time, switched_time;
    bool on;
};


int solve()
{

    int n, k; cin >> n >> k;

    vector<int> values(k, -1);

    bool ok = true;

    int maior = -1;

    for(int i = 0; i < n; i++)
    {
        int aux; cin >> aux;
        int mod = aux % k;



        if(values[mod] ==  -1)
            values[mod] = aux;
        else if((values[mod]/k)%2 == (aux/k) % 2) 
            values[mod] = max(aux, values[mod]);
        else
            ok = false;
        maior = max(maior, values[mod]);
    }   

    if(!ok)
        return cout << -1 << endl, 0;

    set<int> s;
    for(int &value : values)
    {
        if(value == maior || value == -1)
            continue;
        
        //  cout << value << ' ' << ref << ' ';
        value += ((maior - value)/(2*k)) * (k*2);

        s.insert(value);
    }

    int ref = maior + k*4;

    while(true)
    {
        int menor = *s.begin();
        if(menor + k >= maior)
            return cout << maior << endl, 0;
        
        s.erase(menor);

        s.insert(menor + 2* k);

        maior = max(menor + 2*k  , maior);

        if(menor + 2* k == ref)
            break;
    }

    cout << -1 << endl;

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;    

    while(t--)
    {
        solve();
    } 
    

    return 0;
}