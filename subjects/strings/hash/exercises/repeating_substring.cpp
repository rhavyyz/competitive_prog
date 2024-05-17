#include <bits/stdc++.h>
 
using namespace std;
 
struct StringHash {
    int n;
    string s;
    long long p = 1238473;
    long long mod = (1ll << 61) - 1;
    vector<long long> h, pot;
 
    long long mulmod(long long a, long long b) {
        long long q = (long long)((long double)a*b/mod);
        long long r = a * b - mod * q;
        while(r < 0) r += mod;
        while(r >= mod) r -= mod;
        return r;
        // return (a * (__int128)1 * b) % mod;
    }
 
    long long operator()(int l, int r) {
        if(!l) return h[r];
        long long hash_val = (h[r] - mulmod(h[l - 1], pot[r - l + 1]));
        if(hash_val < 0) hash_val += mod;
        return hash_val;
    }
 
    void build_hash() {
        h[0] = s[0];
        pot[0] = 1;
        for(int i = 1; i < n; ++i) {
            h[i] = (mulmod(h[i - 1], p) + s[i]);
            h[i] -= (h[i] >= mod ? mod : 0);
            pot[i] = mulmod(pot[i - 1], p);
        }
    }
 
    StringHash(string &_s) : n((int)_s.size()), s(_s) {
        h.resize(n);
        pot.resize(n);
        build_hash();
    }
};
 
string bb(StringHash & h, const string & s )
{
    int n = s.size();
    int l= 1, r = n-1;

    int m_size = 0;
    int pos = 0;

    while(l <  r)
    {
        int mid = (l+r)/2;

        cout << l << ' ' << mid << ' ' << r << endl;

        set<int> ocurrences;

        bool go_down = true;

        for(int i = 0 ; i + mid <= n; i++)
        {
            int h_v = h(i, i+mid -1);
            if(ocurrences.find(h_v) != ocurrences.end())
            {
                go_down = false;
                pos = i;
                m_size = mid;
                l = mid +1;
                break;
            }
            ocurrences.insert(h_v);
        }
        if(go_down)
            r=mid;

    }

    // cout << pos << m_size << endl;

    if(m_size == 0)
        return "-1";

    return s.substr(pos, m_size);

}

void solve()
{
    string s; cin >> s;

    StringHash h(s);

    cout << bb(h, s) << endl;

    return;
}
 
signed main()
{
 
    solve();
 
    return 0;
}