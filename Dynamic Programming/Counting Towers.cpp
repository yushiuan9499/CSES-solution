// Problem: Counting Towers
// URL: https://cses.fi/problemset/task/2413
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int t , n , now = 1 , dp[1000006][2];
const int M = 1e9+7;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	dp[1][0] = dp[1][1] = 1;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(;now < n;now++)
		{
			dp[now+1][0] = (2*dp[now][0] + dp[now][1])%M;
			dp[now+1][1] = (dp[now][0] + 4*dp[now][1])%M;
		}
		cout << (dp[n][0]+dp[n][1])%M << "\n";
	}
	return 0;
}