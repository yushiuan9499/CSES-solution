// Problem: Finding Periods
// URL: https://cses.fi/problemset/task/1733
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , z[1000006] = {0};
string s;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	n = s.size();
	for(int i = 1 , l = 0 , r = 0 ; i < n ; i++)
	{
		z[i] = max((int)0,min(z[i-l],r-i+1));
		while(i + z[i] < n && s[z[i]] == s[i+z[i]])
		{
			l = i;r = i+z[i];
			z[i]++;
		}
		if(i+z[i] == n)cout << i << " ";
	}
	cout << n;
	return 0;
}