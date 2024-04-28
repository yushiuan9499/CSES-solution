#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n , now = 0 , m;
bool a[16] = {0} , b[200005] = {0};
 
signed main()
{
	cin >> n;
	m = 1<<n;
	for(int i = 0 ; i < m ; i++)
	{
		for(int j = 0 ; ; j++)
		{
			if(!b[now^(1<<j)])
			{
				a[j] = !a[j];now ^= 1<<j;b[now] = 1;
				for(int k = 0 ; k < n ; k++)cout << a[k];
				cout << "\n";
				break;
			}
		}
	}
	return 0;
}
