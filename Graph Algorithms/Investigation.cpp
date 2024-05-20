// Problem: Investigation
// URL: https://cses.fi/problemset/task/1202
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M = 1e9+7;
int n , m , lo[100005] , sh[100005] , dp[100005] , d[200005];
bool vst[100005] = {0};
vector<pair<int,int> > adj[100005];
priority_queue<pair<int,int> > q;

void f()
{
	memset(d,0x3f,sizeof d);
	d[1] = lo[1] = sh[1] = 0;dp[1] = 1;
	q.push(mp(0,1));
	while(!q.empty())
	{
		int now = q.top().second;q.pop();
		if(vst[now])continue;vst[now] = 1;
		if(now == n)return;
		for(pair<int,int> nxt : adj[now])
		{
			if(d[nxt.first] == d[now] + nxt.second)
			{
				dp[nxt.first] = (dp[nxt.first]+dp[now])%M;
				lo[nxt.first] = max(lo[now]+1,lo[nxt.first]);
				sh[nxt.first] = min(sh[now]+1,sh[nxt.first]);
			}
			else if(d[nxt.first] > d[now] + nxt.second)
			{
				d[nxt.first] = d[now] + nxt.second;
				dp[nxt.first] = dp[now];
				lo[nxt.first] = lo[now]+1;
				sh[nxt.first] = sh[now]+1;
				q.push(mp(-d[nxt.first],nxt.first));
			}
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,m,i)
	{
		int a , b , c;cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
	}
	f();
	cout << d[n] << " " << dp[n] << " " << sh[n] << " " << lo[n];
	return 0;
}