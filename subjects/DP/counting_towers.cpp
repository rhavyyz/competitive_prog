#include<bits/stdc++.h>

#define int long long
#define all(A) A.begin(), A.end()

using namespace std;

int memo[(int)1e6 + 10][2];

int const MOD = ((int)1e9) + 7;

int dp(int h, bool has_top)
{
    if(h == 0)
        return 1;

    int left = has_top ? 1 : 0;

    if(memo[h][left] != -1 )
        return memo[h][left];

    int tot = 0;

    int false_number = 1;
    int true_number = 4;

    if(!has_top)
    {
        false_number = 2;
        true_number = 1;    
    }

    tot += ((dp(h-1, true) * true_number) % MOD) + ((dp(h-1, false) * false_number) %MOD);

    return memo[h][left] = tot%MOD;

}

signed main()
{
    int t; cin >> t;

    for(int i = 0; i <= 1e6 + 2; i++)
    {
        memo[i][0] = memo[i][1] = -1;
    }


    while(t--)
    {

        int n; cin >> n;

        cout << (dp(n-1, false) + dp(n-1, true)) %MOD << endl;

    }




    return 0;
}