#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef vector<vector<pair<int, int>>> graph_type;


graph_type g;
vector<int> payment;
vector<map<int, int>> visited;

int shortest_path(int v, int w)
{
    set<pair<int, pair<int, int>>> order;

    order.insert({0, {v , 0}});

    while(!order.empty())
    {
        auto [dist, point] = *order.begin();
        auto [vertex, station] = point;
        order.erase(order.begin());
    
        // cout << dist << ' ' << vertex << ' ' << station << endl;


        if(!visited[vertex].count(station))
            visited[vertex][station] = LLONG_MAX;

        if(visited[vertex][station] <= dist)
            continue;
        
        visited[vertex][station] = dist;

        for(auto [next, station_of] : g[vertex])
        {
            int dif = 0;
            if(station_of != station)
                dif = payment[station_of];

            order.insert({dist + dif, {next, station_of}});
        }
    }

    int m = LLONG_MAX;

    for(auto [t, a] : visited[w])
        m = min(m, a);

    if(m != LLONG_MAX)
        return m;
    
    return -1;
}

int solve()
{

    int n, m, k; cin >> n >> m >> k;

    payment.resize(k+1);
    g.resize(n+1);
    visited.resize(n+1);
    for(int i = 1; i <= k; i++)
        cin >> payment[i];

    while(m--)
    {
        int v, w , c; cin >> v >> w >> c;

        g[v].push_back({w, c});
        g[w].push_back({v, c});
    }

    int v, w; cin >> v >> w;

    // cout << "started" << endl;
    cout << shortest_path(v, w) << endl;

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