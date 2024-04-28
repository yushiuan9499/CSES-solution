#include <iostream>
#include <algorithm>
using namespace std;
 
int n , a[1000006];
 
int main()
{
	cin >> n;
    a[0] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
            a[i] = 1e6+1;
            int now = i;
            while(now > 0)
            {
                int j = now % 10;
                now = now/10;
                if(a[i-j] + 1 < a[i])a[i] = a[i-j]+1;
            }
    }
    //for(int i = 0 ; i < x ; i++)cout << a[i] << " ";
    cout << a[n];
            
	return 0;
}
