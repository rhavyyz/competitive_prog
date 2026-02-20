#include <bits/stdc++.h>

using namespace std;


int is_prime[(int)1e7 + 1];
int u[(int)1e7 + 1];


void sieve(int n) {
    for(int i = 1; i <= n; i++)
        u[i] = is_prime[i] = 1;
    
    
    for(long long int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            for(int j  = i ; j <= n; j+=i) {
                if (j != i)
                    is_prime[j] = 0;
                    
                if(j % (i* i) == 0)  u[j] = 0;
                u[j] *= -1;
            }
        }
    }

}

int main() {

    int a, b, c, d; cin >> a >> b >> c >> d;


    int range = min(b, d);

    sieve(range);

    long long int ans = 0;

    for(int i = 1; i<= range; i++) {

        long long int first_bound = b/i - (a-1)/i;

        long long int  second_bound = d/i - (c-1)/i;

        ans += first_bound * second_bound * u[i];
    }

    cout << ans << std::endl;

    return 0;
}

