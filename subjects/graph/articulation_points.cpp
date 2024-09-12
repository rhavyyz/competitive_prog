#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph_type;
typedef pair<int, int> edge_type;

graph_type g;

vector<int> low, tin, visited;
vector<int> cut_edges;

int cont = 0;

void dfs(int v, int p = -1)
{
    low[v] = tin[v] = cont++;
    visited[v] = 1;

    int children_qtd = 0;
    for(int to : g[v])
    {
        if(to == p)
            continue;


        // If backedge and edges 
        if (visited[to])
        {
            // To ignore the parent edge
            if(p != to)
            low[v] = min(low[v], tin[to]);
        }
        // If regular edge
        else
        {
            children_qtd++;
            dfs(to, v);

            // low is going to be the lowest between the current vertex and its children
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] && p != -1)
                cut_edges.push_back(v);
        }


    }

    if(p == -1 && children_qtd > 1)
        cut_edges.push_back(v);

}

int find_briges()
{
    visited.assign(g.size(), 0);
    tin.resize(g.size());
    low.resize(g.size());
    cut_edges.clear();

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