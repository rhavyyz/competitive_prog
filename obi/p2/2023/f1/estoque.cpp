#include<bits/stdc++.h>

using namespace std;

int adj[501][501];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;cin >> n >> m;
 
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
            cin >> adj[y][x];
    }

    int cont = 0;

    int t; cin >> t;

    while(t--)
    {
        int y, x; cin >> y >> x;

        y--;x--;

        cont += adj[y][x]-- ? 1 : 0;
    }


    cout << cont << endl;

    return 0;
}