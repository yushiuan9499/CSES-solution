// Problem: Planets Queries II
// URL: https://cses.fi/problemset/task/1160
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q , nxt[200005][40];
int dep[200005] = {0}, id[200005] , cnt = 0 , cnt2 , sz[200005];
bool vst[200005] = {0};

int dfs(int now)
{
	if(dep[now])
	{
		return 0;
	}
	if(vst[now])
	{
		cnt--;
		cnt2 = 0;
		return now;
	}
	vst[now] = 1;
	int res = dfs(nxt[now][0]);
	if(res)
	{
		id[now] = cnt2++;
		dep[now] = cnt;
		if(res==now)
		{
			sz[-cnt] = cnt2;
			return 0;
		}
		return res;
	}
	else
	{
		dep[now] = max(dep[nxt[now][0]],(int)0)+1;
		return 0;
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	repeat(1,n+1,i)cin >> nxt[i][0];
	repeat(1,35,i)
	{
		repeat(1,n+1,j)nxt[j][i] = nxt[nxt[j][i-1]][i-1];
	}
	repeat(1,n+1,i)
	{
		if(!vst[i])dfs(i);
	}
	//repeat(1,n+1,i)cout << dep[i] << " ";
	while(q--)
	{
		int u , v;cin >> u >> v;
		if(dep[u] < dep[v])cout << "-1\n";
		else if(dep[v] > 0)
		{
			int d = dep[u] - dep[v];
			for(int i = 1 , j = 0 ; i <= d ; i <<= 1 , j++)
			{
				if(i&d)u = nxt[u][j];
			}
			cout << (u==v?d:-1) << "\n";
		}
		else if(dep[v] < 0 && dep[u] > 0)
		{
			int d = dep[u];
			for(int i = 1 , j = 0 ; i <= d ; i <<= 1 , j++)
			{
				if(i&d)u = nxt[u][j];
			}
			cout << (dep[u]==dep[v]?(d+(sz[-dep[u]]+id[u]-id[v])%sz[-dep[u]]):-1) << "\n";
		}
		else if(dep[u] == dep[v])cout << (sz[-dep[u]]+id[u]-id[v])%sz[-dep[u]] << "\n";
		else cout << "-1\n";
	}
	return 0;
}