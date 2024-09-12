#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph_type;
typedef vector<set<int>> graph_set_type;

typedef pair<int, int> edge_type;

graph_type g;

vector<int> low, tin, visited;
vector<edge_type> bridges;

int cont = 0;

graph_set_type components;

stack<int> vertex_stack;
vector<int> component_of;

void dfs(int v, int p = -1)
{
    low[v] = tin[v] = cont++;
    visited[v] = 1;
    vertex_stack.push(v);

    for(int to : g[v])
    {
        if(to == p)
            continue;

        if (visited[to])
        {
            if(p != to)
                low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);

            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
            {
                bridges.push_back({v, to});

                int vertex;
                do {
                    vertex = vertex_stack.top();
                    component_of[vertex] = components.size();
                    vertex_stack.pop();

                    components.resize(components.size() + 1);

                } while(vertex != v);

            }
        }
    }
}

void dfs_to_tree(int v)
{
    if(visited[v] != 0)
        return;

    visited[v] = 1;

    for (int to : g[v])
    {
        if(component_of[to] != component_of[v])
        {
            components[component_of[to]].insert(component_of[v]);
            components[component_of[v]].insert(component_of[to]);
        }
    }
    
}

int bridge_tree()
{
    visited.resize(g.size(), 0);
    tin.resize(g.size());
    low.resize(g.size());
    bridges.clear();
    component_of.resize(g.size());


    for(int i =1; i <g.size(); i++)
    {
        if(!visited[i])
            dfs(i);
    }

    fill(visited.begin(), visited.end(), 0);

    for(int i =1; i <g.size(); i++)
    {
        if(!visited[i])
            dfs_to_tree(i);
    }



    return 0;

}

int main()
{


    cout << visited[99] << endl;

    return 0;
}