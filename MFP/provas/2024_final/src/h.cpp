signed H()
{

  int n , k; cin >> n >> k;

  vector<pair<int, int>> order;
  queue<int> waiting;
  set<int> attendingd;


  for(int i = 0; i < n; i++)
  {
    int start, duration; cin >> start >> duration;
    order.push_back({start, duration});
  }

  sort(order.begin(), order.end());

  int concurrent= 0; 
  for(auto el : order)
  {
    auto [start, duration] = el;
    while(attendingd.size() && start >= *attendingd.begin())
    {
      int end_of = *attendingd.begin();
      attendingd.erase(end_of);
      if(waiting.size())
      {
        attendingd.insert( waiting.front()+end_of);
        waiting.pop();
      }  
      else 
        k++;
    }

    if(k)
    {
      attendingd.insert(el.first + el.second);
      k--;
    }
    else 
      waiting.push(el.second);

    concurrent = max( concurrent,(int) (attendingd.size() + waiting.size()));
  }

  cout << concurrent << endl;
  return 0;
}
