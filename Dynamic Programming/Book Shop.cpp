#include <iostream>
using namespace std;
 
int n , x , h[1003] , s[1003] , a[1003][100005];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	for(int i = 1 ; i <= n ; i++)cin >> h[i];
	for(int i = 1 ; i <= n ; i++)cin >> s[i];
	
	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= x ; j++)
		{
			a[i][j] = 0;
			if(i != 0)
			{
				if(j >= h[i])a[i][j] = max(a[i-1][j] , s[i] + a[i-1][j-h[i]]);
				else a[i][j] = a[i-1][j];
			}
		}
	}
	
	cout << a[n][x];
	return 0;
} 
