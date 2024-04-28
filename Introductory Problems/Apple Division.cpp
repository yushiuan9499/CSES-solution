#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
 
ll n, w[20] , sum = 0 ;
 
ll f(int x, ll gp1)
{
    if(x == n)
    {
        ll gp2 = sum - gp1;
        return abs(gp2 - gp1);
    }
    ll a = f(x+1,gp1+w[x]);
    ll b = f(x+1,gp1);
    return a<b?a:b;
}
 
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
	    cin >> w[i];
	    sum += w[i];
	}
	cout << f(0,0);
	return 0;
}
