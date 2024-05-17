#include<bits/stdc++.h>

using namespace std;

int main()
{

    int tot; cin >> tot;

    int values[3];
    cin >> values[1];
    cin >> values[2];
    cin >> values[0];

    sort(values, values+ 3);

    int i = 0;
    for(; i < 3; i++)
    {
        if(tot >= values[i])
        {
            tot -= values[i];
        }
        else
            break;
    }

    cout << i << endl;

    return 0;
}