#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graphType;

int visited[int(1e5) + 1];
int has_debts[int(1e5) + 1];

const int INF = 1e8;

pair<int, int> bfs(graphType & graph)
{
    memset(visited, 0, sizeof(visited));    

    queue<pair<int, pair<int, int>>> order;

    pair<int, int> ans = {INF, INF};

    int n = graph.size() -1;

    order.push({1, {0, 1}});


    while(!order.empty())
    {

        auto curr_node = order.front().first; 
        auto curr_specs = order.front().second; 

        order.pop();

        if(curr_node == n)
        {
            curr_specs.first += has_debts[n];

            if(curr_specs < ans)
            {
                ans = curr_specs;
            }

            continue;
        }


        if(visited[curr_node] !=  0 && visited[curr_node] <= curr_specs.first + 1)
            continue;
        visited[curr_node] = curr_specs.first  + 1;

        for(auto next : graph[curr_node])
        {
            // cout << next << ' ';
            order.push(
                {
                    next, 
                    {curr_specs.first + has_debts[curr_node], curr_specs.second + 1}
                }
            );

        }

        // cout << endl << endl;
        
    }   

    return ans;
}

int solve()
{

    graphType graph;
    memset(has_debts, 0, sizeof(has_debts));

    int n, m, d;
    cin >> n >> m >> d;

    graph.resize(n+1, vector<int>(0, 0));

    while(d--)
    {
        int aux; cin >> aux;

        has_debts[aux] = 1;
    }

    while(m--)
    {
        int v, w; cin >> v >> w;

        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    auto ans = bfs(graph);

    cout << ans.first << ' ' << ans.second - 1<< endl;

    return 0;
}

int main()
{
    solve();

    return 0;
}