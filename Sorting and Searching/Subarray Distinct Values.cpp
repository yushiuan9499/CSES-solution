// Problem: Subarray Distinct Values
// URL: https://cses.fi/problemset/task/2428
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , k , a[2000005] , cnt2, l , r , ans;
map<int,int> cnt;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	repeat(0,n,i)cin >> a[i];
	for(ans = cnt2 = l = r = 0 ; r < n && l < n ; r++)
	{
		if(cnt[a[r]] == 0)cnt2++;
		cnt[a[r]]++;
		while(cnt2 > k)
		{
			if(cnt[a[l]] == 1)cnt2--;
			cnt[a[l++]]--;
		}
		ans += r-l+1;
	}
	cout << ans;
	return 0;
}