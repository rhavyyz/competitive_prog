#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    queue<int> fila;

    while(n--)
    {
        int aux; cin >> aux;
        fila.push(aux);
    }

    int m; cin >> m;
    set<int> s;

    while(m--)
    {
        int aux; cin >> aux;
        s.insert(aux);
    }

    while(!fila.empty())
    {

        int el = fila.front();
        fila.pop();

        if(s.count(el) == 0)
            cout << el << ' ';

    }

    cout << endl;

    return 0;
}