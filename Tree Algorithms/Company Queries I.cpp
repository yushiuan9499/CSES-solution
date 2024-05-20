// Problem: Company Queries I
// URL: https://cses.fi/problemset/task/1687
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q , fa[200005][30];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	fa[1][0] = -1;
	cin >> n >> q;;
	repeat(2,n+1,i)cin >> fa[i][0];
	repeat(1,30,i)
	{
		repeat(1,n+1,j)fa[j][i] = (fa[j][i-1] < 0)?-1:fa[fa[j][i-1]][i-1];
	}
	while(q--)
	{
		int x , k;cin >> x >> k;
		for(int i = 0 , j = 1 ; j <= k ; i++ , j <<= 1)
		{
			if(x<0)break;
			if(k&j)x = fa[x][i];
		}
		cout << x << "\n";
	}
	return 0;
}