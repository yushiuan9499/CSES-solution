// Problem: Projects
// URL: https://cses.fi/problemset/task/1140
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , mx = 0 , ans = 0;
pair<pair<int,int> , int >  a[200005];
set<pair<int , int> > s;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)
	{
		cin >> a[i].first.first >> a[i].first.second >> a[i].second;
	}
	sort(a,a+n);
	repeat(0,n,i)
	{
		while(!s.empty() && (*s.begin()).first < a[i].first.first)mx = max(mx,(*s.begin()).second),s.erase(s.begin());
		s.insert(mp(a[i].first.second,a[i].second + mx));
		ans = max(ans,a[i].second + mx);
	}
	cout << ans << "\n";
	return 0;
}