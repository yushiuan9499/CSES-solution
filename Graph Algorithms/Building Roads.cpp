#include <iostream>
#include <vector>
using namespace std;
 
int m , n , j , l;
int group[100005];
vector<int> road[100005];
 
void f(int c , int k)
{
	group[c] = k;
	///cout << road[c].back();
	
	for(int o = 0 ; o < road[c].size() ; o++)
	{
		if(group[road[c][o]] == 0)
		{
			f(road[c][o] , k);
		}
		
	}
	return;
}
 
int main()
{
	cin >> n >> m;
	
	for(int i = 0 ; i < m ; i++)
	{
		int a , b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	
	j = 1;
	l = 0;
	while(j <= n)
	{
		if(group[j] == 0)
		{
			l++;
			f(j , l);
		}
		j++;
	}
	cout << (l - 1) << "\n";
	
	j = 2;
	for(int p = 1 ; p <= n ; p++)
	{
		if(group[p] == j)
		{
			cout << "1 " << p << "\n";
			j++;
		}
	}
	
	return 0;
}
