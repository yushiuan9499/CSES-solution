#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , m , now = 0 , X , Y;
bool block[1003][1003] = {0};
queue<pair<pair<int,int>,int> > ms , a;
int dir[4][3] = {{1,0,'D'} , {0,1,'R'} , {0,-1,'L'} , {-1,0,'U'}} , from[1003][1003];
vector<char> path;
string s;
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	repeat(0,n,i)
	{
		cin >> s;
		repeat(0,m,j)
		{
			if(s[j] == '#')block[i][j] = 1;
			else if(s[j] == 'A')a.push(mp(mp(i,j),0)), X = i , Y = j;
			else if(s[j] == 'M')ms.push(mp(mp(i,j),0));
		}
	}
	while(!a.empty())
	{
		while(!ms.empty() && ms.front().second == now)
		{
			int x , y;
			pair<pair<int,int>,int> mon = ms.front();ms.pop();
			if(block[x = mon.first.first][y = mon.first.second])continue;
			block[x][y] = 1;
			repeat(0,4,k)
			{
				if(0 <= x + dir[k][0] && x + dir[k][0] < n && 
				   0 <= y + dir[k][1] && y + dir[k][1] < m &&
				   !block[x + dir[k][0]][y + dir[k][1]])
				   	ms.push(mp(mp(x + dir[k][0],y + dir[k][1]),now+1));
			}
		}
		while(!a.empty() && a.front().second == now)
		{
			int x , y;
			pair<pair<int,int>,int> i = a.front();a.pop();
			if(block[x = i.first.first][y = i.first.second])continue;
			block[x][y] = 1;
			repeat(0,4,k)
			{
				if(0 > x + dir[k][0] || x + dir[k][0] >= n || 
				   0 > y + dir[k][1] || y + dir[k][1] >= m)
				   {
				   		cout << "YES\n";
				   		while(x != X || y != Y)
				   		{
				   			path.push_back(dir[from[x][y]][2]);
				   			int temp = x - dir[from[x][y]][0];
				   			y -= dir[from[x][y]][1];
				   			x = temp;
				   		}
				   		cout << path.size() << "\n";
				   		repeat(0,path.size(),j)cout << path[path.size()-j-1];
				   		return 0;
				   }
				if(!block[x + dir[k][0]][y + dir[k][1]])
				{
					from[x + dir[k][0]][y + dir[k][1]] = k;
					a.push(mp(mp(x + dir[k][0],y + dir[k][1]),now+1));
				}   	
			}
		}
		now++;
	}
	cout << "NO";
    return 0;
}