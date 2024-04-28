#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
pair<int,int> a[200005];
int n , now = 0 , ans = 0;
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> a[i].second >> a[i].first;
	sort(a,a+n);
	repeat(0,n,i)
	{
		if(a[i].second >= now)
		{
			ans++;
			now = a[i].first;
		}
	}
	cout << ans;
    return 0;
}
