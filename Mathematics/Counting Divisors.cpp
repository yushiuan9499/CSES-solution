// Problem: Counting Divisors
// URL: https://cses.fi/problemset/task/1713
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int t , ans , n ,nn;
int a[1000006] = {0};

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;nn = n;
		ans = 1;
		for(int i = 2 ; n >= i*i; i++)
		{
			if(a[n]){ans *= a[n];n = 1;break;}
			int cnt = 0;
			while(n%i == 0)cnt++,n /= i;
			ans *= (cnt+1);
		}
		a[nn] = ans*(n!=1?2:1);
		cout << a[nn] << '\n';
	}
	return 0;
}