#include <bits/stdc++.h>
using namespace std;
/*

    Inicialmente vamos declarar as estruturas importantes que devemos ser capazes de representar

*/
#define int long long


struct Point 
{
    int x , y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point operator+(const Point &p) const    { return Point(p.x + this->x, p.y + this->y); }
    Point operator*(const int i) const    { return Point(i * this->x, i * this->y); }
    Point operator-(const Point &p) const    { return p + ((*this)*-1); }

    int operator*(const Point &p) const { return this->x * p.x + this->y * p.y; }
    int operator^(const Point &p) const { return this->x * p.y - this->y+p.x; }

    bool operator == (const Point& p) const {
        return p.x == this->x and p.y == this->y;
    }

    bool operator < (const Point &p) const {
        if(p.x > this->x)
            return true;
        else if (p.x < this->x)
            return false;
        
        return p.y > this->y;
    }

    bool operator <= (const Point &p) const { return *this < p || (*this) == p; }

    bool operator >(const Point &p) const { return !(*this <= p); }

    bool operator>=(const Point &p) const{ return !(*this < p); }

    friend istream& operator >> (istream & in, Point& p) { return in >> p.x >> p.y; }
};

struct Line
{
    Point p1, p2;

    Line(Point p1, Point p2) : p1(p1), p2(p2) {}

    void sort()
    {
        if (!(p1 < p2))
            swap(p1, p2);
    }

    friend istream& operator >> (istream & in, Line& l) { return in >> l.p1 >> l.p2; }
};

int solve()
{
    int a, b, c, d, e, f, g, h; cin >> a >> b >> c >> d >> e >> f >> g >> h;

    cout << "Something" << endl;

    Line l1(Point(a, b), Point(c, d)),
         l2(Point(e, f), Point(g, h));

    l1.sort();
    l2.sort();

    bool ok = false;
    bool has_0 = false;
    int first = (l1.p2 - l1.p1) ^ (l2.p1- l1.p1);
    if(!first)
    {
        has_0 = true;
        ok = ok || (l1.p1 < l2.p1 && l2.p1 < l1.p2);
    }

    int second = (l1.p2 - l1.p1) ^ (l2.p2- l1.p1);
    if(!second)
    {
        has_0 = true;
        ok = ok || (l1.p1 < l2.p2 && l2.p2 < l1.p2);
    }

    int first_ = (l2.p2 - l2.p1) ^ (l1.p1- l2.p1);
    if(!first_)
    {
        has_0 = true;
        ok = ok || (l2.p1 < l1.p1 && l1.p1 < l2.p2);
    }

    int second_ = (l2.p2 - l2.p1) ^ (l1.p2- l2.p1);
    if(!second_)
    {
        has_0 = true;
        ok = ok || (l2.p1 < l1.p2 && l1.p2 < l2.p2);
    }


    if(has_0 == true)
    {
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }
    first = first/abs(first);
    first_ = first_/abs(first_);
    
    second = second/abs(second);
    second_ = second_/abs(second_);
    
    if(first == -1*second && first_ == -1*second_)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

signed main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}

/*

    Minkowsky sum.

    Line sweep com segtree para unição entre retangulos.

*/