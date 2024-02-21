#include<bits/stdc++.h>

#define int long long

using namespace std;
int msg[1000];
int tot_dif[1000];

int solve()
{
    int n; cin >> n;

    int clock = 0;
    int flag = false;


    while(n--)
    {
        char op; int val; cin >> op >> val;

        if(op == 'T')
        {
            clock += val;
            continue;
            flag = false;
        
        }  
        if(flag)
            clock++;
        else
            flag = true;

        if(op == 'R')
            msg[val] = clock;
        else if(op == 'E')
            tot_dif[val] += clock - msg[val];

    }

    for(int i = 1; i < 101; i++)
    {
        if(tot_dif[i] != 0)
            cout << i << ' ' << tot_dif[i] << endl;
    }

    return 0;
}

signed main()
{

    solve();

    return 0;
}