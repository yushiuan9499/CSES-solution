// Problem: Nested Ranges Count
// URL: https://cses.fi/problemset/task/2169
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n;
pair<pair<int,int>,int> p[200005];
map<int,int> m;
int ans[200005][2] = {0};

struct Bits{
	private:
		vector<int> bits_array;
	
	public:
		inline void init(int bits_size)
		{
			bits_array.resize(bits_size+1);
			for(int &i : bits_array)i = 0;
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
} bit;

bool cmp(pair<pair<int,int>,int> a , pair<pair<int,int>,int> b)
{
	if(a.first.first == b.first.first)return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)
	{
		cin >> p[i].first.first >> p[i].first.second;
		p[i].second = i;
		m[p[i].first.first] = 1;
		m[p[i].first.second] = 1;
	}
	int cnt = 0;
	for(pair<int,int> x : m)
	{
		m[x.first] = ++cnt;
	}
	sort(p,p+n,cmp);
	bit.init(cnt);
	repeat(0,n,i)
	{
		ans[p[i].second][1] = bit.query(cnt) - bit.query(m[p[i].first.second]-1);
		bit.update(m[p[i].first.second],1);
	}
	bit.init(cnt);
	repeat(0,n,i)
	{
		ans[p[n-i-1].second][0] = bit.query(m[p[n-i-1].first.second]);
		bit.update(m[p[n-i-1].first.second],1);
	}
	repeat(0,n,i)cout << ans[i][0] << " ";cout << "\n";
	repeat(0,n,i)cout << ans[i][1] << " ";
	return 0;
}