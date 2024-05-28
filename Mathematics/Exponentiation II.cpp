// Problem: Exponentiation II
// URL: https://cses.fi/problemset/task/1712
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M = 1e9+7;
int t , n , m , o;
int pow(int x , int y , int mm)
{
	if(!y)return 1;
	if(y&1)return (x*pow(x,y-1,mm))%mm;
	int ret = pow(x,y/2,mm);
	return (ret*ret)%mm;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> o;
		cout << pow(n,pow(m,o,M-1),M) << "\n";
	}
	return 0;
}