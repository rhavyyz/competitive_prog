#include<bits/stdc++.h>

using namespace std;

int rositas[200001];

int main()
{

    int n; cin >> n;

    for(int i = 0; i < n; i++)
        cin >> rositas[i];

    sort(rositas, rositas+n);


    int higher = -1;

    for(int i = 0; i < n/2; i++)
    {
        int left = rositas[i];
        int  right = rositas[n-1-i];
    
        higher = max(higher, (left + right)/2);
    }

    cout << higher<< endl;

    return 0;
}