#include <iostream>
#include <algorithm>
using namespace std;
const int k = 1e9 + 7;
 
long long n , a[1000006];
 
long long a_value(int x)
{
    if(x < 0)return 0;
    return a[x];
}
 
int main()
{
	cin >> n;
	a[0] = 1;
	
	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = a_value(i-1) + a_value(i-2) + a_value(i-3) + a_value(i-4) + a_value(i-5) + a_value(i-6);
		a[i] = a[i] % k;
	}
	cout << a[n];
	return 0;
}