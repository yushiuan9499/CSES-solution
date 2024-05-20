// Problem: Subtree Queries
// URL: https://cses.fi/problemset/task/1137
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q , l[200005] = {0}, r[200005] = {0}, cnt = 0 , v[200005];
vector<int> adj[200005];

struct Bits{
	private:
		vector<int> bits_array;
	
	public:
		inline void init(int bits_size)
		{
			bits_array.resize(bits_size+1);
			for(int i : bits_array)i = 0;
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

void dfs(int now)
{
	l[now] = ++cnt;
	for(int son : adj[now])
	{
		if(!l[son])dfs(son);
	}
	r[now] = cnt;
	return;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;bi.init(n+5);
	repeat(0,n,i)cin >> v[i+1];
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);adj[v].pb(u);
	}
	dfs(1);
	repeat(0,n,i)bi.update(l[i+1],v[i+1]);
	while(q--)
	{
		int qq , s , x;cin >> qq >> s;
		if(qq == 1)
		{
			cin >> x;bi.update(l[s],x-bi.query(l[s])+bi.query(l[s]-1));
		}
		else cout << bi.query(r[s]) - bi.query(l[s] - 1) << "\n";
	}
	return 0;
}