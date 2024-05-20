// Problem: Planets Queries I
// URL: https://cses.fi/problemset/task/1750
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q;
int nxt[200005][40];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	repeat(1,n+1,i)cin >> nxt[i][0];
	repeat(1,35,i)
	{
		repeat(1,n+1,j)nxt[j][i] = nxt[nxt[j][i-1]][i-1];
	}
	while(q--)
	{
		int x , k;cin >> x >> k;
		for(int i = 0 ; (1<<i) <= k ; i++)
		{
			if(k&(1<<i))x = nxt[x][i];
		}
		cout << x << "\n";
	}
	return 0;
}