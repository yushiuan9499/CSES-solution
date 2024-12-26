// Problem: Prime Multiples
// URL: https://cses.fi/problemset/task/2185
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , k , ans = 0 , a[30];

void f(int m , int sgn , int now = 0 , int cnt = 0 , int mul = 1)
{
	if(cnt == m)
	{
		ans += sgn*(n/mul);
		return;
	}
	repeat(now,k,i)
	{
		if(n/mul >= a[i])f(m,sgn,i+1,cnt+1,mul*a[i]);
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	repeat(0,k,i)cin >> a[i];
	for(int i = 1 , j = 1; i <= k ; i++ , j = -j)
	{
		f(i,j);
	}
	cout << ans;
	return 0;
}