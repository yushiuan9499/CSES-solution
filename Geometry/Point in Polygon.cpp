// Problem: Point in Polygon
// URL: https://cses.fi/problemset/task/2192
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m , x[1003] , y[1003];
bool is_b , in;

inline int f(int x1 , int y1 , int x2 , int y2)
{
	return x1*y2 - x2*y1;
}

bool on_b(int qx , int qy , int now)
{
	if(min(x[now],x[(now+1)%n]) <= qx && qx <= max(x[now],x[(now+1)%n]) &&
	   min(y[now],y[(now+1)%n]) <= qy && qy <= max(y[now],y[(now+1)%n]))
	{
		return (f(qx - x[now],qy - y[now],x[(now+1)%n] - x[now],y[(now+1)%n] - y[now]) == 0);
	}
	return 0;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,n,i)cin >> x[i] >> y[i];
	while(m--)
	{
		int qx , qy;cin >> qx >> qy;
		is_b = in = 0;
		repeat(0,n,i)
		{
			if(on_b(qx,qy,i))
			{
				is_b = 1;
				break;
			}
			if(y[i] <= qy && qy < y[(i+1)%n] && 
			  f(qx - x[i],qy - y[i],x[(i+1)%n] - x[i],y[(i+1)%n] - y[i]) < 0)
			  {
			  	in = !in;
			  }
			else if(y[(i+1)%n] <= qy && qy < y[i] && 
					f(qx - x[(i+1)%n],qy - y[(i+1)%n],x[i]-x[(i+1)%n],y[i]-y[(i+1)%n]) < 0)
					{
						in = !in;
					}
		}
		if(is_b)cout << "BOUNDARY\n";
		else cout << (in?"INSIDE":"OUTSIDE") << "\n";
	}
	return 0;
}