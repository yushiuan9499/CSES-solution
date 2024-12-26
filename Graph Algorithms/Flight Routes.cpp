// Problem: Flight Routes
// URL: https://cses.fi/problemset/task/1196
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m , k;
priority_queue<int> d[200005];
vector<pair<int,int> > adj[200005];
stack<int> ans;

void f()
{
	priority_queue<pair<int,int> > pq;
	d[1].push(0);
	pq.push(mp(0,1));
	while(!pq.empty())
	{
		pair<int,int> p = pq.top();pq.pop();
		int now;
		if(-p.first > d[now = p.second].top())continue;
		for(pair<int,int> nxt : adj[now])
		{
			int tmp = -p.first+nxt.second;
			if(d[nxt.first].size() < k)
			{
				d[nxt.first].push(tmp);
				pq.push(mp(-(tmp),nxt.first));
			}
			else if(tmp < d[nxt.first].top())
			{
				d[nxt.first].pop();
				d[nxt.first].push(tmp);
				pq.push(mp(-(tmp),nxt.first));
			}
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	repeat(0,m,i)
	{
		int u , v , c;cin >> u >> v >> c;
		adj[u].pb(mp(v,c));
	}
	f();
	while(!d[n].empty())
	{
		ans.push(d[n].top());
		d[n].pop();
	}
	while(!ans.empty())
	{
		cout << ans.top() << " ";ans.pop();
	}
	return 0;
}