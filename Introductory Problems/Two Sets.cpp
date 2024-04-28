#include <iostream>
#include <vector>
using namespace std;
 
unsigned long long n , i , k , t;
vector<int> a , b;
 
int main()
{
	cin >> n;
	if( ((n % 4) == 0) || ((n % 4) == 3) )
	{
		cout << "YES\n";
		k = n*(n+1)/4;
		for(i = n ; i > 0 ; i--)
		{
			if(i <= k)
			{
				a.push_back(i);
				k -= i;
			}
			else b.push_back(i);
		}
		cout << a.size() << "\n";
		for(i = 0 ; i < a.size() ; i++)cout << a[i] << " ";
		cout << "\n";
		cout << b.size() << "\n";
		for(i = 0 ; i < b.size() ; i++)cout << b[i] << " ";
	}
	else cout << "NO";
}
