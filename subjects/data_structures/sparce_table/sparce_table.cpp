#include<bits/stdc++.h>

using namespace std;


/*
    Sparce tables can be used to do all sorts of range queries in a
    array without updates. But the thig is, it can do queries of minimun 
    and maximum inside a range in consntant time so it is really only
    worth for this

    mixed with bb it can be used to find por example the next element 
    on the array that is lass than arr[i] in O(log n) as shown in
    next_larger_element.cpp file
*/


/*
    The main ideia is to store every power of two sized range result for every position
    so its possible to compute a query composing a range by its powers of two parts.
    considering the minimum and maximum operations we can make this query in O(1) because
    its possible to just get two big preprocessed chuncks that cover the entire range,
    (maybe even with a overlaping space) and with this return the result.
*/

const int N = 10^6; // elements on the array
const int K = 25; // powers of 2

// st[j][i] means te minimum at the range
//      [i, i + 2^j-1]
int st[K+1][N];
int arr[N];

int log_floor(int x);

void build()
{
    // For all ranges with j==0 the own element is gonna be the minimun
    copy(arr, arr+N, st[0]);

    for(int j = 1; j <= K; j++)
        // less or equal because of i+2^j-1
        for(int i = 0; i + (1 << j) <= N; i++)
            st[j][i] = min(st[j-1][i] , st[j-1][i + (1 << (j-1))]);
}

int get_min(int l ,int r)
{
    int power = log_floor(r-l+1);


    return min(st[power][l], st[power][r+1-(1 << power)]);
}

// fast way to find integer log
#include<bit>
int log_floor(int x) { 
    return __bit_width(x) - 1;

    // pre c++ 20
    return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;    
}
