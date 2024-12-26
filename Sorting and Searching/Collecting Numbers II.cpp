// Problem: Collecting Numbers II
// URL: https://www.cses.fi/problemset/task/2217
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)

int n , m , a[200005] , pos[200005];
int ans = 0;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	repeat(0,n,i)
	{
		cin >> a[i];pos[a[i]] = i;
	}
	repeat(2,n+1,i)ans += (pos[i] < pos[i-1]);
	while(m--)
	{
		int x, y;cin >> x >> y;
		x--;y--;
		if(a[x] > a[y])swap(x,y);
		if(a[y] - a[x] == 1)
		{
			if(a[x] != 1)ans -= x < pos[a[x]-1];
			ans -= y < pos[a[y]-1];
			if(a[y] != n)ans -= pos[a[y]+1] < y;
			swap(pos[a[x]],pos[a[y]]);
			a[x]++;a[y]--;
			if(a[x] != n)ans += pos[a[x]+1] < pos[a[x]];
			if(a[y] != 1)ans += pos[a[y]] < pos[a[y]-1];
			ans += pos[a[y]+1] < pos[a[y]];
		}
		else
		{
			if(a[x] != 1)ans -= x < pos[a[x]-1];
			ans -= pos[a[x]+1] < x;
			ans -= y < pos[a[y]-1];
			if(a[y] != n)ans -= pos[a[y]+1] < y;
			swap(pos[a[x]],pos[a[y]]);
			swap(a[x],a[y]);
			ans += pos[a[x]] < pos[a[x]-1];
			if(a[x] != n)ans += pos[a[x]+1] < pos[a[x]];
			if(a[y] != 1)ans += pos[a[y]] < pos[a[y]-1];
			ans += pos[a[y]+1] < pos[a[y]];
		}
		cout << ans+1 << "\n";
	}
	return 0;
}