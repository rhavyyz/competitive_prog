#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<string> v = {"aab", "aa"};

    sort(v.begin(),v.end());
    cout << (v[0][2] == '\0') << endl;

    return 0;
}