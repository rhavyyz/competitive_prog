#include<bits/stdc++.h>

using namespace std;

#define double long double

int main()
{
    int m, z; cin >> z >> m;

    double root = sqrt(2);

    double d = z * root;
    double vet = root* ((double)d) /2; 
    
    // cout << vet << endl;

    double x = 0, y = 0;

    int div = m/d;

    double vety = vet;

    if(div%2==1)
    {
        vety*=-1;
        div--;
        x+=vet;
        y+=vet;
    }

    x+= div* vet;

    double res = m/d - ((double)int(m/d));
    // double n_d = d;

    // double mult = res/n_d;

    x += vet * res;
    y += vety * res;

    cout << setprecision(10) << fixed;
    cout << x << ' ' << y << endl;


    return 0;
}