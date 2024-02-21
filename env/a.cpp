#include<bits/stdc++.h>

#define int unsigned int
#define all(A) A.begin(), A.end()

using namespace std;


int solve()
{
	map<int, int> values;


	int a = 1;

	int last_b = (a << 31);

	int n; cin >> n;
	int res = n;
	for(int i =0; i < n; i++)
	{
		int aux; cin >> aux;
		int comple = ~aux;

		auto regular = values.find(comple),
			 plus = values.find(comple + last_b),
			 minus = values.find(comple - last_b);

		if(regular != values.end() && (*regular).second > 0&& comple != aux)
		{
			res--;
			(*regular).second--;
		}
		else if(aux>=last_b && plus != values.end() && (*plus).second > 0 && comple + last_b != aux)
		{
			res--;
			(*plus).second--;
		}
		else if(aux <last_b && minus != values.end() && (*minus).second > 0 && comple - last_b != aux)
		{
			res--;
			(*minus).second--;
		}
		
		if(values.find(aux) != values.end())
			values[aux]++;
		else
			values[aux] = 1;
	}

	if(res < n/2)
	{
		if(n%2)
			res = n/2 + 1;
		else
			res = n/2;
	}

	return res;
}

signed main()
{
	int t; cin >> t;

	while(t--)
		cout << solve() << endl;
	


	return 0;
} 