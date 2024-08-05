#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;

    int last; cin >> last;

    queue<int> fila;

    n--;
    while(n--)
    {
        int aux; cin >> aux;
        fila.push(aux);
    }

    int tot = 0;

    while(!fila.empty())
    {
        int curr = fila.front();
        fila.pop();

        tot += min(10, curr - last);

        last = curr;
    }

    cout << tot + 10;

    return 0;
}