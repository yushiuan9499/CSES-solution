// Problem: List Removals
// URL: https://cses.fi/problemset/task/1749
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

struct Bits{
	private:
		vector<int> bits_array;
	public:
		inline void init(int bits_size)
		{
			bits_array.resize(bits_size+1);
		}
		
		inline void update(int bits_index , int bits_value)
		{
			int sz = bits_array.size();
			while(bits_index < sz)
			{
				bits_array[bits_index] += bits_value;
				bits_index += bits_index&-bits_index;
			}
		}
		
		inline int query(int bits_index)
		{
			int ret = 0;
			while(bits_index > 0)
			{
				ret += bits_array[bits_index];
				bits_index -= bits_index&-bits_index;
			}
			return ret;
		}
} b;

int n , a[200005] , r;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	b.init(n+5);
	repeat(1,n+1,i)cin >> a[i],b.update(i,1);
	repeat(0,n,i)
	{
		cin >> r;
		int ans = 0;
		for(int jump = n ; jump ; jump >>= 1)
		{
			while(ans+jump <= n && b.query(ans+jump) < r)ans += jump;
		}
		cout << a[ans+1] << " ";
		b.update(ans+1,-1);
	}
	return 0;
}