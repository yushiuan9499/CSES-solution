#include <iostream>
using namespace std;
 
unsigned long long y , x , i , j , t;
 
int max(int a , int b)
{
	if(a > b)return a;
	else return b;
}
 
int main()
{
	cin >> t;
	for(i = 0 ; i < t ; i++)
	{
		cin >> y >> x;
		if(max(x , y)%2 == 0)
		{
			if(x > y)cout << ((x-1)*(x-1) + y);
			else cout << (y*y - x + 1);
		}
		else
		{
			if(x < y)cout << ((y-1)*(y-1) + x);
			else cout << (x*x - y + 1);
		}
		cout << "\n";
	}
	return 0;
}
