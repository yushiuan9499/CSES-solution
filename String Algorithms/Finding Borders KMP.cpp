// Problem: Finding Borders
// URL: https://cses.fi/problemset/task/1732
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , kmp[1000006] = {0};
string s;
stack<int> ans;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	n = s.size();
	int j = 0;
	repeat(1,n,i)
	{
		while(j && s[i] != s[j])j = kmp[j-1];
		if(s[i] == s[j])j++;
		kmp[i] = j;
	}
	for(int i = kmp[n-1] ; i ; i = kmp[i-1])ans.push(i);
	while(!ans.empty())cout << ans.top() << " ",ans.pop();
	return 0;
}