#include<bits/stdc++.h>

using namespace std;

char grid[1000][1000];
pair<char,pair<int, int>> parent[1000][1000];
int n, m;

bool check(int y, int x)
{
    return y >= 0 && y < n && x>= 0 && x < m;
}

vector<pair<char ,pair<int , int>>> moves = {
    {'D', {1, 0}},
    {'U',{-1, 0}},
    {'R',{0, 1}},
    {'L', {0, -1}}
};

void bfs(int start_y, int start_x)
{
    queue<pair<int, int>> order;
    order.push({start_y, start_x});

    while(!order.empty())
    {
        auto [y, x] = order.front();
        order.pop();


        if(grid[y][x] == '#')
            continue;

        // else seria caso grid y x == '.'
        grid[y][x] = '#';
        
        for(auto [direction, diff] : moves)
        {
            auto [diff_y, diff_x] = diff;

            if(check(diff_y+y, diff_x+x))
            {
                if( grid[diff_y+y][diff_x+x] != '#' )
                {
                    order.push({diff_y+y, diff_x+x});
                    parent[diff_y+y][diff_x+x] = {direction, {y, x}};
                }
            }
        }
    }
}

bool dfs(int y, int x)
{
    if(grid[y][x] == '#')
        return false;

    // else seria caso grid y x == '.'
    grid[y][x] = '#';
    
    for(auto [direction, diff] : moves)
    {
        auto [diff_y, diff_x] = diff;

        if(check(diff_y+y, diff_x+x))
        {
            if(dfs(diff_y+y, diff_x+x))
                parent[diff_y+y][diff_x+x] = {direction, {y, x}};
        }
    }

    return true;
}

int main()
{
    cin >> n >> m;

    int start_y, start_x;
    int end_y, end_x;

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)  
        {
            cin >> grid[y][x];
            if(grid[y][x] == 'A')
            {
                start_y = y;
                start_x = x;
            }
            else if(grid[y][x] == 'B')
            {
                end_y=y;
                end_x = x;
            }
        }
    }

    bfs(start_y, start_x);

    if(grid[end_y][end_x] != '#')
        return cout << "NO" << endl, 0;
    
    cout << "YES" << endl;
    
    string path = "";
    pair<int, int> curr = {end_y, end_x};

    while(curr != make_pair(start_y, start_x))
    {
        path += parent[curr.first][curr.second].first;

        curr = parent[curr.first][curr.second].second;
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;

    cout << path << endl;

    return 0;
}