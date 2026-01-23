
#define INF 1e15
signed F()
{

  int n, m, start, stop; cin >> n >> m >> start >> stop;

  typedef vector<vector<pair<int, int>>> graph_type;

  graph_type g(n+1);

  while(m--)
  {
    int u, v, w; cin >> u >> v >> w;

    g[u].push_back({v, w});
  }

  
  // Adapted Djikstra
  vector<int> weights (n+1, -1);
  priority_queue<pair<int, int>> order;

  order.push({INF, start});

  while(order.size())
  {
    auto [weight, node] = order.top();
    order.pop();

    if(weights[node] != -1)
        continue;

    weights[node] = weight;
    
    for (auto [next_node, next_weigth] : g[node])
      order.push({min(next_weigth, weight), next_node});
    
  }

  cout << weights[stop] << endl;

  return 0;
}
