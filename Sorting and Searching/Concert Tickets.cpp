#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , m;
multiset<int> s;
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	repeat(0,n,i)
	{
		int h;cin >> h;
		s.insert(2e5-h);
	}
	repeat(0,m,i)
	{
		int t;cin >> t;
		auto x = s.lower_bound(2e5-t);
		if(x==s.end())cout << "-1\n";
		else 
		{
			cout << (int)(2e5-*x) << "\n";
			s.erase(x);
		}
	}
    return 0;
}
