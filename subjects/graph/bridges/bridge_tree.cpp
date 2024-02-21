#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph_type;
typedef pair<int, int> edge_type;

graph_type g;

vector<int> low, tin, visited;
vector<edge_type> bridges;

int cont = 0;

graph_type components;
set<int> order;

void dfs(int v, int p = -1)
{
    low[v] = tin[v] = cont++;
    visited[v] = 1;

    for(int to : g[v])
    {
        if(to == p)
            continue;

        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else
        {
            dfs(to, v);

            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
                bridges.push_back({v, to});
        }


    }
}

int bridge_tree()
{
    visited.assign(g.size(), 0);
    tin.resize(g.size());
    low.resize(g.size());
    bridges.clear();


    for(int i =1; i <g.size(); i++)
    {
        if(!visited[i])
            dfs(i);
    }


    return 0;

}

int main()
{


    cout << visited[99] << endl;

    return 0;
}