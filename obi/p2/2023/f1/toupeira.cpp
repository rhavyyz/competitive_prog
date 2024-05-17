#include<bits/stdc++.h>

using namespace std;

int adj[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;cin >> n >> m;

    while(m--)
    {
        int aux1, aux2; cin >> aux1 >> aux2;

        adj[aux1][aux2] = 1;
        adj[aux2][aux1] = 1;
    }

    // int cont = 0;
    int t; cin >> t;

    int cont = 0;


    while(t--)
    {
        int z, last; cin >> z >> last;

        bool ok = true;

        for(int i = 1; i < z; i++)
        {
            int room; cin >> room;

            if( last != room &&  !adj[last][room])
            {
                ok = false;
            }
            last = room;
        }

        if(ok)
            cont++;
    }

    cout << cont << endl;

    return 0;
}