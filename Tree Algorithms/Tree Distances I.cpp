// Problem: Tree Distances I
// URL: https://cses.fi/problemset/task/1132
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , mx[200005] , mx2[200005], ans[200005] = {0};
vector<int> adj[200005];

int dfs1(int now , int fa)
{
	mx[now] = mx2[now] = 0;
	for(int son : adj[now])
	{
		if(son == fa)continue;
		int res = dfs1(son,now);
		if(res >= mx[now])mx2[now] = mx[now],mx[now] = res;
		else if(res > mx2[now])mx2[now] = res;
	}
	return mx[now] + 1;
}

void dfs2(int now , int fa , int m)
{
	ans[now] = max(mx[now],m);
	for(int son : adj[now])
	{
		if(son == fa)continue;
		if(mx[now] == mx[son] + 1)dfs2(son,now,max(m+1,mx2[now]+1));
		else dfs2(son,now,max(m+1,mx[now]+1));
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
	repeat(1,n+1,i)cout << ans[i] << " ";
	return 0;
}