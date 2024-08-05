#include<bits/stdc++.h>

#define int long long

using namespace std;

int n;
int vals[5002];

int dp(int start, int end)
{
    if(start > end)
        return 0;

    int tot = 1e18;

    tot = min(tot, dp(start+1, end-1) + vals[start]);
    tot = min(tot, dp(start+1, end-1) + vals[end]);

    if(start +1 <= end)
        tot = min(tot, dp(start + 2, end) + vals[start]);
    if(end-1 >= start)
        tot = min(tot, dp(start, end-2) + vals[end]);

    return tot;
}

signed main()
{
    cin >> n;

    int tot = 0;

    for(int i =0; i < n; i++)
    {
        cin >> vals[i];
        tot += vals[i];
    }
    
    cout << tot - dp(0, n-1) << endl;

    return 0;
}