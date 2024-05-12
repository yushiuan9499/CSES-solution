// Problem: Movie Festival II
// URL: https://cses.fi/problemset/task/1632
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , k , ans = 0;
pair<int,int> a[200005];
multiset<int> s;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	repeat(0,n,i)cin >> a[i].second >> a[i].first;
	sort(a,a+n);
	repeat(0,n,i)
	{
		auto x = s.upper_bound(a[i].second);
		if(x !=  s.begin())
		{
			ans++;
			s.erase(prev(x));
			s.insert(a[i].first);
		}
		else if(s.size() < k)
		{
			ans++;
			s.insert(a[i].first);
		}
	}
	cout << ans;
	return 0;
}