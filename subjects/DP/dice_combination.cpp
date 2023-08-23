#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define ld long double
#define mset(A,X) memset(A,X,sizeof A)
#define bug(x) cerr << #x << "  >>>>>>>  " << x << '\n'
#define sz size()
#define all(A) A.begin(), A.end()

// vector<int> numbers = {6,5,4,3,2,1};

int dp[100000 + 1] = { 0 , 1 , 2, 4, 8 , 16, 32};

// inline int getDpNum(int number)
// {
// 	return number > 0 ? dp[number] : 0;
// }

int cont(int number)
{
	// ALG RECURSIVO

	if(number == 0) return 1;
	if(number < 0) return 0;

	if(dp[number])
		return dp[number];

	int res = 0;

	for(int v = 6; v >= 1; v--)
	{
		res += cont(number - v);
	}
	res %= (1000000000 + 7);

	dp[number] = res;
	return res;

	// // ALG ITERATIVO

	// for(int i = 7; i <= number; i++)
	// {
	// 	for(int v = 6; v >= 1; v--)
	// 		dp[i] += dp[i-v] ;

	// 	dp[i] %= (1000000000 + 7);
	// }

	// return dp[number];
}

int solve(){
   
	int n; cin >> n;

	int res = cont(n);

	cout << res << endl;

    return 0;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int t;

	// cin>>t; //*/
	// // t = 1; //*/
	// while(t--) 
    solve();

	return 0;
}