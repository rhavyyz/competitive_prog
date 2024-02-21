#include<bits/stdc++.h>



using namespace std;

typedef vector<vector<int>> graph_type;
#define endl '\n'

void print_v(vector<int> &v, string name = "")
{
    cout << name << '\t';
    for(int el : v)
        cout << el << " ";
    
    cout << endl;
}
void print_g(graph_type &g, string name = "")
{
    cout << "\n" << name << '\n';
    for(int i = 1; i < g.size(); i++)
    {
        cout << i << ": ";
        print_v(g[i]);
    }
}

vector<int> visited1;
graph_type g1;
vector<int> order;
int dfs1(int u)
{
    visited1[u] = 1;

    for(int to : g1[u])
    {
        if(visited1[to] != 0)
            continue;
        
        dfs1(to);
    }

    order.emplace_back(u);  
    return 0;
}
vector<int> visited2;
graph_type g2;
int n_comp =1;

graph_type components;
graph_type condensed;

int dfs2(int u)
{
    cout << "started " << u << endl;

    visited2[u] = n_comp;

    for(int to : g2[u])
    {
        if(visited2[to] != 0)
        {
            if(visited2[to] != n_comp)
                condensed[n_comp].emplace_back(visited2[to]);
            continue;
        }
        cout << "Going to " << to << " from " << u << endl;
        dfs2(to);
    }

    components[u].emplace_back(n_comp);    

    cout << "Ended " << u << endl;

    return 0;
}

void set_graphs()
{
    int n, m;
    cin >> n >> m;
    g1.resize(n+1);
    g2.resize(n+1);
    condensed.resize(n+1);
    visited1.resize(n + 1, 0);
    visited2.resize(n + 1, 0);
    components.resize(n + 1);

    while(m--)
    {
        int a, b; cin >> a >> b;

        g1[a].emplace_back(b);
        g2[b].emplace_back(a);
    }

    print_g(g1, "g1");
    print_g(g2, "g2");
}

void kosaraju()
{
    set_graphs();
    cout << endl;

    for(int i = 1; i < g1.size(); i++)
    {
        if(!visited1[i])
            dfs1(i);
    }
    cout << endl;

    print_v(order, "order");

    reverse(order.begin(), order.end());

    print_v(order, "reversed order");

    cout << endl;

    for(int vertex : order)
    {  
        if(!visited2[vertex])
        {
            dfs2(vertex);
            n_comp++;

        }
    }
    cout << endl;

    print_v(visited2, "visited2");
    cout << endl;

    print_g(condensed, "condensed");
    cout << endl;

    print_g(components, "components");
    cout << endl << "n_comp " << n_comp  << endl;
}

int main()
{
    kosaraju();

    return 0;
}