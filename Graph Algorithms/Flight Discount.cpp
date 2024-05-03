// Problem: Flight Discount
// URL: https://cses.fi/problemset/task/1195
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m ;
vector<pair<int,int>> adj[200005];


int f()
{
	bool vst[200005] = {0};
	int d[200005];
	memset(d,0x3f,sizeof d);
	priority_queue<pair<int,int> > pq;
	d[1] = 0;
	pq.push(mp(0,1));
	while(!pq.empty())
	{
		int now = pq.top().second;pq.pop();
		if(now == 1e5+n)return d[(int)1e5+n];
		if(vst[now])continue;
		vst[now] = 1;
		for(pair<int,int> nxt : adj[now])
		{
			if(d[nxt.first] > d[now] + nxt.second)
			{
				d[nxt.first] = d[now] + nxt.second;
				pq.push(mp(-d[nxt.first],nxt.first));
			}
		}
	}
	return -1;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,m,i)
	{
		int u , v , c;cin >> u >> v >> c;
		adj[u].pb(mp(v,c));
		adj[u].pb(mp(1e5+v,c/2));
		adj[(int)1e5+u].pb(mp(1e5+v,c));
	}
	cout << f();
	return 0;
}