#include<bits/stdc++.h>

/*

    There is a distance metric called chebyschev distance, that dissociates the coordinates of points
    while calculating the distance. 

        D chebyschev (x, w) = max(|cord_i_x - cord_i_w|)

    so there is a way to make the manhattan distance = chebyscev distance.

    basicly we just need to project these points to a chebyschev using the function described bellow
    and thats all

*/

using namespace std;

pair<int, int> to_chebyschev(pair<int, int> p)
{
    return {p.first + p.second, p.first - p.second};
}


signed main()
{



    return 0;
}