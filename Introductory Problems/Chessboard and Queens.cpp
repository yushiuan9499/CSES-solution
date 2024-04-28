#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long

string s;
int ans = 0;
bool block[10][10] = {0};
bool used[10] = {0} , used2[20] = {0} , used3[20] = {0};

void dfs(int n = 0)
{
	if(n == 8)
	{
		ans++;
	}
	repeat(0,8,i)
	{
		if(used[i] || used2[i+n] || used3[8+n-i] || block[n][i])continue;
		used[i] = used2[i+n] = used3[8+n-i] = 1;
		dfs(n+1);
		used[i] = used2[i+n] = used3[8+n-i] = 0;
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	repeat(0,8,i)
	{
		cin >> s;
		repeat(0,8,j)
		{
			block[i][j] = (s[j] == '*');
		}
	}
	dfs();
	cout << ans;
	return 0;
}