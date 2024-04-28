#include <iostream>
#include <set>
using namespace std;
 
int n , a[200005] , ans = 1 , l = 0 , r = 0;
set<int> s;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0 ; i < n ; i++)cin >> a[i];
	while(r < n)
	{
	    if(s.count(a[r]))
	    {
	        while(s.count(a[r]))
	        {
	            s.erase(a[l]);
	            l++;
	        }
	    }
	    s.insert(a[r]);
	    r++;
	    if(r - l  > ans)ans = r-l;
	}
	cout << ans;
	return 0;
}
