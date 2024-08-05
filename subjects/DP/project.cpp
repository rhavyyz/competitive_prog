#include<bits/stdc++.h>

#define int long long

using namespace std;

int n;

vector<pair<int, pair<int, int>>> bosta;
vector<int> start, fim , value;
vector<int> checks;

int dp(int i)
{

    // cout <<i << endl;
    if(i >= n)
        return 0;
    if(checks[i] != -1)
        return checks[i];

    int next = upper_bound(start.begin() + i, start.end(), fim[i]) - start.begin();

    return  checks[i] = max(dp(next)  + value[i],  dp(i+1));
}

signed main()
{
    cin >> n;

    bosta.resize(n);
    checks.resize(n, -1);
    start.resize(n);
    fim.resize(n);
    value.resize(n);

    // cout << "bosta1" << endl;


    for(int i = 0; i < n; i++)
    {
        int a, b, c;

        cin >> bosta[i].first >> bosta[i].second.first >> bosta[i].second.second;
    }

    // cout << "bosta2" << endl;

    sort(bosta.begin(), bosta.end());
    for(int i = 0; i < n; i++)
    {
        start[i] = bosta[i].first;
        fim[i] = bosta[i].second.first;
        value[i] = bosta[i].second.second;
    } 



    // cout << "bosta3" << endl;
    cout << dp(0) << endl;

    return 0;
}