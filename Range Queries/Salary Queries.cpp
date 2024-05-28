// Problem: Salary Queries
// URL: https://cses.fi/problemset/task/1144
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
} bi;

int n , q;
int a[200005] , b[200005][2];
bool qq[200005];
map<int,int> m;
int v[400005];


signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	repeat(0,n,i)cin >> a[i],m[a[i]] = 1;
	repeat(0,q,i)
	{
		char c;cin >> c >> b[i][0] >> b[i][1];
		qq[i] = (c=='?');
		if(c=='!')m[b[i][1]] = 1;
	}
	int cnt = 1;
	for(pair<int,int> x : m)
	{
		v[cnt] = x.first;
		m[x.first] = cnt++;
	}
	bi.init(cnt+5);
	repeat(0,n,i)bi.update(m[a[i]],1);
	repeat(0,q,i)
	{
		if(qq[i])
		{
			cout << bi.query(upper_bound(v+1,v+cnt,b[i][1]) - v - 1) - bi.query(lower_bound(v+1,v+cnt,b[i][0]) - v - 1) << "\n";
		}
		else
		{
			bi.update(m[a[b[i][0] - 1]],-1);
			a[b[i][0] - 1] = b[i][1];
			bi.update(m[a[b[i][0] - 1]],1);
		}
	}
	return 0;
}