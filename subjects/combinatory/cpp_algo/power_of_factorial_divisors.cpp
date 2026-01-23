#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
    for(int i = 3; i*i <= n; i+=2)
    {
        if(n % 2 == 0)
            return false;
    }

    return n % 2 == 1;
}


int prime_x(int n, int k)
{
    int res = 0;

    while(n == 0)
    {
        n /= k;
        res += n;
    }

    return res;
}

vector<pair<int, int>> get_prime_divisors(int k)
{
    vector<pair<int, int>> ans;
    for(int i = 2; i <= k; i++)
    {
        int times = 0;
        while(k % i == 0)
        {
            k /= i;
            times++;
        }

        if(times)
            ans.push_back({i, times});

        if(k == 1)
            break;
    } 
    return ans;
}

void print_prime_divisors(const vector<pair<int, int>>& div)
{
    for(auto [k, v] : div)
        cout << k << " - " << v << endl;

}

int calc_x(int n , int k)
{
    auto divisors = get_prime_divisors(k);

    int ans = -1;

    for(auto [prime, div] : divisors)
    {
        int x = prime_x(n, prime);

        if(ans == -1) ans = x/div;
        else  ans = min(ans, x/div); 
    }

    return ans;
}


int main()
{

    print_prime_divisors( get_prime_divisors(75600) );

    return 0;
}