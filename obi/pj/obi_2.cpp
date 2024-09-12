#include<bits/stdc++.h>

using namespace std;
int n;
char f;
char mat[500][500];

vector<pair<int, int>> moves ={
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool check(int y, int x)
{
    return y >= 0 && y <n && x >=0 && x < n;
}

void dfs(int y, int x)
{
    if(!check(y, x) || mat[y][x] == '*' || mat[y][x] > f)
        return;

    mat[y][x] = '*';

    for(auto move : moves)
        dfs(y + move.first, x+ move.second);
}

int main() {

    cin >> n >> f;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
            cin >> mat[i][j];
    }

    dfs(0, 0);

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
            cout << mat[i][j];
        cout << endl;
    }


    return 0;
}

