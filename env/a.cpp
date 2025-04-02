#include <bits/stdc++.h>

using namespace std;

#define int long long
#define map unordered_map
#define all(A) A.begin(), A.end()

#define bug(x) cout << #x << ' ' << x << endl

int solve()
{
    int n, m, k;

    cin >> n >> m >> k;

    int l= 1, r = m+1;

    while(l < r)
    {
        int mid = (l+r)/2;

        int tot = (m/ (mid+1) * mid) + m % (mid+1);
        if(tot * n  >= k )
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    
    if(((m/ (l+1) * l) + m % (l+1)) * n  >= k )
        l--;

    while(((m/ (l+1) * l) + m % (l+1)) * n < k)
        l++;

    cout << l << endl;

    return 1;
}

signed main()
{

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    // cout << gate(2, '*').operate(1) << endl;
}
