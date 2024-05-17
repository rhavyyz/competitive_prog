#include<bits/stdc++.h>

using namespace std;

#define int unsigned long int

const int MOD = 1e9 + 9;

const int P = 31;

int p_pow[(int)1e6 + 1];
int h_val[(int)1e6 + 1];
int BITree[(int)1e6 + 2];

int get_int(char c)
{
    return c - 'a' + 1;
}

void update_bit(int index, int val, int n)
{
    h_val[index] += val;

    index++;

    for(; index <= n; index += index & -index)
        BITree[index] = (BITree[index] + val) % MOD;

}
int get_bit_range(int index)
{
    index++;
    int sum = 0;

    for(;index > 0; index -= index & -index)
        sum = (sum +  BITree[index]) % MOD;

    return sum;
}

void init_bit(int n)
{
    for(int i = 0; i <= n; i++)
        BITree[i] = 0;

    for(int i = 0; i < n; i++)
        update_bit(i, h_val[i], n);
}


void hashing(const string & s)
{   
    int n = s.size();
    p_pow[0] = 1;

    for(int i = 1; i <= n; i++)
    p_pow[i] = (p_pow[i-1] * P) % MOD;

    for(int i = 0; i < n; i++)
        h_val[i] = (get_int(s[i]) * p_pow[i]) % MOD;


    init_bit(s.size());
    // cout << "aqui_ner" << endl;

}

int get_hash(const string  &s)
{
    return get_bit_range(s.size()-1);
}

void switch_char(int pos, char a, string&  s)
{
    int c = a - s[pos];

    int delta = (c * p_pow[pos]) % MOD;
    if(delta < 0)
        delta += MOD;


    // cout << a << ' ' << s[pos] << ' ' << p_pow[pos] << ' ' <<  << delta << endl;

    s[pos] = a;

    update_bit(pos, delta, s.size());
}


signed main()
{

    string s = "abacate";

    hashing(s);


    cout << get_hash(s) << endl;

    switch_char(2, 'b', s); // abbcate

    cout << s << ' ' << get_hash(s) << endl;

    string s1 = "abbcate";
    
    hashing(s1);

    cout << s1 << ' ' <<get_hash(s1) << endl;

    return 0;
}