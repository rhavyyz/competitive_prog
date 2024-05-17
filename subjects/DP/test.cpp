#include<bits/stdc++.h>

using namespace std;

int prices[int(1e5)+1];
int pages[int(1e5)+1];
int dp[int(1e5)+1];

int n, z;

void solve()
{
    memset(dp, 0, sizeof(dp));


    cin >> n >> z;

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    for(int i = 0; i < n; i++)
        cin >> pages[i];


    int biggest = 0;

    for(int i= 0; i < n; i++)
    {
        for(int x = z; x >=0 ; x--)
        {
            if(x-prices[i] < 0) continue;

            dp[x] = max(dp[x], dp[x-prices[i]] + pages[i]);

            biggest = max(biggest, dp[x-prices[i]]);
            biggest = max(dp[x], biggest);
        }
    }

    cout << biggest << endl;

}

int main()
{
    solve();


    return 0;
}