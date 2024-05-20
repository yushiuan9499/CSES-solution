// Problem: Distinct Colors
// URL: https://cses.fi/problemset/task/1139
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , c[200005] , ans[200005] , cnt = 0 , son[200005] , sz[200005] = {0};
vector<int> adj[200005];
map<int,int> cntc;

int dfs1(int now = 1)
{
	son[now] = -1;sz[now] = 1;
	for(int s : adj[now])
	{
		if(!sz[s])
		{
			sz[now] += dfs1(s);
			if(son[now] == -1 || sz[son[now]] < sz[s])son[now] = s;
		}
	}
	return sz[now];
}

void dfs2(int now = 1 , bool b = 1)
{
	if(b)
	{
		for(int s : adj[now])
		{
			if(sz[s] < sz[now] && s != son[now])dfs2(s,1),cnt = 0,cntc.clear();
		}
		if(son[now] != -1)dfs2(son[now],1);
		for(int s : adj[now])
		{
			if(sz[s] < sz[now] && s != son[now])dfs2(s,0);
		}
		if(cntc[c[now]]++ == 0)cnt++;
		ans[now] = cnt;
	}
	else 
	{
		if(cntc[c[now]]++ == 0)cnt++;
		for(int s : adj[now])
		{
			if(sz[s] < sz[now])dfs2(s,0);
		}
		return;
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> c[i+1];
	repeat(0,n-1,i)
	{
		int a , b;cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs1();
	dfs2();
	repeat(1,n+1,i)cout << ans[i] << ' ';
	return 0;
}
