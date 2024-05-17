// https://codeforces.com/contest/1969/problem/C

#include <bits/stdc++.h>

using namespace std;

int n, k;
int values[(int)1e6];

int memo[(int)1e6][11];

const int INF = 1e9;

void dp()
{
    for(int i = 0; i < n; i++)
    {
        int minimum = INF;
        for(int x=0; x <= k && i-x >= 0; x++)
        {
            memo[i][x] = INF;
            minimum = min(minimum, values[i-x]);
            memo[i][x] = min(memo[i][x], memo[i-x][k-x]+ (x+1)*minimum );
        }
    }

    int minimun = INF;
    for(int x=0; x <= k; x++)
    {
        minimun = min(minimun, memo[n-1][x]);
    }

    cout << minimun << endl;

}

void solve()
{
    cin >> n >> k;

    for(int i=0; i < n; i++)
        cin >> values[i];

    dp();

}

signed main()
{
    
    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}