// Problem: Factory Machines
// URL: https://cses.fi/problemset/task/1620
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , a[200005] , t;
int ans = 0;

bool f(int x)
{
	int ret = 0;
	repeat(0,n,i)
	{
		ret += x/a[i];
		if(ret >= t)return 0;
	}
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> t;
	repeat(0,n,i)cin >> a[i];
	for(int jump = 1e18 ; jump ; jump >>= 1)
	{
		while(f(ans + jump))ans += jump;
	}
	cout << ans + 1;
	return 0;
}