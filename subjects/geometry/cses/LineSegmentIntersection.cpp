#include<bits/stdc++.h>

using namespace std;

struct point2d
{
    int x, y;

    int operator^(point2d p)
    {
        return (x * p.y) - (p.x * y);
    }

    int operator*(point2d p)
    {
        return x * p.x + y*p.y;
    }

    point2d operator-(point2d p)
    {
        return {x - p.x, y - p.y};
    }

    point2d operator+(point2d p)
    {
        return {x + p.x, y + p.y};
    }

    int orientation(point2d p2, point2d p3)
    {
        int ans = (p2.y-y)* (p3.x - p2.x) - (p3.y-p2.y)* (p2.x - x);
        return ans/abs(ans);
    }
};

int solve()
{



    return 0;
}

signed main()
{
    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}