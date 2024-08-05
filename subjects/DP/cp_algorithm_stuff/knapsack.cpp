#include<bits/stdc++.h>

using namespace std;
#define int long long


int n;
unordered_map<int, int> dp;

int vals[50];

int solve_dp(int pos, pair<int, int> aux)
{
    auto [choosed, sum] = aux;

    if(sum == 0 && choosed > 0)
        return 1;
    if(sum < 0 || pos >= n)
        return 0;

    return solve_dp(pos+1, {choosed, sum}) + solve_dp(pos+1, {choosed + 1, sum-vals[pos]});
}



int solve()
{
    int t;

    cin >> n >> t;

    for(int i = 0; i < n; i++)
        cin >> vals[i];





    cout << dp [t] << endl;
    return 0;
}

signed main()
{
    solve();

    return 0;
}