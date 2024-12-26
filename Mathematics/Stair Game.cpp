// Problem: Stair Game
// URL: https://cses.fi/problemset/task/1099
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int t;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--)
	{
		int k , x = 0;cin >> k;
		repeat(0,k,i)
		{
			int a;cin >> a;
			if(i&1)x ^= a;
		}
		cout << (x?"first\n":"second\n");
	}
	return 0;
}