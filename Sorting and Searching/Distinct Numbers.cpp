#include <iostream>
#include <bitset>
using namespace std;
 
bitset<1000000009> has;
int n , x , co = 0;
 
int main()
{
	cin >> n ;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> x;
		if(!has[x])
		{
			co++;
			has[x] = 1;
		}
	}
	cout << co;
	return 0;
}
