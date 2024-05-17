#include<bits/stdc++.h>

#define int long long

using namespace std;

int val[100000];

signed main()
{
    int n, s; cin >> n>> s;


    for(int i = 0; i < n; i++)
    {
        cin >> val[i] ;
    }

    int cont = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n && sum <= s; j++)
        {
            sum += val[j];
            if(sum == s)
                cont++;
        }
    }
    cout << cont << endl;


    return 0;
}