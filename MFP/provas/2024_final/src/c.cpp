signed C()
{
  int a, b; cin >> a >> b;

  for(int i = 1; i <= a; i++)
  {
    if(a%i == 0)
    {
      int qtd = a/i;
      if((qtd-1) * i <= i)  
        return cout << i << endl, 0;
    }
  }

  return 0;
}
