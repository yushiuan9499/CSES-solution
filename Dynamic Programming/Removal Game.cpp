// Problem: Removal Game
// URL: https://cses.fi/problemset/task/1097
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , a[5003];
int dp[5003][5003] = {0};

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> a[i],dp[i][i] = a[i];
	repeat(1,n,d)
	{
		repeat(0,n-d,l)
		{
			dp[l][l+d] = max(min(dp[l][l+d-2],dp[l+1][l+d-1])+a[l+d],min(dp[l+2][l+d],dp[l+1][l+d-1])+a[l]);
		}
	}
	cout << dp[0][n-1];
	return 0;
}