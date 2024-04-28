#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , m , k , a[200005] , b[200005] , ans = 0;
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> k;
	repeat(0,n,i)cin >> a[i];
	repeat(0,m,i)cin >> b[i];
	sort(a,a+n);sort(b,b+m);
	for(int i = 0 , j = 0 ; i < n && j < m ; i++)
	{
		for( ; j < m && b[j] - a[i] <= k ; j++)
		{
			if(a[i] - b[j] <= k)
			{
				ans++;j++;break;
			}
		}
	}
	cout << ans;
    return 0;
}
