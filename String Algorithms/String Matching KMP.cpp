// Problem: String Matching
// URL: https://cses.fi/problemset/task/1753
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m , kmp[2000006] = {0} , ans;
string s , t;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s >> t;
	s = t+'$'+s;
	m = t.size();
	n = s.size();
	int j = 0;
	repeat(1,n,i)
	{
		while(j && s[i] != s[j])j = kmp[j-1];
		if(s[i] == s[j])j++;
		kmp[i] = j;
	}
	repeat(m+1,n,i)
	{
		if(kmp[i] == m)ans++;
	}
	cout << ans;
	return 0;
}