// Problem: Subarray Divisibility
// URL: https://cses.fi/problemset/task/1662
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , a[200005] , cnt[200005] = {0} , ans = 0 , now = 0;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cnt[0] = 1;
	cin >> n;
	repeat(0,n,i)
	{
		cin >> a[i];now = ((a[i]%n)+n+now)%n;
		ans += cnt[now];
		cnt[now]++;
	}
	cout << ans;
	return 0;
}