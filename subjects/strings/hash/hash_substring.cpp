#include<bits/stdc++.h>

using namespace std;

#define int long long

int g_values[123];
int p = 31;
int m = 1e9 + 9;

vector<int> hashes;
vector<int> p_pows;

int hashing(string &s)
{
    p_pows.resize(s.size() +1);
    hashes.resize(s.size() +1);
    p_pows[0] = 1;

    int h = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        hashes[i] =  h = (h + (s[i]*p_pows[i]) % m) % m;

        p_pows[i+1] = (p_pows[i] * p) % m;
    }

    return h;
}

int subh(int i , int r)
{

    int tot = hashes[r];
    // cout << "pass" << endl;

    if(i > 0)
        tot-=hashes[i-1];

    tot *= p_pows[p_pows.size() - 1 - i];

    return tot % m;
}


signed main()
{
    string s; cin >> s;

    for(char c = 'a'; c <='z';c++)
    {
        char aux ; cin >>aux;

        g_values[c] = aux == '1' ? 0 : 1;
    }
    
    hashing(s);

    vector<int> psum(s.size());

    int last = 0;
    for(int i = 0 ; i < s.size(); i++)
    {
        psum[i] = last + g_values[s[i]];
        last = psum[i];
    }

    int k; cin >> k;

    // cout << "pass" << endl;

    set<int> se;

    last = 0;
    for(int i = 0; i < psum.size(); i++)
    {
        for(int r = i; r < psum.size(); r++)
        {
     
                // cout << i << ' ' << r << endl;
            if(psum[r] - last <= k)
            {
                if(se.find(subh(i, r)) == se.end())
                {
                    cout << s.substr(i, r-i + 1) << ' ' << subh(i, r) << endl;
                    se.insert(subh(i, r));
                }

            }
        }
        last = psum[i];
    }

    cout << se.size() << endl;

    return 0;
}