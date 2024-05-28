// Problem: Sum of Divisors
// URL: https://cses.fi/problemset/task/1082
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , ans = 0;
const int M = 1e9+7;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1 ; n >= i*i ; i++)
	{
		ans += (i*((n/i)%M - i + 1))%M;
		ans %= M;
		if(n != i*i)ans += (M+((i+1+(n/i)%M)*((n/i)%M-i)/2)%M)%M;
		ans %= M;
	}
	cout << (ans+M)%M;
	return 0;
}