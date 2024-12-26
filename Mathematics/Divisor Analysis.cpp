// Problem: Divisor Analysis
// URL: https://cses.fi/problemset/task/2182
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

const int M = 1e9+7;
int n , x[100005] , k[100005], ans1 , ans2 , ans3 , owo;

int pow(int a , int b , int m)
{
	if(!b)return 1;
	if(b&1)return pow(a,b-1,m)*a%m;
	int ret = pow(a,b/2,m);
	return ret*ret%m;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	owo = ans1 = ans2 = ans3 = 1;
	cin >> n;
	repeat(0,n,i)cin >> x[i] >> k[i];
	repeat(0,n,i)
	{
		int tmp = pow(x[i] , k[i]*(k[i]+1)/2 ,M);
		ans3 = pow(ans3,k[i]+1,M);
		ans3 = ans3*pow(tmp,owo,M)%M;
		ans1 = ans1*(k[i]+1)%M;owo = owo*(k[i]+1)%(M-1);
		ans2 = (ans2*((M+pow(x[i],k[i]+1,M)-1)%M)%M)*pow(x[i]-1,M-2,M)%M;
	}
	cout << ans1 << " " << ans2 << " " << ans3 ;
	return 0;
}