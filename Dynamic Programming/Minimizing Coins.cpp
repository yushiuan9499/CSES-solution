#include <iostream>
#include <algorithm>
using namespace std;
 
int n , c[102] , x , a[1000006];
 
int a_v(int x ) // a_value
{
    if(x < 0)return -1;
    return a[x];
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
    a[0] = 0;
    for(int i = 1 ; i <= x ; i++)
    {
            a[i] = -1;
            for(int j = 0 ; j < n ; j++)
            {
                if(a_v(i - c[j]) != -1)
                {
                    if(a[i] != -1)
                    {
                        if(a_v(i - c[j]) + 1< a[i])a[i] = a_v(i - c[j]) + 1;
                    }
                    else a[i] = a_v(i - c[j]) + 1;
                }
            }
    }
    //for(int i = 0 ; i < x ; i++)cout << a[i] << " ";
    cout << a[x];
            
	return 0;
}
