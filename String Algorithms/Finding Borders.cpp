// Problem: Finding Borders
// URL: https://www.cses.fi/problemset/task/1732
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

string s;int n;
vector<int> ans;

struct Hash{
	static const int M = 998244353 , K = 13331 , N = 1e6;
	int arr[N+5] , pow[N+5];
	
	void build(string s)
	{
		int n = s.size();
		arr[0] = s[0];pow[0] = 1;
		repeat(1,n,i)arr[i] = (arr[i-1]*K + s[i])%M , pow[i] = pow[i-1]*K%M;
		return;
	}
	int get(int l , int r)
	{
		return (M+arr[r] - (l?arr[l-1]*pow[r-l+1]%M:0))%M;
	}
} h;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;n = s.size();
	h.build(s);
	repeat(1,n,i)
	{
		if(h.get(0,i-1) == h.get(n-i,n-1))
			ans.pb(i);
	}
	for(int a : ans)cout << a << " ";
	return 0;
}