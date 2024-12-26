#include <iostream>
using namespace std;
#define ll long long
 
int n , m , a[100005] , k = 1e9 +7;
ll times[102][100005] , ans = 0;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		for(int j = 0 ; j <= m+1 ; j++)times[j][i] = 0;
	}
	if(a[0] == 0)
	{
		for(int j = 2 ; j <= m ; j++)times[j][0] = 1;
	}
	else times[a[0]][0] = 1;
	for(int i = 1 ; i < n ; i++)
	{
		if(a[i] == 0)
		{
			for(int j = 1 ; j <= m ; j++)
			{
				times[j][i] = (times[j-1][i-1] + times[j][i-1] + times[j+1][i-1]) % k;
			}
		}
		else times[a[i]][i] = (times[a[i]-1][i-1] + times[a[i]][i-1] + times[a[i]+1][i-1]) % k;
	}
	if(a[n-1] == 0)
	{
			for(int j = 1 ; j <= m ; j++)ans = (ans + times[j][n-1]) % k;
			cout << ans;
	}
	else cout << times[a[n-1]][n-1];
	return 0;
}
