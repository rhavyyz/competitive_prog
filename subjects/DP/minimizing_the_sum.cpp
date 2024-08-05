#include <bits/stdc++.h>
using namespace std;


string t1, t2;
int memo[1001][1001];
int n, m;

int dp(int i, int j)
{
    if(i >= n || j >= m)
        return 0;
    if(memo[i][j]!= -1)
        return memo[i][j];
    int poss = -1;
    if(t1[i] == t2[j])
        poss= max(poss, 1 + dp(i+1, j+1));
    else
    {
        poss= max(poss, dp(i+1, j));
        poss= max(poss, dp(i, j+1));
    }

    return memo[i][j] = poss;
}

int main()
{
    cin >> t1 >> t2;
    n = t1.size();
    m = t2.size();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            memo[i][j] = -1;

    int aux = dp(0,0);

    cout << aux << endl;

    return 0;
}