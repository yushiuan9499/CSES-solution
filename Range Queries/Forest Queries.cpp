#include <iostream>
using namespace std;
 
int a[1003][1003] , n , q , x1 , y1 , x2 , y2;
string s;
 
int main()
{
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> s;
		for(int j = 0 ; j < n ; j++)
		{
			a[i][j] = (s[j] == '*');
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(i == 0 && j == 0)continue;
			if(i == 0)a[i][j] += a[i][j-1];
			else if(j == 0)a[i][j] += a[i-1][j];
			else a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
		}
	}
	for(int i = 0 ; i < q ; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;
		cout << a[y2-1][x2-1] - ((x1 == 1)?0:a[y2-1][x1-2]) - ((y1 == 1)?0:a[y1-2][x2-1]) + ((x1 == 1 || y1 == 1)?0:a[y1-2][x1-2]) << "\n";
	}
	return 0;
}