#define int long long

signed D()
{
  vector<vector<int>> grid(6, vector<int>(6));

  for(auto & a: grid)
    for(auto  & b: a) 
      cin >> b;

  vector<int> mask(6);  

  for(int i = 0; i <= 5; i++)
    mask[i] = i;

  int sum = 0;
  for(int i = 0; i < 6; i++)
    sum += grid[i][mask[i]];
  
  cout << sum << endl;

  vector<int> m = mask;

  while (next_permutation(mask.begin(), mask.end()) )
  {
    int next_sum = 0;

    for(int i = 0; i < 6; i++)
      next_sum += grid[i][mask[i]];

    if( sum < next_sum)
    {
      sum = max(next_sum, sum);
      m = mask;
    }
  }

  cout << sum << endl;
  for(auto a : m)
    cout << a + 1<< ' ';
  cout << endl;
  return 0;
}
