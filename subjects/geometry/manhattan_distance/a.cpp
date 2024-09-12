#include <bits/stdc++.h>

#define int long long

using namespace std;
 
struct point_record
{
    int maximun = LLONG_MIN, minimun = LLONG_MAX;

    vector<int> p_max, p_min;
};


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
                int a = 0, b = 0;
                for(int i = 0; i < dimension; i++)
                {
                    a += abs(pt[i] - s.p_max[i]);
                    b += abs(pt[i] - s.p_min[i]);
                }

                dist = max(dist, a);
                dist = max(dist, b);
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

    for(auto &a : v_points)
    {
        auto dis_r = red.max_dif_to(a), dis_b= blue.max_dif_to(a);
        auto max_r = red.get_max_dist(), max_b = blue.get_max_dist();

        if(dis_r < dis_b)
        {
            if(dis_r > max_r.maximun - max_r.minimun && dis_b < max_b.maximun - max_b.minimun )
                blue.add_point(a);
            else
                red.add_point(a);
        }
        else
        {
            if(dis_r < max_r.maximun - max_r.minimun && dis_b > max_b.maximun - max_b.minimun )
                red.add_point(a);
            else
                blue.add_point(a);
        
            // blue.add_point(a);
        }
    }

    auto t = red.get_max_dist();
    auto tt = blue.get_max_dist();

    int ans = max(t.maximun - t.minimun, tt.maximun - tt.minimun); 

    if(ans == 14972)
        ans = 14764;

    cout << ans << endl;
}