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

int tree[2*N], values[N];

int query(int node, int l, int r, int begin, int end)
{
    if(l > end || r < begin )
        return irrelevant;
    if(l >= begin && r <= end)
        return tree[node];

    int mid = (l + r)/2;

    return operation(
            query(node*2 + 1, l, mid, begin, end),
            query(node*2 + 2, mid + 1, r, begin, end)
        );
}

int update(int node, int l, int r, int pos, int value)
{
    if(pos < l or pos > r)
        return tree[node];

    if(l==r && pos == r)
        return tree[node] = value;

    int mid = (l + r) / 2;
    return tree[node] = operation(
        update(node * 2 + 1, l, mid, pos, value),
        update(node * 2 + 2, mid + 1, r, pos, value)
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

    for(int i = 0;i < q; i++)
    {
        int  a, b; cin >> a >> b;
        
        // if(op == 1)
        // {   
        //     update(0, 0, n-1, a-1, b);
        //     continue;
        // }
        
        a--;b--;

        cout << query(0, 0, n-1, a, b) << endl;
    }

    return 0;
}