#include<bits/stdc++.h>

using namespace std;

vector<int> gen_lps(const string & pat)
{

    vector<int> lps(pat.size(), 0); 

    int len = 0, i = 1;

    while(i<pat.size()){
        cout << len << ' ' << i << endl;
        
        if(pat[i] == pat[len])
        {
            lps[i] = ++len;
            i++;
        }
        else if(len> 0)
            len = lps[len-1];
        else
            i++;
    }

    return lps;

}

int main()
{
    string s; cin >>s;

    
    auto lps = gen_lps(s);

    for(auto t : lps)
        cout << t << " ";

    cout << endl;

    return 0;

}