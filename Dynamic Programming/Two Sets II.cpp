// Problem: Two Sets II
// URL: https://cses.fi/problemset/task/1093
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n;
int dp[200005][2] = {0};
const int M = 1e9+7;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	dp[1][1] = 1;
	repeat(2,n+1,i)
	{
		repeat(0,i,j)dp[j][i&1] = dp[j][!(i&1)];
		repeat(i,n*(n+1)/4+1,j)
		{
			dp[j][i&1] = (dp[j][!(i&1)] + dp[j-i][!(i&1)])%M;
		}
	}
	//repeat(0,n*(n+1)/4+1,i)cout << dp[i][n&1] << " ";
	cout << ((n&3 && (n+1)&3)?0:dp[n*(n+1)/4][n&1]);
	return 0;
}