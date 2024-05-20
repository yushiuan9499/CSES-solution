#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int t , q , now;
 
bool f(int x)
{
	int ret = 0;
	int i = 1 , j = 1;
	for(;10*i <= x; i *= 10 , j++)
	{
		ret += j*9*i;
		if(ret >= q)return 0;
	}
	ret += j*(x-i);
	return ret < q;
}
int g(int x)
{
	int ret = 0;
	int i = 1 , j = 1;
	for(;10*i <= x; i *= 10 , j++)
	{
		ret += j*9*i;
	}
	ret += j*(x-i);
	return ret;
}
string to_str(int x)
{
	string ret;
	while(x)
	{
		ret = (char)('0' + x%10) + ret;
		x /= 10;
	}
	return ret;
}
 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> q;
		now = 0;
		for(int jump = q ; jump ; jump >>= 1)
		{
			while(f(now+jump))now += jump; 
		}
		cout << to_str(now)[q-g(now)-1] << "\n";
	}
    return 0;
}