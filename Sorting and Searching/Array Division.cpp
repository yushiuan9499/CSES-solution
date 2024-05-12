// Problem: Array Division
// URL: https://cses.fi/problemset/task/1085
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , k , a[2000005] , ans = 0;

bool f(int x)
{
	int now = 0 , ret = 1;
	repeat(0,n,i)
	{
		if(a[i] > x)return 1;
		if(now+a[i] > x)now = a[i],ret++;
		else now += a[i];
	}
	return ret > k;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	repeat(0,n,i)cin >> a[i];
	for(int jump = 1e18 ; jump ; jump >>= 1)
	{
		while(f(ans+jump))ans += jump;
	}
	cout << ans+1;
	return 0;
}