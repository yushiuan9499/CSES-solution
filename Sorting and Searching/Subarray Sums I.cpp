// Problem: Subarray Sums I
// URL: https://cses.fi/problemset/task/1660
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , k;
int a[200005] , r , l , now , ans;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	repeat(0,n,i)cin >> a[i];
	for(ans = now = l = r = 0 ; r < n && l < n ; r++)
	{
		now += a[r];
		while(now > k)now -= a[l++];
		ans += (now ==k);
	}
	cout << ans;
	return 0;
}