// Problem: Line Segment Intersection
// URL: https://cses.fi/problemset/task/2190
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

inline int f(int dx1 , int dy1 , int dx2 , int dy2)
{
	int ret =  dx1*dy2 - dx2*dy1;
	if(ret > 0)return 1;
	if(ret==0)return 0;
	return -1;
}

inline int g(int a , int b)
{
	if(a == 0 || b == 0)return 0;
	return a^b;
}

int t , x[4] , y[4];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--)
	{
		repeat(0,4,i)cin >> x[i] >> y[i];
		if(max(x[0],x[1]) < min(x[2],x[3]) ||
		   min(x[0],x[1]) > max(x[2],x[3]) ||
		   max(y[0],y[1]) < min(y[2],y[3]) ||
		   min(y[0],y[1]) > max(y[2],y[3]))
		   {
		   	cout << "NO\n";
		   	continue;
		   }
		int res1 = f(x[1] - x[0] , y[1] - y[0] , x[2] - x[0] , y[2] - y[0])*f(x[1] - x[0] , y[1] - y[0] , x[3] - x[0] , y[3] - y[0]);
		int res2 = f(x[3] - x[2] , y[3] - y[2] , x[0] - x[2] , y[0] - y[2])*f(x[3] - x[2] , y[3] - y[2] , x[1] - x[2] , y[1] - y[2]);
		if(res1 > 0 || res2 > 0)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}