#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , a;
vector<int> v;
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	repeat(0,n,i)
	{
		cin >> a;
		int x = upper_bound(v.begin(),v.end(),a) - v.begin();
		if(x == v.size())v.pb(a);
		else v[x] = a;
	}
	cout << v.size();
    return 0;
}
