#include<bits/stdc++.h>

#define int long long

using namespace std;
int msg[1000];
int tot_dif[1000];

int solve()
{
    int n; cin >> n;

    int clock = 0;

    // memset(msg, -1,sizeof(msg));

    while(n--)
    {
        char op; int val; cin >> op >> val;

        if(op == 'T')
        {
            clock += val - 1;
            continue; 
        }  
        clock++;
       
        if(op == 'R')
            msg[val] = clock;
        else if(op == 'E')
        {
            tot_dif[val] += clock - msg[val];
            msg[val] = -1;
        }

    }

    for(int i = 1; i < 101; i++)
    {
        if(tot_dif[i] != 0)
            cout << i << ' ' << (msg[i] == -1 ? tot_dif[i] : -1) << endl;
    }

    return 0;
}

signed main()
{

    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}