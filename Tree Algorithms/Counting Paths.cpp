// Problem: Counting Paths
// URL: https://cses.fi/problemset/task/1136
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , q;
const int N = 200005;
vector<int> g[N];
int son[N] , num[N] , parent[N] , dep[N] = {0}, top[N] , dfn[N] , cnt = 0;

//找到每個節點的重兒子
void dfs1(int now)
{
	son[now] = -1;num[now] = 1;
	for(int nxt : g[now])
	{
		if(!dep[nxt])
		{
			dep[nxt] = dep[now] + 1;
			parent[nxt] = now;
			dfs1(nxt);
			num[now] += num[nxt];
			if((son[now] == -1) || (num[nxt] > num[son[now]]))son[now] = nxt;
		}
	}
	return;
}

//剖分並找出頂點
void dfs2(int now , int t)
{
	top[now] = t;
	dfn[now] = ++cnt;
	if(son[now] == -1)return;
	dfs2(son[now],t);
	for(int nxt : g[now])
	{
		if(nxt != son[now] && nxt != parent[now])dfs2(nxt,nxt);
	}
	return;
}

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

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;bi.init(n+5);
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		g[u].pb(v);g[v].pb(u);
	}
	memset(parent,-1,sizeof parent);
	dep[1] = 1;dfs1(1);
	dfs2(1,1);
	while(q--)
	{
		int a, b;cin >> a >> b;
		while(top[a] != top[b])
		{
			if(dep[top[a]] < dep[top[b]])swap(a,b);
			bi.update(dfn[top[a]],1);bi.update(dfn[a]+1,-1);
			a = parent[top[a]];
		}
		if(dep[a] < dep[b])swap(a,b);
		bi.update(dfn[b],1);bi.update(dfn[a]+1,-1);
	}
	repeat(1,n+1,i)cout << bi.query(dfn[i]) << " ";
	return 0;
}