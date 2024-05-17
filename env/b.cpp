#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define IOS ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false); 
#define endl '\n'
#define bug(x)  cerr << #x << " >>> " << x << endl;
#define all(A) A.begin(), A.end()

void solve()
{
    
    int n, k; cin >> n >> k;

    if(n == 1)
    {
        cout << k << endl;

        return;
    }

    int top = ((int)1) << 33;

    while(top > k+1)
        top/=2;

    cout << signed(top-1) << ' ' << signed(k-top + 1) << " ";
    for(int i = 1; i < n-2; i++)
        cout << signed(0) << ' ';
    cout << endl;

}

 
signed main()
{
    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    } 
    
    return 0;
}


