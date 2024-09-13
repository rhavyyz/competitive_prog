#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(A) A.begin(), A.end()


typedef vector<vector<pair<int, int>>> graph_type;


graph_type g;
vector<int> payment;
vector<map<int, int>> visited;

int solve()
{
    int n, m; cin >> n >> m;

    vector<int> cars(n), mec(m), qtd(m, 0);

    for(auto & a: cars)
        cin >> a;

    cout << endl;

    for(auto & a: mec)
        cin >> a;

    cout << endl;

    sort(all(cars));
    sort(all(mec));

    priority_queue<pair<int, int>> q;

    for(int i = 0; i < m; i++)
        q.push({0, i});

    int ans = 0;

    for(int i = n-1; i >= 0; i--)
    {
        auto [v, p] = q.top(); q.pop();

        v *= -cars[i]; 
        ans += v;
        qtd[p]++;

        q.push({-qtd[p]*mec[p], p});
    }

    
    cout << ans << endl;


    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();



    return 0;
}