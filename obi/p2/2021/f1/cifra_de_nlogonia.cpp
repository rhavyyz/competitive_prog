#include<bits/stdc++.h>

#define int long long

using namespace std;

char vogals[5] = {'a', 'e', 'i', 'o', 'u'};

char nearest_vogal(char c)
{
    char vogal = 'a';
    int dist = c - 'a';

    for(int i = 1; i < 5; i++)
    {
        if(abs(c-vogals[i]) < dist)
        {
            dist = abs(c-vogals[i]);
            vogal = vogals[i];
        }
        // else
        //     break;
    }

    return vogal;
}

bool is_vogal(char c)
{
    for(int i =0; i < 5; i++)
    {
        if(c == vogals[i])
            return true;
    }

    return false;
}

int solve()
{
    string s; cin >> s;

    string res;

    for(char c : s)
    {
        res += c;

        if(is_vogal(c))
            continue;

        res += nearest_vogal(c);

        if(c!='z')
            c++;
        if(is_vogal(c))
            c++;    

        res+=c;

    }

    return cout << res << endl, 0;
}

signed main()
{

    solve();

    return 0;
}