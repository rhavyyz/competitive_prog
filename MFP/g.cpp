// #include<bits/stdc++.h>

// using namespace std;

// int n, m;

// int flowers[10001];
// pair<int, pair<int, int>> ranges[10000];



// int main()
// {
//     cin >> n >> m;

//     for(int i = 0; i < n; i++)
//     {
//         int aux1, aux2; cin >> aux1 >> aux2;

//         // ignore ranges with size one
//         if(aux2 - aux1 == 0)
//         {
//             m--; i--;
//             continue;
//         }

//         ranges[i].first = aux2 - aux1 + 1;
//         ranges[i].second.first = aux1;
//         ranges[i].second.second = aux2;
//     }

//     sort(ranges, ranges+ m);

//     for(int i = 0; i < m; i++)
//     {
//         auto [l, r] = ranges[i].second;
//         l--; r--;

//         for(; l<= r; l++)
//         {
//             flowers[i];
//         }
//     }


//     return 0;
// }