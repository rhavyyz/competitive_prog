#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int n, m, euler = 0;
vector<pair<int, pair<int, int>>>  edges;

typedef vector<vector<pair<int, int>>> graph_type;


graph_type g;

struct DSU {
    vector<int> parent, height;

    DSU(int n) {

        parent.resize(n);
        height.resize(n, 1);
        for(int i =0; i < n; i++)
            parent[i] = i;
    } 

    int find(int el) {
        if (parent[el] == el)
            return el;

        return parent[el] = find(parent[el]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (height[a] > height[b]) {
            parent[b] = a;
        } else if (height[a] < height[b]) {
            parent[a] = b;
        } else {
            parent[a] = b;
            height[b]++;
        }
    }
};

void kruskal() {
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    
    DSU dsu(n);

    for(auto [weight, nodes] : edges) {
        if (dsu.find(nodes.first) != dsu.find(nodes.second)) {
            dsu.merge(nodes.first, nodes.second);

            g[nodes.first].push_back({nodes.second, weight});
            g[nodes.second].push_back({nodes.first, weight});
        }
    }
}

vector<vector<pair<int, int>>> bl;
vector<pair<int, int>> euler_tour;
vector<int> height;

void dfs(int node, int parent = -1, int w = INF) {
    euler_tour[node].first = euler++;
    if (parent != -1) {
        bl[node][0] = {parent, INF};

        for(int i = 1; i < bl[0].size(); i++) {
            auto [p, p_w] = bl[node][i-1];

            if(bl[p][i - 1].first == -1)
                break;
            
            bl[node][i] = {bl[p][i - 1].first, min(bl[p][i - 1].second, p_w)};
        }
    }


    for(auto [next_node, next_w] : g[node]) {
        if(next_node !=parent)
            dfs(next_node, node, next_w);
    }

    euler_tour[node].second = euler++;
}

int binary_lift() {
    int l = log2(n) + 2;
    bl.resize(n, vector<pair<int, int>>(l, {-1, INF}));
    euler = 0;

    dfs(0);
}

bool is_parent(int p, int c ) {
    return euler_tour[p].first < euler_tour[c].first && euler_tour[p].second > euler_tour[c].second;
}


int min_dist(int n, int u) {
    int ret = INF;
    
    int lca = u, i = 0;

    while(true) {
        if (bl[lca][0].first == -1 || is_parent(lca, n))
            break;
        
        if (bl[lca][i].first == -1 || is_parent(bl[lca][i].first, n)) {
            ret = min(bl[lca][max(0, i-1)].second, ret);
            lca = bl[lca][max(0, i-1)].first;
            i = 0;
        } else i++;
    }

    int lca = n, i = 0;

    while(true) {
        if (bl[lca][0].first == -1 || is_parent(lca, u))
            break;
        
        if (bl[lca][i].first == -1 || is_parent(bl[lca][i].first, u)) {
            ret = min(bl[lca][max(0, i-1)].second, ret);
            lca = bl[lca][max(0, i-1)].first;
            i = 0;
        } else i++;
    }

    return ret;
}


int main() {
    int q;
    cin >> n >> m >> q;

    g.resize(n);
    height.resize(n);
    euler_tour.resize(n);
    edges.resize(m);

    for (auto & a : edges)
        cin >> a.second.first >> a.second.second >> a.first;

    kruskal();
    binary_lift();

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << min_dist(a, b) << endl;
    }

    return 0;
}
