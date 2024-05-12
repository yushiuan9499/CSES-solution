#include <iostream>
#include <algorithm>
using namespace std;
 
int n, q , a , b , x[200005] = {0} , xx;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)cin >> xx,x[i] = xx ^ x[i-1];
	for(int i = 0 ; i < q ; i++)cin >> a >> b,cout << (x[b] ^ x[a-1]) << "\n";
	return 0;
}
