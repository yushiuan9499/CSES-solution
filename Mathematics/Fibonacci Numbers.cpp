// Problem: Fibonacci Numbers
// URL: https://www.cses.fi/problemset/task/1722
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n;
const int M = 1e9+7;
struct mat{
	int arr[102][102] = {0}, n , m;
	mat(int sz):n(sz),m(sz){
		repeat(0,sz,i)arr[i][i] = 1;
		return;
	}
	mat(int x , int y):n(x),m(y){memset(arr,0,sizeof arr);return;}
	mat operator*(mat &y)
	{
		int mm = y.m , k = m;
		mat ret(n,mm);
		repeat(0,n,i)
		{
			repeat(0,k,j)
			{
				repeat(0,mm,l)
				{
					ret.arr[i][l] += arr[i][j]*y.arr[j][l];
					ret.arr[i][l] %= M;
				}
			}
		}
		return ret;
	}
	void operator=(mat &x)
	{
		repeat(0,n,i)
		{
			repeat(0,m,j)arr[i][j] = x.arr[i][j];
		}
		return;
	}
};

mat a(2,2) , i(2,2) , v0(2,1);

mat f(int x)
{
	if(!x)
		return i;
	if(x&1)
	{
		return f(x-1)*a;
	}
	mat ret = f(x/2);
	return ret*ret;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	a.arr[1][0] = a.arr[1][1] = a.arr[0][1] = i.arr[0][0] = i.arr[1][1] = v0.arr[1][0] = 1;
	cin >> n;
	cout << (f(n)*v0).arr[0][0];
	return 0;
}