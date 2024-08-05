#include<bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    int n; cin >> n;

    vector<int> vals(n);

    for(auto & a : vals)
        cin >> a;

    vector<int> ans;
    ans.push_back(vals[0]);

    for(int i =1 ; i < n; i++)
    {
        if(ans.back() < vals[i])
        {
            ans.push_back(vals[i]);
            continue;
        }

    
        *lower_bound(ans.begin(), ans.end(), vals[i]) = vals[i];
    } 

    cout << ans.size() << endl;


    return 0;
}