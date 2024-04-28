#include <iostream>
using namespace std;
#define ll long long
 
ll n , m , a[505][505];
 
int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)a[i][j] = 5e3;
	int k = min(n,m);
	for(int i = 0 ; i <= k ; i++)a[i][i] = 0 , a[0][i] = 0 , a[i][0] = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			for(int k = 1 ; k <= i/2 ; k++)
				if(a[i-k][j] + a[k][j] + 1 < a[i][j])a[i][j] = a[i-k][j] + a[k][j] + 1;
			for(int k = 1 ; k <= j/2 ; k++)
				if(a[i][j-k] + a[i][k] + 1 < a[i][j])a[i][j] = a[i][j-k] + a[i][k] + 1;
		}
	} 
	cout << a[n][m];
}