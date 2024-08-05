#include<bits/stdc++.h>
 
#define int long long 
 
using namespace std;
 
bool memo[(int)1e6];
 
 
signed main()
{
    int n;
    cin >> n;
 
    memset(memo, false, sizeof(memo));
 
    int k = 0;
    memo[0] = true;
 
 
    vector<int> coins(n);
 
    for(auto &a:coins)
        cin >> a;
 
    for(auto coin:coins)
    {
        for(int i = 1e5; i >= coin; i--)
        {
            if(memo[i])
                continue;
            if(memo[i - coin])
            {
                memo[i] = true;
                k++;
            }
        }
    }
 
    cout << k << endl;
    for(int i = 1; i <= 1e5; i++)
    {
        if(memo[i])
            cout << i << ' ';
    }
 
    cout << endl;
 
    return 0;
}