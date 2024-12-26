// Problem: Forest Queries II
// URL: https://www.cses.fi/problemset/task/1739
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
		vector<vector<int>> bits_array;
	
	public:
		inline void init(int bits_size)
		{
			bits_array.resize(bits_size+1);
			for(vector<int> &arr : bits_array)
			{
				arr.resize(bits_size+1);
				for(int &i : arr)i = 0;
			}
			return;
		}
		inline void update(int y , int x , int bits_value)
		{
			int sz = bits_array.size();
			while(y < sz)
			{
				int xx = x;
				while(xx < sz)
				{
					bits_array[y][xx] += bits_value;
					xx += xx&-xx;
				}
				y += y&-y;
			}
		}
		inline int query(int y , int x)
		{
			int ret = 0;
			while(y > 0)
			{
				int xx = x;
				while(xx > 0)
				{
					ret += bits_array[y][xx];
					xx -= xx&-xx;
				}
				y -= y&-y;
			}
			return ret;
		}
} b;

int n , q;
bool tree[1003][1003];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	b.init(n);
	repeat(1,n+1,i)
	{
		string s;cin >> s;
		repeat(1,n+1,j)
		{
			if(tree[i][j] = (s[j-1]=='*'))b.update(i,j,1);
		}
	}
	while(q--)
	{
		int type;cin >> type;
		if(type == 1)
		{
			int y , x;cin >> y >> x;
			b.update(y,x,((tree[y][x] = !tree[y][x])?1:-1));
		}
		else 
		{
			int y1, x1 , y2 , x2;cin >> y1 >> x1 >> y2 >> x2;
			cout << b.query(y2,x2) - b.query(y2,x1-1) - b.query(y1-1,x2) + b.query(y1-1,x1-1) << "\n";
		}
	}
	return 0;
}