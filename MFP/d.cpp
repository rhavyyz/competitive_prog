#include<bits/stdc++.h>

using namespace std;


// Usei long double por ser o tipo de dado com maior precisao ao lidar com
// numeros com casa decimal
#define double long double


// So aplicar a formula que e dada no enunciado da questao 
int main()
{
    double m1, m2, x1, x2, f;

    cin >> m1 >> m2 >> x1 >> x2 >> f;

    double d = x1 - x2;

    if(d< 0)
        d *= -1;

    double d2 = d*d;

    double G = f*d2 / (m1*m2);

    cout << setprecision(10) << fixed << G << endl;


    return 0;
}
