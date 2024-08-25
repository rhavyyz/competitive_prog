#include<bits/stdc++.h>

using namespace std;

int n, m;
char mat[1001][1001];
pair<char, pair<int, int>> parents[1001][1001];

vector<pair<char, pair<int, int>>> moves =
{
    {'D' ,{1, 0}},
    {'U' ,{-1, 0}},
    {'L' ,{0, -1}},
    {'R' ,{0, 1}}
};


void bfs(int y, int x)
{
    queue<pair<pair<int ,int>, 
          pair<char, pair<int, int>>>> ordem;

    ordem.push({
        {y, x},
        {'\0', {-2, -2}}
    });

    while(!ordem.empty())
    {
        auto [cord, parent] = ordem.front();

        ordem.pop();

        if(mat[cord.first][cord.second] == '#')
            continue;

        if(parents[cord.first][cord.second].second != make_pair(-1, -1))
            continue;
        parents[cord.first][cord.second] = parent;

        for(auto [move_direction, move] : moves)
        {
            ordem.push(
                {
                    {move.first + cord.first, move.second + cord.second},
                    {move_direction, cord}
                }
            );
        }

    }


}

signed main()
{
    cin >> n >> m;

    pair<int, int> a_cord, b_cord;

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 'A')
                a_cord = {i, j};

            if(mat[i][j] == 'B')
                b_cord = {i, j};

            parents[i][j].second = {-1,-1};
        }
    }


    bfs(a_cord.first, a_cord.second);

    vector<char> path;

    if(parents[b_cord.first][b_cord.second].second == make_pair(-1, -1))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    while (b_cord != make_pair(-2, -2))
    {
        path.push_back(parents[b_cord.first][b_cord.second].first);
        b_cord = parents[b_cord.first][b_cord.second].second;
    }
    cout << path.size() << endl;

    reverse(path.begin(), path.end());

    for(char c : path)
        cout << c ;
    cout << endl;
    


    return 0;
}