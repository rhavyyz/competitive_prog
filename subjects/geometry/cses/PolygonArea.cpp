#include <bits/stdc++.h>

#define int long long

using namespace std;

struct pt
{
    int x, y;

    pt(){ y = x = 0;}
    pt(int x, int y) : x(x), y(y) {}

    pt const operator+ (pt const &p) const {return pt(p.x+x, p.y+y);}
    pt const operator- (pt const &p) const {return pt(x-p.x, y-p.y);}
    pt const operator+ (int val) const {return pt(val*x, val*y);}
    int const operator* (pt const &p) {return p.x*x + p.y*y;}
    int const operator ^(pt const & p) const { return x*p.y - y*p.x; } 

    bool operator < (pt const &p){
        if (p.x < x)
            return false;
        if(p.x > x)
            return true;
        return y < p.y;
    }

    bool operator==(pt const  &p) { return p.x == x && p.y == y; }
    bool operator<=(pt const &p) { return *this < p || *this == p; }
    bool operator > (pt const &p) { return !(*this <= p); }
    bool operator >= (pt const &p) { return !(*this < p); }
};

pt gen_central(const vector<pt> & pts)
{
    pt center;

    for (auto p : pts)
        center = center + p;
    
    center.x /= pts.size();
    center.y /= pts.size();

    return center;
}

bool ccw(pt pt1, pt pt2, pt pt3)
{
    return ((pt2 - pt1) ^ (pt3 - pt2)) > 0;
}


int quad(pt z)
{
     if(z.x >= 0 && z.y > 0)
        return 1;
    else if(z.x < 0 && z.y >= 0)
        return 2;
    else if (z.x <= 0 && z.y < 0)
        return 3;
    else
        return 4;        
}

bool comp_ccw(pt p1, pt p2)
{
    if(quad(p1) != quad(p2)) return quad(p1) < quad(p2);


}



int area_x_2(vector<pt> const & ccw_polygon)
{
    int n = ccw_polygon.size();
    int tot = 0; 

    for(int i = 0; i <  ccw_polygon.size(); i++)
    {
        int n1 = (i + 1) %n;
        tot += ccw_polygon[i] ^ (ccw_polygon[n1] -ccw_polygon[i]);
    }

    return abs(tot);
}

int solve()
{
    int n; cin >> n;
    vector<pt> points(n);

    for(auto &p : points)
        cin >> p.x >> p.y;

    // for(auto &p : points)
    //     cout << p.x << ' ' << p.y << endl;;

    points = sort_by_ccw(points);

    cout << area_x_2(points) << endl;
    return 1;
}

signed main()
{
    int t = 1;
    // cin >> t;

    while(t--)
        solve();
    
    return 0;
}