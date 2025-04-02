#include <bits/stdc++.h>

using namespace std;

struct pt
{
    int x, y;

    pt(){ y = x = 0;}
    pt(int x, int y) : x(x), y(y) {}

    pt operator+ (pt const &p) {return pt(p.x+x, p.y+y);}
    pt operator- (pt const &p) {return pt(x-p.x, y-p.y);}
    pt operator+ (int const val) {return pt(val*x, val*y);}
    int operator* (pt const &p) {return p.x*x + p.y*y;}
    int  operator ^(pt const & p) { return x*p.y - y*p.x; } 

    bool operator < (pt &p){
        if (p.x < x)
            return false;
        if(p.x > x)
            return true;
        return y < p.y;
    }

    bool operator==(pt &p) { return p.x == x && p.y == y; }
    bool operator<=(pt&p) { return *this < p || *this == p; }
    bool operator > (pt&p) { return !(*this <= p); }
    bool operator >= (pt &p) { return !(*this < p); }
};

vector<pt> points;

pt gen_central(const vector<pt> & pts)
{
    pt center;

    for (auto p : pts)
        center = center + p;
    
    center.x /= pts.size();
    center.y /= pts.size();

    return center;
}

int ccw(pt p1, pt p2)
{
    int val = p1 ^ p2;

    if(val == 0)
        return 0;

    return val / abs(val);
}

vector<pt> sort_by_ccw(const vector<pt> & pts)
{
    vector<pt> first, second, third, fourth;

    for(auto p: pts)
    {
        if(p.x >= 0 && p.y > 0)
            first.emplace_back(p);
        else if(p.x < 0 && p.y >= 0)
            second.emplace_back(p);
        else if (p.x <= 0 && p.y < 0)
            third.emplace_back(p);
        else
            fourth.emplace_back(p);
    }

    pt center = gen_central(pts);

    auto comp = [center](pt p1, pt p2)
    {
        return ccw(p1 - center, p2 - center) == -1;
    };

    sort(first.begin(), first.end(), comp);
    sort(second.begin(), second.end(), comp);
    sort(third.begin(), third.end(), comp);
    sort(fourth.begin(), fourth.end(), comp);


    vector<pt> ans(pts.size());

    for(auto p : first)
        ans[ans.size()] = p;
    for(auto p : second)
        ans[ans.size()] = p;
    for(auto p : third)
        ans[ans.size()] = p;
    for(auto p : fourth)
        ans[ans.size()] = p;

    return ans;
}