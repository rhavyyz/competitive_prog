#include<bits/stdc++.h>

using namespace std;

int cont = 0;

int n;
int points_to[101];
int times[101];
// int visited[101];


void dfs(int i, int begin = -1)
{
    if(i == begin)
        return;
    if(begin == -1)
        begin = i;

    
    cout << i << ' '; 

    dfs(points_to[i], begin);
}

void solve()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> points_to[i];

    for(int i = 1;i <= n; i++)
    {
        dfs(i);
        cout << endl;
    }
}

int main()
{
    int t; cin >> t;

    while(t--)
        solve();


    return 0;
}