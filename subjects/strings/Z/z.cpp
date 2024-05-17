#include<bits/stdc++.h>

using namespace std;

#define int long long

int zarray[10000000];

void genZarray(string &s)
{
    int n = s.size();

    int l = 0, r = 0;
    int i = 0;  


    while(i++, i < n)
    {
        // cout << i ;

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

}

signed main()
{
    string source, pattern;
    cin >> source >> pattern;

    string f = pattern + "$" + source;

    memset(zarray, 0, sizeof(int) * f.size());

    genZarray(f);

    int n = 0;

    // cout  << f << endl;

    for(int i = 0; i < f.size();i++)
    {
        // cout << zarray[i] << ' ' ;
        if(zarray[i] == pattern.size())
            n++;
    }

    cout << n << endl;

    return 0;
}