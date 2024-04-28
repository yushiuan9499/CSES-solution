#include <iostream>
#include <algorithm>
using namespace std;
 
int n , a[200005] , ans = 1 , m;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i ; i < n ; i++)
	{
	    int x;cin >> x;
	    a[x] = i;
	}
	m = n+1;
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i] < a[i-1] && i != 1)ans++;
	}
	cout << ans;
	return 0;
}
