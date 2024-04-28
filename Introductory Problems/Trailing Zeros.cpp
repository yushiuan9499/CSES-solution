#include <iostream>
using namespace std;
 
int n , a = 0;
 
int main()
{
	cin >> n;
	while(n > 0)
	{
		a += (n / 5);
		n /= 5;
	}
	cout << a;
}
