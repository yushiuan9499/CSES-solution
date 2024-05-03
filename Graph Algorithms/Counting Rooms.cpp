#include <iostream>
using namespace std;
int n, m, i, j, room;
bool maps[1001][1001];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
 
void dfs(int x,int y)
{
	maps[x][y]=0;
	for(int k=0;k<4;k++)
	{
		if(dir[k][0]+x>=0 && dir[k][0]+x<n
		 &&dir[k][1]+y>=0 && dir[k][1]+y<m && maps[x+dir[k][0]][y+dir[k][1]])
		 {
		 	dfs(x+dir[k][0],y+dir[k][1]);
		 }
	}
}
 
int main()
{
	cin >> n >> m;
	char c;
	for( i=0;i < n;i++)
	{
		for( j=0;j < m;j++)
		{
			cin >> c;
			if(c=='#')maps[i][j]=0;
			else maps[i][j]=1;
		}
	}
	for(i=0;i < n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(maps[i][j])
			{
				room++;
				dfs(i,j);	
			}
		}
	}
	cout <<room;
	return 0;
}