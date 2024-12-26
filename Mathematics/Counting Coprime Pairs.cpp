// Problem: Counting Coprime Pairs
// URL: https://cses.fi/problemset/task/2417
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , ans = 0;
vector<int> pf[1000006];
map<int,vector<int> > m;
map<int,int> cnt;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	repeat(2,1e6+1,i)
	{
		if(!pf[i].size())
		{
			for(int j = i ; j <= 1e6 ;j += i)pf[j].pb(i);
		}
	}
	cin >> n;
	repeat(0,n,i)
	{
		int a;cin >> a;
		for(int f : pf[a])m[f].pb(a);
	}
	for(pair<int,vector<int> >now : m)
	{
		cnt.clear();
		for(int mm : now.second)
		{
			for(int f : pf[mm])
			{
				if(f < now.first)cnt[f]++;
			}
		}
		int sz = now.second.size();
		ans += sz*(sz-1)/2;
		for(pair<int,int> owo : cnt)
		{
			ans -= owo.second*(owo.second - 1)/2;
		}
		cout << ans << " ";
	}
	cout << n*(n-1)/2 - ans;
	return 0;
}