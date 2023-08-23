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
int coins[1001];

const int SIZE = 1e6 + 1; 
const int MAX = SIZE;

int dp[SIZE];
int n; // logic size of dp

int minimun(int res)
{
    if (res == 0) return 0;

    if(res < 0) return MAX;

    if(dp[res]) return dp[res];

    int min = MAX;

    for(int i=0; i < n; i++)
    {
        int aux = minimun(res - dp[i]);

        if(min > aux) min = aux;
    }

    if(min == MAX) return dp[res] = MAX;

    return dp[res] = min + 1;
}

int solve(){

    int x; cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> coins[i];

    // sort(coins , coins + n); //greater<int>()); //  Sorts the array backwards
    
    int res = minimun(x);
    
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