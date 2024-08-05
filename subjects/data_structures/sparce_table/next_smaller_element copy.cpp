#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int K = 30;

int st[K+1][MAXN];
int arr[MAXN];
int n;

void build()
{
    copy(arr, arr+n, st[0]);

    for(int j = 1; j <= K; j++)
        for(int i = 0; i + ((int)1 << j) <= n; i++)
            st[j][i] = min(st[j-1][i], st[j-1][i+((int)1<<(j-1))]);
}

int log_floor(int x){    return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;    }

int query(int l, int r)
{
    int size = log_floor(r-l + 1);

    return min(st[size][l], st[size][r - ((int)1 << size ) + 1]);
}

int bb(int pos)
{
    int l = pos + 1, r = n-1;

    while(l <= r)
    {
        // cout <<"l r "<< l << ' ' << r << endl;
        int mid =(l+r)/2;
        if(query(pos + 1, mid) < arr[pos])
            r = mid-1;
        else
            l = mid+1;
    }

    return l;
}

signed main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    reverse(arr, arr+n);
    
    build();


    for(int i = n-1; i >= 0; i--)
        cout << n-bb(i) << ' ';

    cout << endl;

    return 0;
}