#include<bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int memo[502][125251];
 
const int MOD =  1e9 +7;
 
int half_tot = 0;
int n;
int dp(int val, int res)
{
    if(res == half_tot)
        return 1;
    if(val > n || res < 0)
        return 0;
 
    if(memo[val][res] != -1)
        return memo[val][res];
 
    return memo[val][res] = (dp(val+1, res) + dp(val+1, res - val)) % MOD;
}
 
int fast_pow(int a, int b)
{
    if(b == 0)
        return 1;
 
    int half = fast_pow(a, b/2);
 
    int tot = (half * half)%MOD;
    if(b%2)
        tot = (tot * a)%MOD;
 
    return tot;
}
 
signed main()
{
    cin >>n;
 
    for(int i = 1; i <= n; i++)
        memset(memo[i], -1, sizeof(memo[i]));
 
    int tot = ((n+1)*n)/2;
    if(tot%2)
        return cout << 0 << endl, 0; 
 
    half_tot = tot/2;
 
    cout << (dp(1, tot) * fast_pow(2, MOD-2)) % MOD << endl;
 
    return 0;
}