#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n, k; cin >> n >> k;


    vector<int> vals;

    while(n--)
    {
        int aux; cin >> aux;

        vals.push_back(aux);
    }

    sort(vals.begin(), vals.end());

    cout << vals[k-1] << endl;

    return 0;
}