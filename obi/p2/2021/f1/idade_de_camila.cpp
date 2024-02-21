#include<bits/stdc++.h>

#define int long long

using namespace std;

int solve()
{
    // cibele > camila > celeste

    int ages[3];

    cin >> ages[0] >> ages[1] >> ages[2];
    sort(ages, ages+3);

    return cout << ages[1] << endl, 0;
}

signed main()
{

    solve();

    return 0;
}