#include <iostream>
using namespace std;
 
string s , t;
int d[5003][5003] , n , m;
 
int main()
{
	cin >> s >> t;
	n = s.size();m = t.size();
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)d[i][j] = 0;
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
		{
			if((i == 0) || (j == 0))d[i][j] = max(i,j);
			else if(s[i-1] == t[j-1])d[i][j] = d[i-1][j-1];
			else d[i][j] = min(d[i][j-1],min(d[i-1][j-1],d[i-1][j])),d[i][j]++;
		}
		
	cout << d[n][m];
	return 0;
}
