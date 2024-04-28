#include <iostream>
#include <cmath>
using namespace std;
 
int n;
 
void h(int x , int a , int b , int c)
{
	if(x == 1)cout << a << " " << c << "\n";
	else
	{
		h(x-1,a,c,b);
		cout << a << " " << c << "\n";
		h(x-1,b,a,c);
	}
	return;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	
	cin >> n;
	cout << pow(2,n)-1 << "\n";
	h(n,1,2,3);
	return 0;
}
