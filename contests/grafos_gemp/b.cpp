#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graphType;

graphType graph;
bool visited[(int)1e5 + 1];

int n, m;

bool dfs(int v)
{
    if(visited[v])
        return false;

    visited[v] = true;

    for(auto next : graph[v])
        dfs(next);// pilha add

    return true;
}

int main()
{
    cin >> n >> m;
    graph.resize(n+1);

    for(int i = 0; i < m; i++)
    {
        int v, w; cin >> v >> w;

        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    dfs(1);

    vector<pair<int, int>> edges;

    for(int i = 2; i <= n; i++)
    {
        if(dfs(i))
            edges.push_back({1, i});
    }


    cout << edges.size() << endl;
    for(auto [v, w] : edges)
        cout << v << ' ' << w << endl;

    return 0;
}