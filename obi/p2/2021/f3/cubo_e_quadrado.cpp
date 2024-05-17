#include<bits/stdc++.h>

using namespace std;

int main()
{

    int a, b; cin >> a >> b;

    int ans = 0;

    int begin = sqrt(a);

    if(begin * begin < a)
        begin++;


    for(int i = begin; i * i <= b; i++)
    {
        int pow2 = i * i;

        for(int a = 1; a <= i + 1; a++)
        {
            if(a * a * a == pow2)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}