#include<bits/stdc++.h>

using namespace std;

void compute_lps_array(const string & s, int  arr[])
{
    int n = s.size();

    arr[0] = 0;

    int i = 1;
    int len = 0;
    while(i < n)
    {
        if(s[len] == s[i])
        {
            arr[i] = ++len;
            i++;
        }
        else if(len != 0)
            len = arr[len-1];
        else
            arr[i++] = 0;
    }
}

int lps[10000000];
int KMP(const string & s, const string & pat, int lps[])
{
    int occur = 0;
    int n = s.size();
    int m = pat.size();

    int i = 0, j = 0;

    while(!(m - j > n - i) )
    {
        if(s[i] == pat[j])
        {
            i++;j++;

            if(j == m)
            {
                occur++;
                j = lps[j-1];
            }
        }
        else if(j!= 0)
            j = lps[j-1];
        else
            i++;
    }

    return occur;
}

int main()
{

    string source, pat;
    cin >> source >> pat;


    compute_lps_array(pat, lps);

    cout << KMP(source, pat, lps) << endl;

    return 0;
}