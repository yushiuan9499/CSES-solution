#include <iostream>
using namespace std;
unsigned long long n,k,i,j;
int main()
{
	cin >> n;
	k=n*(n+1)/2;
	for(i=1;i<=(n-1);i++)
	{
		cin >> j;
		k-=j;
	}
	cout << k;
}
