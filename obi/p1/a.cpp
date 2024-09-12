#include<bits/stdc++.h>

using namespace std;

vector<int> coins;


int memo[(int)1e6 + 10][100];
const int INF = 1e15;

int dp(int w, int pos)
{
    if(w == 0)
        return 1; 
    if(pos >= coins.size())
        return 0;

    if(memo[w][pos] != -1)
        return memo[w][pos];
    int tot = 0;


    tot += dp(w, pos + 1);
    tot += dp(w-coins[pos], pos);
    tot %= (int)1e9 + 7;


    return memo[w][pos] = tot;

}

signed main()
{

    int n, w; cin >> n >> w;

    for(int i = 0; i<= w; i++)
    {
        fill(memo[i] , memo[i] + 100 , -1);
    }


    dp(w, 0);
    // int n, w; cin >> n >> w;

    // coins.resize(n);

    // while(n--)
    //     cin >> coins[n];

    // vector<long long> memo(w+1, INF);
    // memo[0] = 0;

    // for(int i = 1; i <= w; i++)
    // {
    //     for(int coin : coins)
    //     {
    //         if(0 <= i-coin)
    //             memo[i] = min(memo[i], memo[i-coin] + 1);
    //     }
    // }

    return 0;
}