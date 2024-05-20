// Problem: Company Queries II
// URL: https://cses.fi/problemset/task/1688
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q , fa[200005][30] , dep[200005];
vector<int> son[200005];

void dfs(int now = 1 , int d = 0)
{
	dep[now] = d;
	for(int s : son[now])dfs(s,d+1);
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	fa[1][0] = -1;
	cin >> n >> q;;
	repeat(2,n+1,i)cin >> fa[i][0],son[fa[i][0]].pb(i);
	repeat(1,30,i)
	{
		repeat(1,n+1,j)fa[j][i] = (fa[j][i-1] < 0)?-1:fa[fa[j][i-1]][i-1];
	}
	dfs();
	while(q--)
	{
		int a, b;cin >> a >> b;
		if(dep[a] < dep[b])swap(a,b);
		int d = dep[a] - dep[b];
		for(int i = 0 , j = 1 ; j <= d ; i++ , j <<= 1)
		{
			if(d&j)a = fa[a][i];
		}
		for(int jump = 25 ; jump >= 0; jump--)
		{
			while(fa[a][jump] != fa[b][jump])a = fa[a][jump],b = fa[b][jump];
		}
		cout << ((a==b)?a:fa[a][0]) << "\n";
	}
	return 0;
}