// Problem: Flight Routes Check
// URL: https://cses.fi/problemset/task/1682
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
stack<int> s;
bool vst[100005] = {0};
int cnt = 0;
int ans[2];

void dfs1(int now)
{
	if(vst[now])return;
	vst[now] = 1;
	for(int nxt : adj[now])dfs1(nxt);
	s.push(now);
	return;
}

void dfs2(int now)
{
	if(vst[now])return;
	vst[now] = cnt;
	for(int nxt : adj_t[now])dfs2(nxt);
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
	repeat(1,n+1,i)dfs1(i);
	memset(vst,0,sizeof vst);
	repeat(0,n,i)
	{
		if(!vst[s.top()])ans[cnt++] = s.top(),dfs2(s.top());
		s.pop();
		if(cnt > 1)
		{
			cout << "NO\n";
			cout << ans[1] << " " << ans[0];
			return 0;
		}
	}
	cout << "YES";
	return 0;
}