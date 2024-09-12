#include<bits/stdc++.h>

using namespace std;

//  $$|p.x - q.x| = \max(p.x - q.x, -p.x + q.x)$$ 


/*

    The whole concept of this runs over the extrapolation of this idea to many dimensions

    Considering we just have the x cordinate, to maximize the distance between to points, 
    we need to find the largest and the smallest

    |p.x - q.x| = max(p.x - q.x, -p.x + q.x) 

    For better comprehension lets always consider p.x-q.x as positive therefore 
    max(p.x - q.x, -p.x + q.x) = p.x - q.x. So we can do

    max(p.x + (-q.x)) = max(p.x) + max(-q.x) 
    
    = max(p.x) - min(q.x) 

    With more cordinates we can get a simillar result, just like 
    
    max(p.x + p.y) - min(q.x + q.y)

    Just remember that it is important to handle the all permutations of signs, so its 
    necessary to handle cases like 

    max(-p.x + p.y) - min(q.x - q.y)
    max(p.x - p.y) - min(-q.x + q.y)
    max(p.x + p.y) - min(-q.x - q.y)

*/ 

vector<vector<int>> p = { // Points
    {1, 2},
    {1, 6},
    {12, 6},
    {18, 6},
    {5, 9},
    {3, 4},
};
int n = p.size(); // number of points
int d = p[0].size(); // Dimension of the cordinetes


int solve()
{

    long long ans = 0;

    // the idea is to iterate throught all signal permutations as a bitmask
    for (int msk = 0; msk < (1 << d); msk++) {
        long long mx = LLONG_MIN, mn = LLONG_MAX;

        // For every point we are going to get the values 
        for (int i = 0; i < n; i++) {
            long long cur = 0;

            // Iterate over all cordinates of a point and making sum/sub operations
            // acourding to the bitmask
            for (int j = 0; j < d; j++) {
                std::cout << msk << ' ' << (1 << j) << endl;
                if (msk & (1 << j)) 
                    cur += p[i][j];
                else
                    cur -= p[i][j];
            }
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        ans = max(ans, mx - mn);
    }

    std::cout << ans << endl;
    return 0;
}



int main()
{

    solve();

    return 0;
}