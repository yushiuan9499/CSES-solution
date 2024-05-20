// Problem: Distance Queries
// URL: https://cses.fi/problemset/task/1135
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q , fa[200005][30] , dep[200005];
vector<int> adj[200005];

void dfs(int now = 1 , int f = -1 , int d = 0)
{
	fa[now][0] = f;
	dep[now] = d;
	for(int son : adj[now])
	{
		if(son == f)continue;
		dfs(son,now,d+1);
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	fa[1][0] = -1;
	cin >> n >> q;;
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);adj[v].pb(u);
	}
	dfs();
	repeat(1,30,i)
	{
		repeat(1,n+1,j)fa[j][i] = (fa[j][i-1] < 0)?-1:fa[fa[j][i-1]][i-1];
	}
	while(q--)
	{
		int a, b;cin >> a >> b;int aa = a , bb = b;
		if(dep[a] < dep[b])swap(a,b);
		int d = dep[a] - dep[b];
		for(int i = 0 , j = 1 ; j <= d ; i++ , j <<= 1)
		{
			if(d&j)a = fa[a][i];
		}
		for(int jump = 25 ; jump >= 0; jump--)
		{
			while(fa[a][jump] != fa[b][jump])a = fa[a][jump],b = fa[b][jump];
		}
		cout << dep[aa] + dep[bb] - 2*dep[(a==b)?a:fa[a][0]] << "\n";
	}
	return 0;
}