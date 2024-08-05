#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n; cin >> n;

    string s;

    int cnt = 0;
    bool ok = true;

    while(cin >> s)
    {
        for(char c : s)
        {
            if(c == '{')
                cnt++;
            else if( c == '}')
                cnt--;

            if(cnt < 0)
                ok = false;
        }
    }

    if(cnt > 0)
        ok = false;

    if(ok)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}