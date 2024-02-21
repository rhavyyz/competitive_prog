#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int factors[MAX_N];

void count_factors(int n = MAX_N)
{

    memset(factors, 0, sizeof(int) * n);

    for(int i = 1; i < n; i++)
    {
        for(int j = i; j < n; j+= i)
            factors[j]++;
    }

}


signed main()
{

    count_factors();

    for(int i = 0;i < 100; i++)
        cout << factors[i] << ' ';

    return 0;
}