#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
string s;
map<char,int> m;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vst[10][10] = {0};
 
int dfs(int n , int x , int y)
{
	if(vst[x][y])return 0;
	if(n != 48 && x == 1 && y == 7)return 0;
	if(n==48)
	{
		return 1;
	}
	if(vst[x+1][y] == vst[x-1][y] && vst[x][y+1] == vst[x][y-1] && vst[x+1][y] != vst[x][y+1])return 0;
	vst[x][y] = 1;
	int ret = 0;
	if(s[n] == '?')
	{
		repeat(0,4,k)
		{
			ret += dfs(n+1,x+dir[k][0],y+dir[k][1]);
		}
	}
	else
	{
		ret = dfs(n+1,x+dir[m[s[n]]][0],y+dir[m[s[n]]][1]);
	}
	vst[x][y] = 0;
	return ret;
}
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	m['R'] = 0;m['L'] = 1;m['D'] = 2;m['U'] = 3;
	repeat(0,8,i)vst[0][i] = vst[8][i] = vst[i][0] = vst[i][8] = 1;
	cin >> s;
	cout << dfs(0,1,1);
    return 0;
}
