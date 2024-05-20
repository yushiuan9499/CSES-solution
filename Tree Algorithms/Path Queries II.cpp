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
	#define default_value 0
	int array[800005] = {0};
	//將兩個資料合併
	inline int pull(int l_value , int r_value)
	{
		return max(l_value,r_value);
	}
	//將線段樹以陣列建造起來
	inline void build(int *arr , int l = 1 , int r = n , int id = 1)
	{
		if(l == r)
		{
			array[id] = arr[l];
			return;
		}
		int mid = (l+r)>>1;
		build(arr,l,mid,2*id);
		build(arr,mid+1,r,2*id+1);
		array[id] = pull(array[2*id],array[2*id+1]);
		return;
	}
	//將[ql,qr]的數據加上update_value
	inline void update(int update_value , int x , int l = 1 , int r = n , int id = 1)
	{
		if(l >= r){
			array[id] = update_value;
			return;
		}
		int mid = (l+r)>>1;
		if(x <= mid)update(update_value , x , l , mid , 2*id);
		else update(update_value , x , mid+1 , r , 2*id+1);
		array[id] = pull(array[2*id],array[2*id+1]);
		return;
	}
	//查詢[ql,qr]的數據
	inline int query(int ql , int qr , int l = 1 , int r = n , int id = 1)
	{
		if(ql > r || qr < l)return default_value;
		if(ql <= l && r <= qr)
		{
			return array[id];
		}
		int mid = (l+r)>>1;
		return pull(query(ql,qr,l,mid,2*id),query(ql,qr,mid+1,r,2*id+1));
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
	dfn[now] = ++cnt;
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
	repeat(0,n,i)cin >> v[i+1];
	repeat(0,n-1,i)
	{
		int u , v;cin >> u >> v;
		adj[u].pb(v);adj[v].pb(u);
	}
	parent[1] = -1;
	dep[1] = 1;dfs1(1);
	dfs2(1,1);
	st.build(vd,1,n);
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
				ans = max(ans,st.query(dfn[top[s]],dfn[s]));
				s = parent[top[s]]; 
			}
			if(dfn[s] < dfn[x])swap(s,x);
			ans =  max(ans,st.query(dfn[x],dfn[s]));
			cout << ans << " ";
		}
	}
	return 0;
}
