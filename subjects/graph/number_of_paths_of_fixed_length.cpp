/*
    let G be the adjascence matrix of a graph. the number of paths of for each vertex to another
    can be made as G^K. the paths from i to j are G[i][j]
*/
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> mult(const vector<vector<int>> & m1, const vector<vector<int>> & m2)
{
    vector<vector<int>> ans(m1.size());
    for (auto & line : ans)
        line.resize(m2[0].size(), 0);

    for (int  i = 0; i < ans.size(); i++)
        for (int  j = 0; j < ans[0].size(); j++)
            for(int k = 0; k < m2.size(); k++)
                ans[i][j] += m1[i][k] * m2[k][j];

    return ans;
}

vector<vector<int>> exp_mat(const vector<vector<int>> & g, int n)
{
    if(n==1)
        return g;

    auto half = exp_mat(g, n/2);
    half = mult(half, half);

    if(n%2)
        half = mult(half, g);

    return half;
}



int main()
{




    return 0;
}