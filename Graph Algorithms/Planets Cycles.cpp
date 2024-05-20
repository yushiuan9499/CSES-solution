// Problem: Planets Cycles
// URL: https://cses.fi/problemset/task/1751
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , nxt[200005];
int tmp , ans[200005] = {0};
int vst[200005] = {0} , cnt;

int dfs(int now)
{
	if(vst[now])
	{
		tmp = ++cnt - vst[now];
		return ans[now]?0:now;
	}
	vst[now] = ++cnt;
	int res = dfs(nxt[now]);
	if(res)
	{
		ans[now] = tmp;
		return (res==now)?0:res;
	}
	else
	{
		ans[now] = ans[nxt[now]]+1;
		return 0;
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(1,n+1,i)cin >> nxt[i];
	repeat(1,n+1,i)
	{
		cnt = 0;
		if(!vst[i])dfs(i);
		cout << ans[i] << " ";
	}
	return 0;
}