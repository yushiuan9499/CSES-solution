// Problem: Finding a Centroid
// URL: https://cses.fi/problemset/task/2079
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , sz[200005] , c = 0;
vector<int> adj[200005];

int dfs(int now = 1 , int fa = 1)
{
	sz[now] = 1;int res , mx = 0;
	for(int son : adj[now])
	{
		if(son != fa)
		{
			res = dfs(son,now);
			mx = max(mx,res);
			sz[now] += res;
		}
	}
	if(max(mx,n - sz[now]) <= n/2)c = now;
	return sz[now];
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);adj[v].pb(u);
	}
	dfs();
	cout << c;
	return 0;
}