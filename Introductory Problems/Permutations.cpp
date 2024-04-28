#include <iostream>
using namespace std;
 
int n , i , j , k , m;
 
int main()
{
	cin >> n;
	if(n > 3)
	{
		for(i = 1 ; i <= n/2 ; i++)cout << 2*i << " ";
		for(i = 1 ; i <= (n+1)/2 ; i++)cout << (2*i)-1 << " ";
	}
	else 
	{
		if(n == 1)cout << 1;
		else cout <<"NO SOLUTION";
	}
}
