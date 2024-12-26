// Problem: Word Combinations
// URL: https://cses.fi/problemset/task/1731
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M= 1e9+7;
string s , ss[100005];
int n , dp[5003] = {0} , k;
set<string> se;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s >> k;
	repeat(0,k,i)cin >> ss[i];
	n = s.size();
	sort(ss,ss+k);
	dp[0] = 1;
	repeat(0,n,i)
	{
		if(!dp[i])continue;
		int l = 0 , r = k-1;
		repeat(0,n-i,j)
		{
			for(int jump = k ; jump ; jump >>= 1)
			{
				while(l+jump <= r && ss[l+jump][j] < s[i+j])l += jump;
				while(r-jump >= l && ss[r-jump][j] > s[i+j])r -= jump;
			}
			if(ss[l][j] != s[i+j] && l < k-1)l++;if(ss[r][j] != s[i+j] && r > 0)r--;
			if(l>r)break;
			if(ss[l][j] == s[i+j] && !ss[l][j+1])
			{
				dp[i+j+1] += dp[i];
				dp[i+j+1] %= M;
				l++;
			}
		}
	}
	cout << dp[n];
	return 0;
}