#include <iostream>
using namespace std;
 
int t , a , b;
bool can = 0;
 
int main()
{
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		can = 0;
		cin >> a >> b;
		if((a+b)%3 == 0)
		{
			if((2*b >= a) && (2*a >= b))can = 1;
		}
		if(can)cout << "YES\n";
		else cout << "NO\n";
	}
}
