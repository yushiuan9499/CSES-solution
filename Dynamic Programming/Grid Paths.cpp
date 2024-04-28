#include <iostream>
using namespace std;
#define ll long long 
 
const int k = 1e9 + 7;
int n ;
ll  ways[1003][1003];
bool map[1003][1003];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		string s;cin >> s;
		for(int j = 0 ; j < n ; j++){
			map[i][j] = (s[j] == '.');
			ways[i][j] = 0;
		}
	}
	
	ways[0][0] = 1;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(map[i][j])
			{
				if(i != 0)ways[i][j] += ways[i-1][j];
				if(j != 0)ways[i][j] += ways[i][j-1];
				ways[i][j] = ways[i][j] % k;
			}
			else ways[i][j] = 0;
		}
	}
	
	cout << ways[n-1][n-1];
	return 0;
}
