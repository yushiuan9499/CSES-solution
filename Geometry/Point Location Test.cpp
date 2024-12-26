// Problem: Point Location Test
// URL: https://cses.fi/problemset/task/2189
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int t , x[3] , y[3];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--)
	{
		repeat(0,3,i)cin >> x[i] >> y[i];
		int res = (x[1] - x[0])*(y[2] - y[0]) - (x[2] - x[0])*(y[1] - y[0]);
		if(res > 0)cout << "LEFT\n";
		else if(res == 0)cout << "TOUCH\n";
		else cout << "RIGHT\n";
	}
	return 0;
}