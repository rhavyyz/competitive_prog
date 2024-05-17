#include<bits/stdc++.h>

using namespace std;

char grid[1000][1000];
int n, m;

bool check(int y, int x)
{
    return y >= 0 && y < n && x>= 0 && x < m;
}

vector<pair<int ,int>> moves = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool dfs(int y, int x)
{
    if(grid[y][x] == '#')
        return false;

    // else seria caso grid y x == '.'
    grid[y][x] = '#';
    
    for(auto [diff_y, diff_x] : moves)
    {
        if(check(diff_y+y, diff_x+x))
        {

            dfs(diff_y+y, diff_x+x);
        }
    }

    return true;
}

int main()
{
    cin >> n >> m;

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)  
            cin >> grid[y][x];
    }

    int tot = 0;

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)  
        {
            if(dfs(y, x))
                tot++;
        }
    }

    cout << tot << endl;

    return 0;
}