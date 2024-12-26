// Problem: Christmas Party
// URL: https://cses.fi/problemset/task/1717
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M = 1e9+7;
int n , ans = 0;
int c[1000006];

int pow(int x , int y)
{
	if(y==0)return 1;
	if(y&1)return x*pow(x,y-1)%M;
	int ret = pow(x,y/2);
	return ret*ret%M;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	c[0] = c[1] = 1;
	repeat(2,n+1,i)c[i] = i*c[i-1]%M;
	for(int i = n , j = 1 ; i >= 0 ; i-- , j = -j)
	{
		ans += j*c[i]*c[n]%M*pow(c[n-i],M-2)%M*pow(c[i],M-2)%M;
		ans %= M;
		ans = (ans+M)%M;
	}
	cout << ans;
	return 0;
}