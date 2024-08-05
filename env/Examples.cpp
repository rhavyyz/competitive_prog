#include<bits/stdc++.h>

using namespace std;

#define int long long

int memo[500];

int items[(int)1e5];
int weights[(int)1e5];
int n, w;

int dp[100][10001];

// qtd_estados * tempo_cada_estado

// n * W;


int check_dp(int i, int peso)
{
    dp[0][0] = 0;
    // for(int i )


    for(int i = 0; i < n; i++)
    {
        for(int peso = w; peso >= 0; peso--)
        {
            if(peso-weights[i] >= 0)
            {
                // dp[i]
            }
        }
    }

}

signed main()
{
    cin >> n >> w;

    for(int i = 0; i < n; i++)
        cin >> items[i] >> weights[i];

    cout << check_dp(0, w) << endl;

    return 0;
}

1 2
3 1 

dp[4] = 3;