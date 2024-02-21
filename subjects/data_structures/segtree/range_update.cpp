#include <bits/stdc++.h>

using namespace std;

#define N 300000
#define irrelevant 0
#define endl '\n'
#define int long long

int operation(int left, int right)
{
    return left ^ right;
}

int tree[2*N], lazy[2*N], values[N];

int query(int node, int l, int r, int begin, int end)
{
    int size = r-l+1;

    if(lazy[node])
    {
        tree[node] += size * lazy[node];

        if(size > 1)
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
    
        lazy[node] = 0;
    }

    if(l > end || r < begin )
        return irrelevant;
 

    if(l >= begin && r <= end)
        return tree[node];

    int mid = (l + r)/2;

    return operation(
            query(node*2 + 1, l, mid, begin, end),
            query(node*2 + 2, mid + 1, r, begin, end)
        );

    return 0;
}

int range_update(int node, int l, int r, int begin, int end, int value)
{
    int size = r-l+1;

    if(lazy[node])
    {
        tree[node] += size * lazy[node];

        if(size > 1)
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
    
        lazy[node] = 0;
    }  

    if(l > end || r < begin)
        return tree[node];
    
    if(l >=begin && r <= end)
    {
        if(size > 1)
        {
            lazy[node * 2 + 1] += value;
            lazy[node * 2 + 2] += value;
        }

        return tree[node] += size * value;
    }

    int mid = (l+r)/2;

    return tree[node] = operation(
        range_update(node*2+1, l, mid, begin, end, value),
        range_update(node*2+2, mid+1, r, begin, end, value)
    );
}

int build(int node, int l, int r)
{
    if(l > r) return irrelevant;
    if(l == r)
        return tree[node] = values[l];
    int mid = (l+r)/2;
    
    return tree[node] = operation(
            build(node*2 + 1, l, mid),
            build(node*2 + 2, mid + 1, r)
        );
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, q; cin >> n >> q;

    for(int i =0; i < n; i++)
    {
        cin >> values[i];
    }

    build(0, 0, n-1);
    memset(lazy, 0, sizeof(int) * 2*n );


    for(int i = 0;i < q; i++)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int a, b, u; cin >> a >> b >> u;
            a--;b--;
            range_update(0, 0, n-1, a, b, u);
            continue;
        }
        int k; cin >> k;
        k--;

        cout << query(0, 0, n-1, k, k) << endl;
    }

    return 0;
}