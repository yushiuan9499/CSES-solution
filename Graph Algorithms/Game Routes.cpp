// Problem: Game Routes
// URL: https://cses.fi/problemset/task/1681
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m;
int dp[100005] = {0};
bool vst[100005];
vector<int> adj[100005] , a;
const int M=1e9+7;

void dfs(int now)
{
	if(vst[now])return;
	vst[now] = 1;
	for(int nxt : adj[now])dfs(nxt);
	a.pb(now);
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
	}
	repeat(1,n+1,i)
	{
		dfs(i);
	}
	dp[1] = 1;
	repeat(0,n,i)
	{
		for(int nxt : adj[a[n-i-1]])
		{
			dp[nxt] += dp[a[n-i-1]];
			dp[nxt] %= M;
		}
	}
	cout << dp[n];
	return 0;
}