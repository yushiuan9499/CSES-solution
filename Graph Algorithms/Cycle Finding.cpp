// Problem: Cycle Finding
// URL: https://cses.fi/problemset/task/1197
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m;
const int N = 2503;
vector<pair<int,int> > adj[N];
bool c = 0;
int cv , cnt = 0 , tmp[N] = {0};
int from[N];

int SPFA(int u , int v)
{
	queue<int> q;
	bool inq[N] = {0};
	int d[N] , vst[N] = {0};memset(d,0x3f,sizeof d);
	d[u] = 0;
	q.push(u);inq[u] = 1;
	while(!q.empty())
	{
		int now = q.front();q.pop();
		tmp[now] = cnt;
		inq[now] = 0;
		if(vst[now]++ == n)
		{
			c = 1;cv = now;
			return -1;
		}
		for(pair<int,int> nxt : adj[now])
		{
			if(tmp[nxt.first] && tmp[nxt.first] != cnt)continue;
			if(d[nxt.first] > d[now] + nxt.second)
			{
				d[nxt.first] = d[now] + nxt.second;
				from[nxt.first] = now;
				if(!inq[nxt.first])
				{
					q.push(nxt.first);
					inq[nxt.first] = 1;
				}
			}
		}
	}
	return d[v];
}


signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,m,i)
	{
		int u , v , c;cin >> u >> v >> c;
		adj[u].pb(mp(v,c));
	}
	repeat(1,n+1,i)
	{
		if(!tmp[i])
		{
			cnt++;
			SPFA(i,i);
			if(c)
			{
				cout << "YES\n";
				bool vst[N] = {0};
				for(; 1 ; cv = from[cv])
				{
					if(vst[cv])break;
					vst[cv] = 1;
				}
				stack<int> s;s.push(cv);
				for(int j = from[cv]; 1 ; j = from[j])
				{
					s.push(j);
					if(j == cv)
					{
						while(!s.empty())cout << s.top() << " ",s.pop();
						return 0;
					}
				}
			}
		}
	}
	cout << "NO";
	return 0;
}