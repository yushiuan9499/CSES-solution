// Problem: Common Divisors
// URL: https://cses.fi/problemset/task/1081
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , mx = 1;
bool a[1000006] = {0};

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,j)
	{
		int x;cin >> x;
		for(int i = 1 ; x >= i*i && x/i > mx ; i++)
		{
			if(x%i)continue;
			if(i > mx && a[i])mx = i;
			if(x/i > mx && a[x/i])mx = x/i;
			a[i] = 1;
			a[x/i] = 1;
		}
	}
	cout << mx;
	return 0;
}