#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n , m , dis = 0, from[1003][1003] , dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool block[1003][1003] , can;
pair<int,int> a , b;
char dir_c[4] = {'D','U','R','L'};
vector<int> path;
 
void bfs()
{
	can = 0;
	queue<pair<int,int>> q;
	q.push(a);
	
	while(!q.empty())
	{
		pair<int,int> now = q.front();q.pop();
		if(block[now.first][now.second])
		{
			continue;
		}
		if(now == b)
		{
			can = 1;
			return;
		}
		block[now.first][now.second] = 1;
		for(int k = 0 ; k < 4 ; k++)
		{
			if( 0 <= now.first + dir[k][0] && now.first + dir[k][0] < n &&
				0 <= now.second + dir[k][1] && now.second + dir[k][1] < m &&
				!block[now.first + dir[k][0]][now.second + dir[k][1]])
			{
				q.push(make_pair(now.first + dir[k][0],now.second + dir[k][1]));
				from[now.first + dir[k][0]][now.second + dir[k][1]] = k;
			}
		}
	}
	return;
}
 
void find_path()
{
	int x = b.second , y = b.first;
	do
	{
		path.push_back(from[y][x]);
		int xx = x - dir[from[y][x]][1];
		int yy = y - dir[from[y][x]][0];
		x = xx;y = yy;
		dis++;
	}
	while(x != a.second || y != a.first);
	return;
}
 
signed main()
{
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			char c;cin >> c;
			block[i][j] = (c == '#');
			if(c == 'A')a.first = i,a.second = j;
			if(c == 'B')b.first = i,b.second = j;
		}
	}
	bfs();
	if(can)
	{
		cout << "YES\n";
		find_path();
		cout << dis << "\n";
		for(int i = dis-1 ; i >= 0; i--)cout << dir_c[path[i]];
		
	}
	else
	{
		cout << "NO";
	}
}