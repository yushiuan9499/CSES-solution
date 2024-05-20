// Problem: Tasks and Deadlines
// URL: https://cses.fi/problemset/task/1630
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , ans = 0 , now = 0;
pair<int,int> a[200005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> a[i].first >> a[i].second;
	sort(a,a+n);
	repeat(0,n,i)
	{
		now += a[i].first;
		ans += a[i].second - now;
	}
	cout << ans;
	return 0;
}