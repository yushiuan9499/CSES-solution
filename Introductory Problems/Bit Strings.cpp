#include <iostream>
#include <cmath>
using namespace std;
 
unsigned long long n , x = 1 , y = 2;
 
int main()
{
	cin >> n;
	while(n > 0)
	{
		if(n % 2 == 1)x = (x*y) % 1000000007;
		y *= y;
		y = y % 1000000007;
		n /= 2;
	}
	cout << x;
