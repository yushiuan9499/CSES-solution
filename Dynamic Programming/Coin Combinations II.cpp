#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
 
const int k = 1e9 + 7;
ll n , c[102] , x , a[1000006];
 
ll a_v(int y ) // a_value
{
    if(y < 0)return 0;
    return a[y];
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	for(int i = 0 ; i < n ; i++)
    {
        cin >> c[i];
    }
    a[0] = 1;
    for(int i = 1 ; i <= x ; i++)a[i] = 0;
    for(int j = 0 ; j < n ; j++)
    {
            for(int i = 1 ; i <= x ; i++)
            {
                a[i] += a_v(i-c[j]);
                a[i] = a[i] % k;
            }
    }
    
    cout << a[x];
            
	return 0;
}
