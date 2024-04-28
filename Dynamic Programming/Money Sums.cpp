#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long

bitset<1000006> d;
int n , x;
vector<int> ans;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	d[0] = 1;
	cin >> n;
	repeat(0,n,i)
	{
		cin >> x;
		d |= d<<x;
	}
	repeat(1,1000005,i)
	{
		if(d[i])ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for(int a : ans)cout << a << " ";
	return 0;
}