
#include<bits/stdc++.h>

#define int long long 

using namespace std;

int memo[502][502];

int dp(int l, int a)
{
    if(l == a)
        return 0;

    if(a > l)
        swap(l, a);

    if(memo[l][a] != -1)
        return memo[l][a];

    int res = 1e18;


    for(int i = 1; i < l; i++)
        res = min(res,  dp(i, a) + dp(l-i, a) + 1);

    for(int i = 1; i < a; i++)
        res = min(res,  dp(l, i) + dp(l, a-i) + 1);

    return memo[l][a] = res;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= max(n, m); i++)
    {
        for(int j = 0; j <= max(n, m); j++)
        {
            memo[i][j] = -1;
            // cout << i << j << ':' << memo[i][j] << ' ';
        }

        // cout << endl;
    }

    cout << dp(n , m) << endl;


    return 0;
}