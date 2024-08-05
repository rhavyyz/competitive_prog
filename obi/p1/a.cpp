#include<bits/stdc++.h>

using namespace std;

signed main()
{
    int n, x; cin >> n >> x;

    map<int,int> occur;

    occur[0] = 1;

    int sum = 0;

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int val; cin >> val;
        sum += val;
    
        if(occur.count(sum - x))
        {
            res += occur[sum-x];
        }

        occur[sum]++;
    }

    cout << res << endl;

}