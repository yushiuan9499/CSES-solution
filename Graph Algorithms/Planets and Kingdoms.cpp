// Problem: Planets and Kingdoms
// URL: https://cses.fi/problemset/task/1683
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m;
vector<int> adj[100005] , adj_t[100005];
int comp[100005] = {0} , cnt = 0;
stack<int> s;

void dfs1(int now)
{
	comp[now] = 1;
	for(int nxt : adj[now])
	{
		if(!comp[nxt])dfs1(nxt);
	}
	s.push(now);
	return;
}

void dfs2(int now)
{
	comp[now] = cnt;
	for(int nxt : adj_t[now])
	{
		if(!comp[nxt])dfs2(nxt);
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,m,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);
		adj_t[v].pb(u);
	}
	repeat(1,n+1,i)
	{
		if(!comp[i])dfs1(i);
	}
	memset(comp,0,sizeof comp);
	repeat(0,n,i)
	{
		if(!comp[s.top()])cnt++,dfs2(s.top());
		s.pop();
	}
	cout << cnt << "\n";
	repeat(1,n+1,i)cout << comp[i] << " ";
	return 0;
}