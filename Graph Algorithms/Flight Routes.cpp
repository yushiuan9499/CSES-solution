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
multiset<int> d[200005];
vector<pair<int,int> > adj[200005];

void f()
{
	priority_queue<pair<int,int> > pq;
	d[1].insert(0);
	d[n].insert(0x3f3f3f3f3f);
	pq.push(mp(0,1));
	while(!pq.empty() && -1*pq.top().first < *d[n].rbegin())
	{
		int now = pq.top().second;pq.pop();
		for(pair<int,int> nxt : adj[now])
		{
			pq.push(mp(-(*d[now].begin()+nxt.second),nxt.first));
			for(int dd : d[now])
			{
				d[nxt.first].insert(dd+nxt.second);
				if(d[nxt.first].size() > k)
				{
					d[nxt.first].erase(prev(d[nxt.first].end()));
				}
			}
		}
		if(now != n)d[now].clear();
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
	for(int a : d[n])cout << a << " ";
	return 0;
}