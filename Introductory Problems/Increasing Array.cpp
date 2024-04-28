#include <iostream>
using namespace std;
int n ;
int i ;
unsigned long long m=0;
int main()
{
	
	cin >> n;
	int x[n+1];
	for(i = 1;i <= n;i++)
	{
		cin >> x[i];
	}
	x[0] = 0;
	for(i = 1;i <= n;i++)
	{
		if(x[i] < x[i-1])
		{
			m += x[i-1]-x[i];
			x[i] = x[i-1];
		}
	}
	cout << m;
	return 0;
}
