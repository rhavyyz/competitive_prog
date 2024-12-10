#include <bits/stdc++.h>

using namespace std;



signed main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<int> values(n);

    for(auto &a : values)
        cin >> a;

    sort(values.begin(), values.end());

    int j = 0;

    int ans = 0;

    for(int i = 0; i <= (int)1e6; i++)
    {
        while(j< n && values[j]< i)
            j++;

        if(n-j >= i)
            ans = i;
    }

    cout << ans << endl;

    return 0;
}

