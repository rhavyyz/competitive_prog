#include<bits/stdc++.h>

using namespace std;

/*


    0 -> ab

    1 -> aba

*/



int main()
{
    int n; cin >> n;
    string s;
    cin >> s;

    string ans = "";
    bool corrupted = false;

    int i = s.size() -1;
    while(i >=1)
    {
        if(s[i] == 'b' && s[i-1] == 'a')
        {
            ans = "0" + ans;
            i-= 2;
            continue;
        }
        else if (s[i] == 'a' && s[i-1] == 'b' && i-2 >= 0 && s[i-2] == 'a') 
        {
            ans = "1" + ans;
            i-= 3;
            continue;
        }


        corrupted = true;
        break;
    }

    if(corrupted || n == 1)
        cout << ":(" << endl;

    else
        cout << ans << endl;

    return 0;
}