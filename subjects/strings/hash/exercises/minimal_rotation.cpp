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
 
bool less_than(int i, int best,  StringHash & h, const string & s)
{
    int n = s.size()/2;
 
    int l = 0, r = n -1;
 
    while(l<r)
    {
        if(l == n-1)
            return false;
 
        int mid = (l+r)/2;
 
        if(h(i, i+mid) == h(best, best+mid))
        {
            if(s[i+mid+1] != s[best+mid+1])
                return s[i+mid+1] < s[best+mid+1];
        
            l = mid+1;
        }
        else
        {
            // cout << l << ' ' << r << ' ' << mid << endl;
            r = mid;
        }
    }
    // cout << l << ' ' << r <<endl;;
    if(s[i+l] == s[best+l])
        return s[i+l+1] < s[best+l+1];
 
    return s[i+l] < s[best+l];
}
 
int solve()
{
    string s; cin >> s;
 
    int n = s.size();
    s += s;
 
    StringHash h(s);
 
    int best_window = 0;
 
    for(int i = 1; i < n; i++)
    {
        if(less_than(i, best_window, h, s))
        {
            // cout << best_window << ' ' << i << endl;
            best_window = i;
        }
    }
 
    
    cout << s.substr(best_window,n);
    cout << endl;
 
    return 0;
}
 
signed main()
{
 
    solve();
 
    return 0;
}