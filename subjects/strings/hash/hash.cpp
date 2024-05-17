#include<bits/stdc++.h>

using namespace std;

#define int long long
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
signed main()
{

    string s1, s2; cin >> s1 >> s2;

    cout << (StringHash(s1)(0, s1.size()-1) == StringHash(s2)(0, s2.size()-1) ? "Equal" : "Differet") << endl;


    return 0;
}