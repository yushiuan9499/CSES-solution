// Problem: High Score
// URL: https://cses.fi/problemset/task/1673
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m , u , v , x;
vector<pair<int,int> > adj[2503];
vector<int> adjt[2503];
bool r[2503] = {0};

void dfs(int now = n)
{
	if(r[now])return;
	r[now] = 1;
	for(int nxt : adjt[now])dfs(nxt);
	return;
}

int f()
{
	int d[2503] , vst[2503] = {0};
	bool inq[2503] = {0};
	memset(d,0x3f,sizeof d);
	queue<int> q;
	d[1] = 0;
	q.push(1);
	while(!q.empty())
	{
		int now = q.front();q.pop();
		if(++vst[now] > n)return -1;
		inq[now] = 0;
		for(pair<int,int> nxt : adj[now])
		{
			if(d[nxt.first] > d[now] + nxt.second && r[nxt.first])
			{
				d[nxt.first] = d[now] + nxt.second;
				if(!inq[nxt.first])q.push(nxt.first),inq[nxt.first] = 1;
			}
		}
	}
	return -d[n];
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,m,i)
	{
		cin >> u >> v >> x;
		adj[u].pb(mp(v,-x));
		adjt[v].pb(u);
	}
	dfs();
	cout << f();
	return 0;
}