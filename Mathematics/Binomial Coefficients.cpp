// Problem: Binomial Coefficients
// URL: https://cses.fi/problemset/task/1079
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M = 1e9+7;
int t , a , b;
int c[1000006];

int pow(int x , int y)
{
	if(y==0)return 1;
	if(y&1)return x*pow(x,y-1)%M;
	int ret = pow(x,y/2);
	return ret*ret%M;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	c[0] = c[1] = 1;
	repeat(2,1e6+6,i)c[i] = i*c[i-1]%M;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		cout << c[a]*pow(c[b],M-2)%M*pow(c[a-b],M-2)%M << "\n";
	}
	return 0;
}