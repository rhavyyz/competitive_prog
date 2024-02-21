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

char table[1001][1001];
int n, m;

struct point
{
	int y, x;

	point operator+(point p)
	{
		return { y + p.y, x + p.x };
	}

};

inline bool isInRange(point p)
{
	return 
		p.x >= 0 && 
		p.x < m &&
		p.y >= 0 && 
		p.y < n
	;
}

vector<point> steps = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};

bool visitRoom(point p)
{

	if(!isInRange(p) || table[p.y][p.x] != '.') return false;

	table[p.y][p.x] = 'L';

	for(auto step :steps)
		visitRoom(p + step);

	return true;

}

int solve(){
	cin >> n >> m;

	vector<point> points;

	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			// cout << 1;

			char aux; cin >> aux;
			// cout << 2;

			// cout << "leu";

			table[y][x] = aux;
			// cout << table[y][x];

			if(table[y][x] == '.') points.push_back({y, x});
		}
		// cout << endl;
	}

	// cout << "Codigo" << endl;


	int cont = 0;

	for(auto p : points)
	{
		if(visitRoom(p))
			cont++;
	}

	cout << cont << endl;
			
    return 0;
}

signed main(){
	// ios_base::sync_with_stdio(false);cin.tie(NULL);

	// int t;

	// //cin>>t; //*/
	// t = 1; //*/
	// while(t--) 
    solve();

	return 0;
}