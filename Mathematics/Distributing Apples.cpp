// Problem: Distributing Apples
// URL: https://cses.fi/problemset/task/1716
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M = 1e9+7;
int a , b;
int c[2000006];

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
	cin >> a >> b;a += b-1;
	c[0] = c[1] = 1;
	repeat(2,a+1,i)c[i] = i*c[i-1]%M;
	cout << c[a]*pow(c[b],M-2)%M*pow(c[a-b],M-2)%M;
	return 0;
}