#include<bits/stdc++.h>

using namespace std;

int main()
{
    int street, n; cin >> street >> n;

    int last; cin >> last;
    int bigger = last; 

    for(int i = 1; i < n; i++)
    {
        int aux; cin >> aux;

        int diff = aux - last;

        int size = diff/2 + diff%2;

        bigger = max(bigger, size);

        last = aux;
    }

    bigger = max(bigger, street - last);

    cout << bigger << endl;

    return 0;
}