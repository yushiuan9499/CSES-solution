// Problem: Room Allocation
// URL: https://cses.fi/problemset/task/1164
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n;
int mx = 0 , cnt = 0 , ans[200005];
pair<int , pair<bool,int > > a[400005];
queue<int> q;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)
	{
		int s , e;cin >> s >> e;
		a[i<<1] = mp(s,mp(1,i));a[(i<<1)|1] = mp(e+1,mp(0,i));
	}
	sort(a,a+2*n);
	repeat(0,2*n,i)
	{
		if(!a[i].second.first)q.push(ans[a[i].second.second]);
		else
		{
			if(q.empty())mx++,q.push(mx);
			ans[a[i].second.second] = q.front();q.pop();
		}
	}
	cout << mx << "\n";
	repeat(0,n,i)cout << ans[i] << " ";
	return 0;
}