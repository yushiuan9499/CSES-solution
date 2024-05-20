// Problem: Tree Distances II
// URL: https://cses.fi/problemset/task/1133
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , sz[200005] , sum[200005], ans[200005] = {0};
vector<int> adj[200005];

int dfs1(int now , int fa)
{
	sz[now] = 1;sum[now] = 0;
	for(int son : adj[now])
	{
		if(son == fa)continue;
		sz[now] += dfs1(son,now);
		sum[now] += sum[son] + sz[son];
	}
	return sz[now];
}

void dfs2(int now , int fa , int m)
{
	sum[now] += m;
	for(int son : adj[now])
	{
		if(son == fa)continue;
		dfs2(son,now,sum[now] - sum[son] + n - 2*sz[son]);
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1,1);
	dfs2(1,1,0);
	repeat(1,n+1,i)cout << sum[i] << " ";
	return 0;
}