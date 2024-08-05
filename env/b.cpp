#include "bits/stdc++.h"
// #include<bit>
// #define err(x) cerr << "["#x"]  " << (x) << "\n"
// #define errv(x) {cerr << "["#x"]  ["; for (const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}
// #define errvn(x, n) {cerr << "["#x"]  ["; for (auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}
// #define all(a) a.begin(), a.end()
// #define pb push_back
// typedef long long ll;
// typedef long double ld;
// const int MOD = 1000000007;
// mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
using namespace std;

vector<int> vals;


int begin_bb(int v)
{
    int l = 0, r = vals.size()-1;

    while(l<=r)
    {
        int middle = (l+r)/2;

        if(vals[middle] >= v)
            r = middle -1;
        else
            l = middle + 1;
    }

    return l;
}

int end_bb(int v)
{
    int l = 0, r = vals.size()-1;

    while(l<=r)
    {
        int middle = (l+r)/2;

        if(vals[middle] > v)
            r = middle -1;
        else
            l = middle + 1;
    }

    return l;
}

int solve() 
{
    int n, T;

    cin >> n >> T;

    vector<int>  v1;

    int tot = 0;
    for(int i = 0; i < n/2; i++)
    {
        int number; cin >> number;
        // cout << number << ' ';
        int curr_size = vals.size();

        for(int i = 0; i < curr_size; i++)
        {
            vals.push_back(vals[i] + number);
            if(vals[i] + number <= T)
                tot++;
        }
        if(number <= T)
            tot++;
        vals.push_back(number);
    }

    // cout << tot << endl;

    // cout << "| ";

    // for(auto a : vals)
    //     cout << a << ' ';
    // cout << endl;

    sort(vals.begin(), vals.end());

    // cout << begin_bb(1800) << ' ' << end_bb(1800) << endl;

    for(int i = n/2; i < n; i++)
    {
        int number; cin >> number;
        // cout << number <<' ';
        int curr_size = v1.size();

        for(int i = 0; i < curr_size; i++)
        {    
            v1.push_back(v1[i] + number);

            if(v1[i] + number <= T)
                tot++;
            int end_ = end_bb(T-(v1[i] + number));
            // int begin_ = begin_bb(T-(v1[i] + number));

            // if(begin_ == end_)
            //     continue;

            tot += end_;

        }
        v1.push_back(number);
        if(number <= T)
            tot++;
        int end_ = end_bb(T-number);
        // int begin_ = begin_bb(T-number);
        // cout << number << ' ' << T << endl;
        // cout << end_ << endl;
        // cout << begin_ << endl;
        // if(begin_ == end_)
        //     continue;   
        tot += end_;
    }

    // cout << endl;
    cout << tot + 1 << endl;

    return 1;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int t = 1;
    
    // cin >> t;
    while (t--)
        solve();

    // priority_queue<int> q;

    // q.push(3);
    // q.push(2);
    // q.push(1);


}
