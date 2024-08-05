#include <bits/stdc++.h>

using namespace std;

/*
    Picks theorem express the area of a polygon which aint vertices are lattice points 

        A = I + 1/2*B - 1

    With:
        A beeing the Area
        I beeing the number of littice points inside the polygon
        B beeing the number of litice points on the boundary / edges of the polygon

*/

// Felipe`s code (need to be revised)

int gcd(int a, int b)
{
    if(a < b)
        swap(a, b);
    if(b == 0)
        return a;

    return gcd(b, a%b);
}

// second is x and first is y

int calculate_lattice_points_in_edges(const vector<pair<int, int>> &polygon) {
    int ans {};

    for (int i = 0; i < (int) polygon.size(); ++i) {
		auto q = i ? polygon[i - 1] : polygon.back();
		auto p = polygon[i];

        if (p.second == q.second) {
            ans += abs(p.first - q.first) - 1;
        } else if (p.first == q.first) {
            ans += abs(p.second - q.second) - 1;
        } else {
            ans += gcd(abs(p.second - q.second), abs(p.first - q.first)) - 1;
        }
    }

    return ans + polygon.size();
}

template <typename T>
int calculate_lattice_points_inside_polygon(const vector<pair<int, int>> &polygon) {
	auto area = calculate_two_times_area(polygon);
    int lattice_points_in_edge = calculate_lattice_points_in_edges(polygon);

    return (area - lattice_points_in_edge + 2) / 2; 
}
int main()
{


    return 0;
}