// Problem: Increasing Subsequence
// URL: https://cses.fi/problemset/task/1145
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , a;
vector<int> dp;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)
	{
		cin >> a;
		int x = lower_bound(dp.begin(),dp.end(),a) - dp.begin();
		if(x == dp.size())dp.pb(a);
		else dp[x] = a;
	}
	cout << dp.size();
	return 0;
}