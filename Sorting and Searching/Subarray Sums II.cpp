// Problem: Subarray Sums II
// URL: https://cses.fi/problemset/task/1661
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , x , a[200005];
map<int,int> m;
int ans = 0;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> x;
	repeat(0,n,i)cin >> a[i];
	repeat(1,n,i)a[i] += a[i-1];
	m[0] = 1;
	repeat(0,n,i)
	{
		ans += m[a[i]-x];
		m[a[i]]++;
	}
	cout << ans;
	return 0;
}