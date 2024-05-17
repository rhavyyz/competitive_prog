#include<bits/stdc++.h>

using namespace std;

int adjs[(int)1e5];

int main()
{
    memset(adjs, 0, sizeof(adjs));

    int n, t; 
    cin >> n >> t;

    for(int i = 1; i < n; i++)
    {
        int aux;
        cin >> aux;

        adjs[i] = i+aux;
    }

    int pos = adjs[1];

    bool can_go = false;

    while(pos != 0 && pos <= t)
    {
        if(pos == t)
        {
            can_go = true;   
        
            break;
        }

        pos = adjs[pos];

    }

    if(can_go)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}