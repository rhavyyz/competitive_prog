#include<bits/stdc++.h>

using namespace std;

int main() {

    int x;

    int a = 0;
    int b = 400;
    int c = 800;
    int d = 1200;
    int e = 1600;
    int f = 2000;


    cin >> x;

    if (x == a) {

        cout << "0";
    }
    else if (x > a and x < b) {

        if (b - x > x - a){

            cout << x-a;
        }
        else if (x - a > b - x) {

            cout << b - x;
        }
        else if (x - a == b - x) {

            cout << b - x;
        }

    }


      if (x == c) {

        cout << "0";
    }
    else if (x > c and x < d) {

        if (d - x > x - c){

            cout << x-c;
        }
        else if (x - c > d - x) {

            cout << d - x;
        }
        else if (x - c == d - x) {

            cout << d - x;
        }

    }

    if (x == b) {

        cout << "0";
    }
    else if (x > b and x < c) {

        if (c - x > x - b){

            cout << x-b;
        }
        else if (x - b > c - x) {

            cout << c - x;
        }
        else if (x - b == c - x) {

            cout << c - x;
        }

    }


    if (x == d) {

        cout << "0";
    }
    else if (x > d and x < e) {

        if (e - x > x - d){

            cout << x-d;
        }
        else if (x - d > e - x) {

            cout << e - x;
        }
        else if (x - d == e - x) {

            cout << e - x;
        }

    }

    if (x == e) {

        cout << "0";
    }
    else if (x > e and x < f) {

        if (f - x > x - e){

            cout << x-e;
        }
        else if (x - e > f - x) {

            cout << f - x;
        }
        else if (x - e == f - x) {

            cout << f - x;
        }


    }

    if (x == f) {

        cout << "0";
    }







return 0;
}
