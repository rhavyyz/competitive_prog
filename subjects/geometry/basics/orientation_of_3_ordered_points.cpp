// Given 3 points the task is to determine the orientation of them
#include<utility>


enum Orientation
{

    counter_clockwise,
    clockwise,
    colinear

};

Orientation find_orientation(std::pair<int, int> p1, std::pair<int ,int> p2, std::pair<int ,int> p3)
{
    int ans = (p2.second-p1.second)* (p3.first - p2.first) - (p3.second-p2.second)* (p2.first - p1.first);

    if(ans == 0)
        return Orientation::colinear;
    if(ans > 0)
        return Orientation::clockwise;
    else
        return Orientation::counter_clockwise;
}