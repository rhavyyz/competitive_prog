#include<bits/stdc++.h>

#define int long long 

using namespace std;

int n, m;
string a, b;

int memo[5001][5001];

int dp(int p1, int p2)
{
    if(p2 == m)
        return n - p1;
    if(p1 == n)
        return m - p2;
    
    if(memo[p1][p2] != -1)
        return memo[p1][p2];
 
    if(a[p1] == b[p2])
        return memo[p1][p2] = dp(p1+1, p2+1);
    else
        return memo[p1][p2] = min(min(dp(p1+1, p2), dp(p1, p2+1)), dp(p1 + 1, p2 + 1)) + 1;
}

signed main()
{
    cin >> a >> b;
    if(a.size() < b.size())
        swap(a, b);

    n = a.size();
    m = b.size();

    for(int i = 0; i  <= n; i++)
        memset(memo[i], -1, sizeof(int) * (m+1));

    cout << dp(0, 0) << endl;


    return 0;
}