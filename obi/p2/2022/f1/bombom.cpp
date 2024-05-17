#include<bits/stdc++.h>

#define int long long

using namespace std;

int getVal(char c)
{
    if(c == 'A')
        return 10;
    if(c == 'J')
        return 11;
    if(c == 'Q')
        return 12;

    return 13;
}

signed main()
{

    char c, n, dominante; 
    cin >> c >> dominante;

    // cout << c << ' ' << dominante << endl;

    int l = 0;

    for(int i = 0 ; i < 3; i++)
    {
        cin >> c >> n;
        l += getVal(c);
        if(n == dominante)
            l+= 4;
    }

    int e = 0;

    for(int i = 0 ; i < 3; i++)
    {
        cin >> c >> n;
        e += getVal(c);
        if(n == dominante)
            e+= 4;
    }

    // cout << e << ' ' << l <<endl;

    if(e > l)
    {
        cout << "Edu" << endl;
    }
    else if(e < l)
    {
        cout << "Luana" << endl;
    }
    else
    {
        cout << "empate" << endl;
    }

    return 0;
}