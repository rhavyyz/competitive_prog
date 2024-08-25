#include<bits/stdc++.h>

using namespace std;



int main()
{
    int d; cin >> d;   

    int dist1 = d % 400;
    int dist2 = 400 - dist1;

    cout << min(dist1 , dist2) << endl;

    return 0;
}