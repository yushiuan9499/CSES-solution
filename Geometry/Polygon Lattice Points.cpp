// Problem: Polygon Lattice Points
// URL: https://cses.fi/problemset/task/2193
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

inline int a(int x1 , int y1 , int x2 , int y2)
{
	return x1*y2 - x2*y1;
}

int n , x[100005] , y[100005] , area = 0 , bo = 0;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> x[i] >> y[i];
	repeat(0,n,i)
	{
		area += a(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
		bo += __gcd(abs(x[(i+1)%n] - x[i]),abs(y[(i+1)%n] - y[i]));
	}
	area = abs(area);
	cout << (area - bo + 2)/2 << " " << bo;
	return 0;
}