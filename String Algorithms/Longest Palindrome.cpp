// Problem: Longest Palindrome
// URL: https://cses.fi/problemset/task/1111
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m , p[2000006] = {0}, mxc = 0;
char t[2000006];
string s;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	n = s.size();
	t[0] = '$';
	repeat(0,n,i)t[2*i+1] = s[i],t[2*i+2] = '$';
	m = 2*n+1;	for(int i = 0 , j = -1 , rb = -1; i < m ; i++)
	{
		if(i <= rb)p[i] = min(p[j*2 - i],rb-i);
		while(i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i-p[i]-1] == t[i+p[i]+1])p[i]++;
		if(j==-1 || i+p[i] > rb)j = i,rb = i+p[i];
		if(p[i] > p[mxc])mxc = i;
	}
	cout << s.substr((mxc-p[mxc]+1)/2,p[mxc]);
	return 0;
}