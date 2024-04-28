#include<iostream>
#include<algorithm>
using namespace std;
 
int n;
int x[200005];
long long ans = 1;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++)cin >> x[i];
	sort(x,x+n);
	for(int i = 0 ; i < n ; i++)
	{
		if(x[i] > ans)break;
		ans += x[i];
	}
	cout << ans;
	return 0;
}
