#include<bits/stdc++.h>

#define int long long

using namespace std;

int num[100001];

int pos = 0;

int solve()
{
    int n; cin >> n;

    while (n--)
    {
        int aux; cin >> aux;

        if(aux == 0)
        {
            pos--;

            if(pos < 0)
                return cout << 0 << endl, 0;
            continue;
        }

        num[pos++] = aux;
    }
    
    int tot = 0;

    for(int i = 0; i < pos; i++)
        tot += num[i];

    return cout << tot << endl, tot;

}

signed main()
{

    solve();

    return 0;
}