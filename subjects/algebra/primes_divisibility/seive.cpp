#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

int is_prime[MAX_N];

void fill_primes(int n = MAX_N)
{

    memset(is_prime, 0, sizeof(int) * n);

    for(int i = 2; i < n; i++)
    {
        if(is_prime[i])
            continue;

        for(int j = 2*i; j < n; j += i)
        {
            is_prime[j] = 1;
        }
    }

}

// O(log(log n))
void optimal_fill_primes(int n = MAX_N)
{

    memset(is_prime, 0, sizeof(int) * n);

    for(int i = 2; i*i <= n; i++)
    {
        if(is_prime[i])
            continue;

        for(int j = i*i; j < n; j += i)
        {
            is_prime[j] = 1;
        }
    }

}

signed main()
{

    optimal_fill_primes();

    for(int i = 0;i < 100; i++)
        cout << is_prime[i] << ' ';

    return 0;
}