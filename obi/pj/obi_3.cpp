#include<bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;

    vector<int> posicoes(n + 1);

    for(int i = 1; i <= n; i++)
    {
        int aux; cin >> aux;

        posicoes[aux] = i;
    }

    // 0 , 1, 2, 3, 4, 5, ...
    // 1 , 2, 3, 4, 5, 6, ...

    for(int i = 1; i <= n; i++)
        cout << posicoes[i] << endl;

return 0;
}
