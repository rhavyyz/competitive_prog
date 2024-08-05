#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n; cin >> n;

    stack<int> s;

    while(n--)
    {
        int aux; cin >> aux;
        
        if(aux == 0)
            s.pop();
        else
            s.push(aux);
    }

    int tot = 0;

    while(!s.empty())
    {
        tot += s.top();
        s.pop();
    }

    cout << tot << endl;

    return 0;
}