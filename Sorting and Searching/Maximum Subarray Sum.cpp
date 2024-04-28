#include <iostream>
using namespace std;
#define ll long long
 
ll n , x;
ll sum , a , b , m;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	a = 0;sum = 0;m = -1e9-1;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> x;
		sum += x;
		if(sum - a > m)m = sum - a;
		if(sum < a)a = sum;
	}
	cout << m;
	return 0;
}
