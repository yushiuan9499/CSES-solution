// Problem: Minimum Euclidean Distance
// URL: https://www.cses.fi/problemset/task/2194
// Memory Limit: 512 MB
// Time Limit: 1000 ms
 
#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
 
const int MAX = 8e18;
int n;
struct Point{
	int x , y;
	bool operator<(Point b)
	{
		if(x==b.x)return y < b.y;
		return x < b.x;
	}
} p[200005];
 
int d(Point a , Point b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
 
bool cmp(Point a , Point b)
{
	if(a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}
 
int f(int l = 0 , int r = n-1)
{
	if(l>=r)return MAX;
	if(l+1==r)return d(p[l],p[r]);
	int mid = (l+r)/2;
	int res = min(f(l,mid),f(mid+1,r));
	vector<Point> tmp;
	for(int i = l ; i <= r ; i++)
		if(abs(p[i].x-p[mid].x)*abs(p[i].x-p[mid].x) <= res)tmp.pb(p[i]);
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i = 0 ; i < tmp.size() ; i++)
	{
		repeat(max((int)0,i-9),i,j)
		{
			res = min(res,d(tmp[i],tmp[j]));
		}
	}
	return res;
}
 
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> p[i].x >> p[i].y;
	sort(p,p+n);
	cout << f();
	return 0;
}