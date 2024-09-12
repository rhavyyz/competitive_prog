/*
We approach this problem from a different angle: for every not yet selected vertex we will store the 
minimum edge to an already selected vertex.

Then during a step we only have to look at these minimum weight edges, which will have a complexity of  

$O(n)$ .

After adding an edge some minimum edge pointers have to be recalculated. Note that the weights only c
an decrease, i.e. the minimal weight edge of every not yet selected vertex might stay the same, or it 
will be updated by an edge to the newly selected vertex. Therefore this phase can also be done in  

$O(n)$ .

Thus we received a version of Prim's algorithm with the complexity  
$O(n^2)$ .

*/
// Better for graphs with tons of edges
#include<bits/stdc++.h>
using namespace std;




int n;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;
}
