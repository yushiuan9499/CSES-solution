// Problem: Reading Books
// URL: https://www.cses.fi/problemset/task/1631
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , mx = 0 , sum = 0;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)
	{
		int a;cin >> a;
		mx = max(mx,a);
		sum += a;
	}
	cout << max(mx*2,sum);
	return 0;
}