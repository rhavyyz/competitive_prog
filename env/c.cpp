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

int n, m; 
int mat[201][201];
int visited[201][201];

bool check(int i, int j)
{
    return i>=0 && i < n && j >= 0 && j < m;
}

struct Node
{
    int color;
    int size;
    set<int> near;
};

vector<Node> graph;
vector<set<int>> tested_colors;

vector<pair<int, int>> moves = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int size_with(int i,int color, int parent)
{
    if(i >= graph.size() && i <0)
        return 0;

    int tot = graph[i].size;
    if(graph[i].color != 0 && graph[i].color != color)
    {
        return 0;
    }

    if(graph[i].color == 0)
    {
        if(tested_colors[i].count(color) )
            return n*m*10;
        tested_colors[i].insert(color);
    }

    for(int next : graph[i].near)
    {
        if(next != parent)
            tot+= size_with(next, color, i); 
    }

    return tot;

}
int get_min_from(int i)
{
    int res = n*m*10;
    for(int color = 1; color <=40000; color++)
    {
        res = min(size_with(i, color, i), res);
        if(res == graph[i].size)
            break;
    }
    return res;
}

Node dfs(int i, int j, int color, int id)
{

    if(!check(i, j))
        return {color, 0, {}};

    if(color != mat[i][j] || visited[i][j] != -1)
        return {color, 0, {visited[i][j]}};
    
    visited[i][j] = id;
    int qtd = 1;

    set<int> near;

    for(auto [y, x] : moves)
    {
        auto aux = dfs(i+y, x+j, color, id);
        qtd+=aux.size;

        if(color == 0)
        {
            for (auto next : aux.near)
            {
                if(next!= id)
                    near.insert(next);
            }
        }
    }

    return {color, qtd, near};
}



int solve(){
    

    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j  < m; j++)
        {
            cin >> mat[i][j];
            visited[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j  < m; j++)
        {
            if(visited[i][j] == -1 && mat[i][j] != 0)
            {
                graph.push_back(dfs(i, j, mat[i][j], graph.size()));
                for(int e : graph.back().near)
                {
                    graph[e].near.insert(graph.size()-1);
                }
            }
        }
    }

    int colored_ones = graph.size();



    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j  < m; j++)
        {
            if(visited[i][j] == -1 && mat[i][j] == 0)
            {
                graph.push_back(dfs(i, j, mat[i][j], graph.size()));
                for(int e : graph.back().near)
                {
                    graph[e].near.insert(graph.size()-1);
                }
            }
        }
    }

    int min_colored = m*n +1000;

    for(int i = 0; i < colored_ones; i++)
        min_colored=min(graph[i].size, min_colored);
    int min_spaces = m*n +1000;
    for(int i = colored_ones; i < graph.size(); i++)
        min_spaces=min(graph[i].size, min_spaces);

    if(min_colored <= min_spaces)
        return cout << min_colored << endl , 0;


    int actual_min_spaces = m*n +1000;

    tested_colors.resize(graph.size());

    for(int i = colored_ones; i < graph.size(); i++)
        actual_min_spaces=get_min_from(i);

    cout << min(actual_min_spaces, min_colored) << endl;

    return 0;
}
 
signed main()
{
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;    

    while(t--)
        solve();
    
    return 0;
}