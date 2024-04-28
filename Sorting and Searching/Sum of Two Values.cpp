#include <iostream>
#include <map>
using namespace std;
 
map<int , int> m1;
map<int , bool> m2;
int x , n , a[200005];
bool can=0;
 
int main()
{
	cin >> n >> x;
	for(int i = 0 ; i < n ; i++)cin >> a[i];
	for(int i = 0 ; i < n ; i++)
	{
	    if(m2[a[i]])
	    {
	        cout << m1[x - a[i]]+1 << " " << i + 1;
	        can = 1;
	        break;
	    }
	    m1[a[i]] = i;
	    m2[x - a[i]] = 1;
	}
	if(!can)cout << "IMPOSSIBLE";
	return 0;
}
