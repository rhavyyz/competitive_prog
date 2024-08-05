#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; //required 
using namespace std;
 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#define int long long 
#define IOS ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false); 
#define endl '\n'
#define bug(x)  cerr << #x << " >>> " << x << endl;
#define all(A) 

int hex_to_int(string s)
{
    int res = 0;

    reverse(s.begin(), s.end());

    int base = 1;


    for(char c : s)
    {
        int number;
        if(c >= '0' && c <= '9')
            number = c-'0';
        else
            number = c-'a' + 10;

        res += number*base;

        base*=16;
    }


    return res;
}

void solve()
{

    int pascal_size = -1;
    bool pascal = true;
    bool c = true;
    bool c_ended = false;

    int upper = hex_to_int("7f");
    int lower = hex_to_int("20");

    auto check_c = [&](string s)
    {
        if(c_ended)
            return;

        int value = hex_to_int(s);
        if(value == 0)
        {
            c_ended = true;
            return;
        }

        if(lower>value || upper < value)
            c = false;
    };

    auto check_pascal = [&](string s)
    {
        if(pascal_size == 0)
            return;

        int value = hex_to_int(s);
        if(pascal_size == -1)
        {
            pascal_size = value;

            return;
        }

        if(lower>value || upper < value)
            pascal = false;
    
        pascal_size--;
    };

    string s;

    while(cin >> s)
    {
        check_c(s);
        check_pascal(s);
    }

    if(c_ended == false)
        c = false;
    if(pascal_size > 0)
        pascal = false;

    if(c&&pascal)
        cout << "Both" << endl;
    else if(c)
        cout << "C" << endl;
    else if(pascal)
        cout << "Pascal" << endl;
    else
        cout << "None" << endl;


}
 
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;    

    while(t--)
        solve();
    
    return 0;
}