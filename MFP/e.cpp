#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ones = 0;
    for(int i = 0; i < 7; i++)
    {
        int aux; cin >> aux;
        ones += aux;
    }

    int flag; cin >> flag;
    
    // 1 -> impar
    // 0 -> par 
    
    if((ones%2==1 && flag == 0) || (ones%2==0 && flag == 1))
        cout << "S" << endl;
    else
        cout << "N?" << endl;

    return 0;
}