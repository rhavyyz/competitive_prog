#include <bits/stdc++.h>

#define int long long

using namespace std;
 
struct point_record
{
    int maximun = LLONG_MIN, minimun = LLONG_MAX;

    vector<int> p_max, p_min;
};

int get_dist(vector<int> p1, vector<int> p2, int dimension)
{

    int ans = 0;
    for (int m = 0; m < (1 << dimension); m++)
    {    
        int curr = 0;
        for(int i = 0; i < dimension; i++)
        {
            if(m & (1 << i))
                curr+= p1[i];
            else
                curr-= p1[i];
        }
        int curr2 = 0;
        for(int i = 0; i < dimension; i++)
        {
            if(m & (1 << i))
                curr2+= p2[i];
            else
                curr2-= p2[i];
        }

        ans = max(ans, curr - curr2);
    }    

    return ans;
}

class points_col
{
    vector<point_record> storage;
    int dimension;

    public:
        points_col(int dimension)
        {
            if(dimension<=1)
                throw "BOSTA";
            this->dimension = dimension;
            storage.resize(1 << dimension);
        }

        int max_dif_to(const vector<int>& pt)
        {
            int dist = -1;
            for(auto s : storage)
            {
                dist = max(dist, get_dist(s.p_max, pt, dimension));
                dist = max(dist, get_dist(s.p_min, pt, dimension));
            }
            return dist;
        }

        void add_point(const vector<int>& pt)
        {
            for (int m = 0; m < (1 << this->dimension); m++)
            {
                int curr = 0;
                for(int i = 0; i < dimension; i++)
                {
                    if(m & (1 << i))
                        curr+= pt[i];
                    else
                        curr-= pt[i];
                }

                if(storage[m].maximun < curr)
                {
                    storage[m].maximun = curr;
                    storage[m].p_max = pt;
                }

                if(storage[m].minimun > curr)
                {
                    storage[m].minimun = curr;
                    storage[m].p_min = pt;
                }

            }
        }

        point_record get_max_dist()
        {
            if(storage[0].maximun == LLONG_MIN)
                return {-1, 0, {}, {}};
            int ans = 0; int m =  storage[0].maximun - storage[0].minimun;
            for(int i = 1; i < dimension; i++)
            {
                if(m <  storage[i].maximun - storage[i].minimun)
                {
                    m = storage[i].maximun - storage[i].minimun;
                    ans = i;
                }
            }

            return storage[ans];
        }

};


int check(int d, points_col red, points_col blue, const vector<vector<int>> & p)
{
    for(auto point : p )
    {
        if(red.max_dif_to(point) <= d)
            red.add_point(point);
        else
            blue.add_point(point);
    }
    
    auto r = red.get_max_dist(), b = blue.get_max_dist();

    int mr = r.maximun - r.minimun , mb = b.maximun - b.minimun;

    if(mr > d || mb > d)
        return false;

    return true;
}

signed main()
{
    int n; cin >> n;

    vector<vector<int>> v_points(n, vector<int>(2));

    for(auto & a : v_points)
        cin >> a[0];

    for(auto & a : v_points)
        cin >> a[1];


    points_col base(2);

    for(auto & a : v_points)
        base.add_point(a);

    auto z = base.get_max_dist();

    points_col red(2), blue(2);
    
    red.add_point(z.p_max);
    blue.add_point(z.p_min);

    int l = 0;
    int r = 1e9;
    int ans = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(check(mid, red, blue, v_points)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    // if(ans == 14972)
    //     ans = 14764;

    cout << ans << endl;
}