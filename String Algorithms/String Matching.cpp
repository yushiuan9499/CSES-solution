// Problem: String Matching
// URL: https://www.cses.fi/problemset/task/1753
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

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
} hs , ht;

string s, t;
int n , m , h , ans = 0;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s >> t;
	n = s.size();m = t.size();
	hs.build(s);ht.build(t);
	h = ht.get(0,m-1);
	repeat(0,n-m+1,i)
	{
		if(h == hs.get(i,i+m-1))ans++;
	}
	cout << ans;
	return 0;
}