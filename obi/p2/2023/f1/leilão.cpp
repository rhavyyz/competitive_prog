#include<bits/stdc++.h>

using namespace std;

int main()
{

    string s; int maior = -1;
    int n; cin >> n;

    while(n--)
    {
        string aux; int val; cin >> aux >> val;

        if(val > maior)
        {
            s = aux;
            maior = val;
        }
    }

    cout << s << endl << maior << endl;

    return 0;
}