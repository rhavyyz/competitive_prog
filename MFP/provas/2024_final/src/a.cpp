
vector<string> memo_a(27, "-1");

string dp(int n)
{
  
  if(n == 1)
      return "a";

  if(memo_a[n] != "-1")
    return  memo_a[n];

  string ans  = "a";
  ans[0] = (char)('a' + (n - 1)); 

  return memo_a[n] = dp(n-1) + ans + dp(n-1);
}

signed A()
{
  int n; cin >> n;

  cout << dp(n) << endl;

  return 0;
}
