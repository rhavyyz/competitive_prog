// #include<bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

array<int, 3> extended_gcd(int a, int b)
{
    if(b > a)
        swap(a, b);
    
    if(b == 0)
        return {a, 1, 0};

    auto [res, x1, y1] = extended_gcd(b, a % b);

    return {res, y1, x1 - a/b * y1};
} 

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    if(b == a)
        return a;
    
    return gcd(b, a%b);
}

signed main()
{
    auto [res, x, y] = extended_gcd(100, 88);

    cout << "a"<< res << ' ' << x << ' ' << y << endl;

    return 0;
}