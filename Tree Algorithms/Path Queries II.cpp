// Problem: Path Queries II
// URL: https://cses.fi/problemset/task/2134
// Memory Limit: 512 MB
// Time Limit: 1000 ms
 
#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 
 
int n , q , v[200005];
vector<int> adj[200005];
const int N = 200005;
int son[N] , num[N] , parent[N] , dep[N] = {0}, top[N] , dfn[N] , cnt = 0 , vd[N];
 
struct Seg_tree{
	#define DEFAULT 0
	vector<int> array;
	int n;
	inline int pull(int l_value , int r_value)
	{
		return max(l_value,r_value);
	}
	inline int init(int sz)
	{
		this->n = sz;
		array.clear();array.resize(sz*2+1);
		return 0;
	}
	inline void build()
	{
		for(int i = n-1 ; i ; i--)array[i] = pull(array[i<<1],array[(i<<1)|1]);
		return;
	}
	inline void update(int v ,int id)
	{
		
		for(id += this->n,array[id] = v; id ;id >>= 1)array[id>>1] = pull(array[id],array[id^1]);
		return;
	}
	inline int query(int ql , int qr)
	{
		int ret = DEFAULT;
		ql += this->n;qr += this->n;
		for( ; ql < qr ; ql >>= 1 , qr >>= 1)
		{
			if(ql&1)ret = pull(ret,array[ql++]);
			if(qr&1)ret = pull(ret,array[--qr]);
		}
		return ret;
	}
} st;
 
//找到每個節點的重兒子
void dfs1(int now)
{
	son[now] = -1;num[now] = 1;
	for(int nxt : adj[now])
	{
		if(!dep[nxt])
		{
			dep[nxt] = dep[now] + 1;
			parent[nxt] = now;
			dfs1(nxt);
			num[now] += num[nxt];
			if((num[nxt] > num[son[now]]) || (son[now] == -1)) son[now] = nxt;
		}
	}
	return;
}
 
//剖分並找出頂點
void dfs2(int now , int t)
{
	top[now] = t;
	dfn[now] = cnt++;
	vd[cnt] = v[now];
	if(son[now] == -1)return;
	dfs2(son[now],t);
	for(int nxt : adj[now])
	{
		if(nxt != son[now] && nxt != parent[now])dfs2(nxt,nxt);
	}
	return;
}
 
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	st.init(n);
	repeat(0,n,i)cin >> v[i+1];
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);adj[v].pb(u);
	}
	parent[1] = -1;
	dep[1] = 1;dfs1(1);
	dfs2(1,1);
	repeat(0,n,i)st.array[n+i] = vd[i+1];
	st.build();
	while(q--)
	{
		int qq , s , x;cin >> qq >> s >> x;
		if(qq&1)
		{
			st.update(x,dfn[s]);
		}
		else 
		{
			int ans = 0;
			while(top[s] != top[x])
			{
				if(dep[top[s]] < dep[top[x]])swap(s,x);
				ans = max(ans,st.query(dfn[top[s]],dfn[s]+1));
				s = parent[top[s]]; 
			}
			if(dfn[s] < dfn[x])swap(s,x);
			ans =  max(ans,st.query(dfn[x],dfn[s]+1));
			cout << ans << " ";
		}
	}
	return 0;
}
