#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , m;
set<int> s;
multiset<int> ms;
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	s.insert(0);s.insert(n);ms.insert(n);
	repeat(0,m,i)
	{
		int p;cin >> p;
		auto a = s.upper_bound(p) , b = prev(s.upper_bound(p));
		
		ms.erase(ms.find(*a-*b));ms.insert(*a-p);ms.insert(p-*b);s.insert(p);
		cout << *ms.rbegin() << " ";
	}
    return 0;
}
