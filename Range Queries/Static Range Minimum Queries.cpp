#include <iostream>
using namespace std;
#define ull unsigned long long
 
int n , q , x[200005] , a , b , f[200005][20] , ans;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
    for(int i = 0 ; i < n ; i++)
    {
            cin >> x[i];
            f[i][0] = x[i];    
    }
    for(int j = 1 ; (1 << j) <= n ; j++)
    {
    	for(int i = 0 ; i + (1 << j) - 1 < n ; i++)
    	{
    		f[i][j] = min(f[i][j-1],f[i+(1 << (j-1))][j-1]);
		}
	}
	for(int k = 0 ; k < q ; k++)
	{
		cin >> a >> b;
		int i;
		for(i = 0 ; (1 << (i+1)) <= b-a+1 ; i++);
		ans = min(f[a-1][i],f[b - (1 << i)][i]);
		cout << ans << "\n";
	}
	return 0;
}