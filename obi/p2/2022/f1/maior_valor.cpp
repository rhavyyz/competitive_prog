#include<bits/stdc++.h>

#define int long long

using namespace std;

int sum_of_digits(int n)
{
    int res = 0;
    while(n)
    {
        res += n%10;
    
        n/=10;
    }

    return res;
}

signed main()
{

    int ans = -1;

    int l, r, v; cin >> l >> r >> v;

    for(int i = r; i >= l; i--)
    {

        if(sum_of_digits(i)==v)
        {
            ans = i;
            break;
        }


    }

    cout << ans << endl;

    return 0;
}