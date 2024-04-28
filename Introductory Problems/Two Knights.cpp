#include <iostream>
using namespace std;
#define ull unsigned long long
 
ull n , ans;
 
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	
	cin >> n;
	for(ull i = 1 ; i <= n ; i++)
	{
		ans = i*i*(i*i-1)/2;
		ans -= 4*(i-2)*(i-1);
		cout << ans << "\n";
	}
	return 0;
} 
