// #include<bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

/*

    Based on the euclidian theorem it is a way to find x and y, with them beeing

    gcd(a,b) = x*a + y*b

    It works in this way

    So, at first let g = gcd(a, b)

    we know that there is possible to do 

        g = x1 * b + y1 * a%b

    expanding the concept of mod

        g = x1 * b + y1 * (a - ⌊a/b⌋ * b) 

        => g = x1 * b + y1*a - y1 * ⌊a/b⌋ * b
 
        => g =  y1*a - y1 * ⌊a/b⌋ * b + x1 * b 
        
        => g =  y1*a (- y1 * ⌊a/b⌋ + x1) * b 

    Switching g for x*a + y*b

        x*a + y*b =  y1*a (- y1 * ⌊a/b⌋ + x1) * b 

    Seeing like this we can segregate this equation in two

        * x*a =  y1*a 

    and 

        * y*b = (- y1 * ⌊a/b⌋ + x1) * b 

    So the code works based on this still in log time.
    In top of that we just need to consider that when we find gcd(a, 0)
    x = 1 and y = 0 (y value doesnt matter really but lets put the most intuitive number for god sake)

*/

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