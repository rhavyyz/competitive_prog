#include<bits/stdc++.h>

using namespace std;


vector<int> genZarray(string &s )
{
    int n = s.size();

    vector<int> zarray(n, 0);

    int l = 0, r = 0;
    int i = 0;  


    while(i++, i < n)
    {

        // cout << l << ' ' << r << endl;
        if(i <= r)
        {
            int k = i-l;

            if(zarray[k]+i <= r)
            {
                zarray[i] = zarray[k];
                continue;
            }

            l = i;
            
            cout << s[i]  << ' '  << i << endl << zarray[k]+i << ' ' << r << endl;
            while(r + 1 < n && s[r+1] == s[r-l+1])
                r++;

            zarray[i] = r-l +1;

            continue;
        }

        l  = i;
        r = i -1;

        while( r + 1 < n && s[r+1] == s[r-l+1])
        {
            zarray[i]++;
            r++;
        }

    }

    cout << l << ' ' << r << endl;

    return zarray;
}

signed main()
{

    string s = "abcabcaaaabc";

    auto vec = genZarray(s);

    for(auto a : vec)
        cout << a << " ";

    cout << '\n';

    return 0;
}