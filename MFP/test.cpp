#include<bits/stdc++.h>

using namespace std;

#define double long double 


void d()
{
    double m1, m2; cin >> m1 >> m2;

    double x1, x2; cin >> x1 >> x2;

    double f; cin >> f;

    double d = x1 - x2;
    if(d < 0)
        d = x2 - x1;

    cout << setprecision(10) << fixed;
    cout << f*d*d/(m1*m2) << endl;

}

void e()
{
    int n_1 = 0;

    for(int i = 0; i < 7; i++)
    {
        int aux; cin >> aux;
        if(aux == 1)
            n_1++;
    }

    int seg; cin >> seg;

    if((n_1 % 2 == 0 && seg == 0) || (n_1 % 2 == 1 && seg == 1))
        cout << "N?" << endl;
    else
        cout << "S" << endl;
}

void b()
{
    int heights[200001];
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> heights[i];

    sort(heights, heights + n);

    int higher = -1;

    for(int i = 0; i < n/2; i++)
    {

        int h1 = heights[i];
        int h2 = heights[n-1-i];

        if((h1 + h2)/2 > higher)
            higher = (h1 + h2)/2;
    }

    cout << higher << endl;

}

void c()
{
    int d, m; cin >> d >> m;

    double l = d * sqrt(2);
    double vet = d;

    int div = m/l;

    double x = 0, y = 0;
    int y_direction = 1;

    if(div%2 == 1)
    {
        x+= vet;
        y+= vet;
        y_direction = -1;
        div--;
    }

    x += vet * div;

    double mult = m / l - int(m/l);

    x += mult* vet;

    y += mult * vet * y_direction;

    cout << setprecision(10) << fixed;
    cout << x << ' ' << y << endl;
}

int graph[101];
void dfs(int i, int begin = -1)
{   
    if(i == begin)
        return;

    if(begin == -1)
        begin = i;

    cout << i << ' ';

    dfs(graph[i], begin);
}

void a()
{
    int n; cin >> n;


    for(int i =  1 ; i <= n; i++)
        cin >> graph[i];

    for(int i = 1; i <= n; i++)
    {
        dfs(i);
        cout << endl;
    }

}

int main()
{
    // c();
    int t; cin >> t;

    for(int i = 0; i < t; i++)
        a();
    
    return 0;
}