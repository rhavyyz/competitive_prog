#include <bits/stdc++.h>

#define all(A) A.begin(), A.end()

using namespace std;

struct p1
{
    int x;
};

struct p3
{
    double x, y, z;
};

struct cmpX{
    public:
    bool operator ()(p3 p, p3 q){return p.x < q.x;}
};
struct by_y{
    bool operator ()(p3 p, p3 q){return p.y < q.y;}
};
struct by_z{
    bool operator ()(p3 p, p3 q){return p.z < q.z;}
};


struct p2
{
    double x, y;
};

double dist(p3 p, p3 q)
{
    return (p.x - q.x) * (p.x - q.x) 
                       + 
           (p.y - q.y) * (p.y - q.y)
                       +
           (p.z - q.z) * (p.z - q.z);
}

double dist(p1 p, p1 q)
{
    return abs(p.x - q.x);
}

double dist(p2 p, p2 q)
{
    return abs(
                (p.x - q.x) * (p.x - q.x) 
                            + 
                (p.y - q.y) * (p.y - q.y)
              );
}

double with_p1(vector<p1> & points, int begin = 0, int end = -1)
{
    if(end == -1)
        end = points.size();

    cout << begin << ' ' << end << endl;

    int size = end - begin;


    if(size == 2)
        return dist(points[begin], points[begin+1]);

    if(size == 3)
        return min(
                        min(
                            dist(points[begin], points[begin+1]), 
                            dist(points[begin], points[begin+2])
                           ),
                        dist(points[begin+2], points[begin+1])
                   );

    int mid = (begin+end)/2;

    double d1 = with_p1(points, begin, mid),
           d2 = with_p1(points, mid, end);

    return min(d1, min(d2, dist(points[mid-1], points[mid])));
}

double with_p2_(vector<p2> & points, int begin = 0, int end = -1)
{
    if(end == -1)
        end = points.size();

    // cout << begin << ' ' << end << endl;

    int size = end - begin;


    if(size == 2)
        return dist(points[begin], points[begin+1]);

    if(size == 3)
        return min(
                        min(
                            dist(points[begin], points[begin+1]), 
                            dist(points[begin], points[begin+2])
                           ),
                        dist(points[begin+2], points[begin+1])
                   );

    int mid = (begin+end)/2;

    double d1 = with_p2_(points, begin, mid),
           d2 = with_p2_(points, mid, end);

    double median = size % 2 ? points[size/2 + begin].x : ((double)points[size/2 + begin].x - points[size/2 + begin - 1].x)/2;

    double upper = median + min(d1, d2) + 0.0001;
    double lower = median - min(d1, d2) - 0.0001;
    // cout << "Here 1" << endl;

    int smaller_pos;
    for( smaller_pos = mid-1; smaller_pos >= 0 && points[smaller_pos].x > lower; smaller_pos--)
    { }
    smaller_pos++;
    // cout << "Here 2" << endl;
    
    int bigger_pos;
    for( bigger_pos = mid+1; bigger_pos < points.size() && points[bigger_pos].x < upper; bigger_pos++)
    { } 
    // cout << "Here 3" << endl;


    sort(points.begin() + smaller_pos, points.begin() + bigger_pos, [](p2 q, p2 p){return q.y < p.y;});

    // cout << "Here 4" << endl;


    double min_dist = 1e10; 

    for(int i = smaller_pos; i < bigger_pos; i++)
    {
        for(int j = i + 1; j < bigger_pos && j < bigger_pos + 8; j++)
            min_dist = min(min_dist, dist(points[i], points[j]));
    }

    sort(points.begin() + smaller_pos, points.begin() + bigger_pos, [](p2 q, p2 p){return q.x < p.x;});

    return min(d1, min(d2, min_dist));
}

double with_p3_(vector<p3> & points, int begin = 0, int end = -1)
{
    if(end == -1)
        end = points.size();

    // cout << begin << ' ' << end << endl;

    int size = end - begin;


    if(size == 2)
        return dist(points[begin], points[begin+1]);

    if(size == 3)
        return min(
                        min(
                            dist(points[begin], points[begin+1]), 
                            dist(points[begin], points[begin+2])
                           ),
                        dist(points[begin+2], points[begin+1])
                   );

    int mid = (begin+end)/2;

    double d1 = with_p3_(points, begin, mid),
           d2 = with_p3_(points, mid, end);

    double median = size % 2 ? points[size/2 + begin].x : ((double)points[size/2 + begin].x - points[size/2 + begin - 1].x)/2;

    double upper = median + min(d1, d2) + 0.0001;
    double lower = median - min(d1, d2) - 0.0001;


    int smaller_pos;
    for( smaller_pos = mid-1; smaller_pos >= 0 && points[smaller_pos].x > lower; smaller_pos--)
    { }
    smaller_pos++;
    
    int bigger_pos;
    for( bigger_pos = mid+1; bigger_pos < points.size() && points[bigger_pos].x < upper; bigger_pos++)
    { } 

    sort(points.begin() + smaller_pos, points.begin() + bigger_pos, by_y());

    double min_dist = dist(points[smaller_pos], points[smaller_pos+1]); 

    for(int i = smaller_pos; i < bigger_pos; i++)
    {
        for(int j = i + 1; j < bigger_pos && j < bigger_pos + 34; j++)
            min_dist =  dist(points[i], points[j]);
    }

    // sort(points.begin() + smaller_pos, points.begin() + bigger_pos, by_z());

    // for(int i = smaller_pos; i < bigger_pos; i++)
    // {
    //     for(int j = i + 1; j < bigger_pos && j < bigger_pos + 17; j++)
    //         min_dist = min(min_dist, dist(points[i], points[j]));
    // }

    sort(points.begin() + smaller_pos, points.begin() + bigger_pos, cmpX());

    return min(d1, min(d2, min_dist));
}


double with_p3(vector<p3> & points)
{
    return sqrt(with_p3_(points));
}

double with_p2(vector<p2> & points)
{
    return sqrt(with_p2_(points));
}

signed main()
{

    int n; cin >> n;

    vector<p3> points(n);

    for(auto &point : points)
    {
        int x, y, z; cin >> x >> y >> z;

        point.x= x;
        point.y= y;
        point.z= z;
    }

    sort(all(points), cmpX());

    cout << fixed << setprecision(9) <<  with_p3(points) << endl;
    // cout << brute(points) << endl;

    return 0;
}