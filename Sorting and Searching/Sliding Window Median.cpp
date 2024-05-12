// Problem: Sliding Window Median
// URL: https://cses.fi/problemset/task/1076
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , k , a[2000005];
multiset<int> s1 , s2;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	repeat(0,n,i)cin >> a[i];
	repeat(0,n,i)
	{
		if(s2.empty() || a[i] < *s2.begin())
		{
			s1.insert(a[i]);
			while(2*s1.size() > k+1)s2.insert(*s1.rbegin()),s1.erase(prev(s1.end()));
		}
		else
		{
			s2.insert(a[i]);
			while(2*s2.size() > k)s1.insert(*s2.begin()),s2.erase(s2.begin());
		}
		if(i+1 >= k)
		{
			cout << *s1.rbegin() << " ";
			if(s2.empty() || a[i-k+1] < *s2.begin())s1.erase(s1.find(a[i-k+1]));
			else s2.erase(s2.find(a[i-k+1]));
		}
	}
	return 0;
}