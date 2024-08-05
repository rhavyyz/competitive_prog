#include<bits/stdc++.h>

using namespace std;

#define int long long

const double tol = 1e-8;

struct p2d
{
    double x;
    double y;

    double size()
    {
        return sqrt(x*x + y*y);
    }
    bool operator==(p2d p2)
    {
        return abs(x - p2.x) <= tol && abs(y - p2.y) <= tol;
    }

    p2d operator*(double i)
    {
        return {x*i, y*i};
    }
    p2d operator+(p2d i)
    {
        return {x+i.x, y+i.y};
    }
};

p2d gen_line(p2d b, p2d a)
{
    p2d res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;

    double s = res.size();

    if(s != (double)0)
    {
        res.x /= s;
        res.y /= s;
    }

    return res;
}

int solve()
{
    p2d p1, p2, p3;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    // The idea is to do the cross product between the vectors, p2-p1 and p3-p1
    // Based on the norm of the imaginary Z dimension we can deduce the side in which p3 is
    // accourding to the right hand rule.

    int res = (p2.x - p1.x) * (p3.y - p1.y )- (p2.y - p1.y) * (p3.x - p1.x);

    if(res == 0)
        cout << "TOUCH" << endl;
    else if (res > 0)
        cout << "LEFT" << endl;
    else
        cout << "RIGHT" << endl;

    return 0;
}

signed main()
{

    int t; cin >> t;

    while(t--)
        solve();

    return 0;
}