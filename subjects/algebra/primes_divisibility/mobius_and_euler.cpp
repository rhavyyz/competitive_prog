#include <bits/stdc++.h>


using namespace std;

const int MAX_N = 1e7;


int mobius[MAX_N];
int is_prime[MAX_N];
int phi[MAX_N];


    /*
    
        Mobius is used to do the mobius inversion.
        
        This is a trick based around the Dirichet convolution.

        Basicly it is a way of, creating a new sequence of numbers basend on 2 sequences already given.
        These sequences can be represented as functions of the form f: N -> C.
        
        The Derichlet convolution forms the following pattern

        given, f(x), g(x), their convolution function whould be of the form
                  
        conv(x) = Σ f(d) * g(x/d) 
                 d|x  

        So, for every divisor d, you apply d to f and the complement of d to g, multiplying these values.

        There is a very interesting function to this convolution that is 1 bar, just f(x) = 1.
        If you use this function you can just convolve a function with some king of neutral function that applys it to every divisor of your input value.

        This operation under some constraints and up being a group, meaning that for some functions we can invert it. Doing something like:
       
        here * means the convolution

        (1 bar * f) * μ = f.

        In this case μ = 1 bar ^ -1. And you could get back your f function.
        This μ is the mobius function

        In practice, it is of form:

        μ(n) = n = 1 => 1
               
               ∃ p^2|n , p is a prime that divides n => 0 

               else => (-1)^k , let k be the number of distinct primes that divide n              


    */
    /*
    
        The phi function is a function that points the number of numbers c in the range [1, n] that respect gcd(c, n) = 1.

        The way of alculation this is:with

        let k be the number os distinct primes of n and αi the number of times the ith prime needs to be 
        multiplied to properly form n
                                      k
        phi(n) = n * ∏ ( 1 - 1/p ) = ∏ (pi ^ (αi - 1)) *  (pi - 1) 
                    p|n              i=i
                    ^                              ^
                    |                              | 
                Better with seive           Better with individual numbers
    */

void seive_with_mobius_and_euler() {
    for(int i = 0; i < MAX_N; i++) {
        is_prime[i] = 1;
        mobius[i] = 1;
        phi[i] = i;
    }

    for(int i = 2; i < MAX_N; i++) {
        if(is_prime[i]) {

            for(int j = i ; j < MAX_N; j += i) {
                if(j % (i*i) == 0) {
                    mobius[j] = 0;
                }

                if (j != i)
                    is_prime[j] = 0;

                mobius[j] *= -1;

                //

//                  Since j is multiple of i its save
//                          |
//                          v
                phi[j]  = (phi[j]/i) * (i -1) ;

                //

            }
        }
    }
}



int main() {



    return 0;
}
