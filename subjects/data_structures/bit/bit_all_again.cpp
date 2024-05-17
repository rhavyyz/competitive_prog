#include<bits/stdc++.h>

using namespace std;

int n;
int values[(int)1e8];
int BITree[(int)1e8 + 1];


void update(int index, int v)
{
    index++;

    for(; index <= n; index+= index & -index)
        BITree[index] +=v ;

}

int get_range(int index)
{
    index++;
    int sum = 0;


    for(; index > 0; index -= index & -index)
        sum += BITree[index];

    return sum;

}

void init_BITree()
{
    for(int i = 0; i <= n; i++)
        BITree[i] = 0;

    for(int i = 0; i < n; i++)
        update(i, values[i]);

}

int main()
{
    n = 10;

    values[0] = 1;
    values[1] = 1;
    values[2] = 1;
    values[3] = 1;
    values[4] = 1;
    values[5] = 1;
    values[6] = 1;
    values[7] = 1;
    values[8] = 1;
    values[9] = 1;

    init_BITree();

    // cout << endl;


    cout << get_range(9) << endl;

    update(9, 2);

    cout << get_range(0) << " ";
    cout << get_range(1) << " ";
    cout << get_range(2) << " ";
    cout << get_range(3) << " ";
    cout << get_range(4) << " ";
    cout << get_range(5) << " ";
    cout << get_range(6) << " ";
    cout << get_range(7) << " ";
    cout << get_range(8) << " ";
    cout << get_range(9) << " ";

    return 0;
}