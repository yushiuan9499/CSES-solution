// Problem: Pizzeria Queries
// URL: https://cses.fi/problemset/task/2206
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)


struct Seg_tree{
	#define default_value 2e9
	vector<int> array;
	bool b = 0;
	//將兩個資料合併
	inline int pull(int l_value , int r_value)
	{
		return min(l_value , r_value);
	}
	//將線段樹初始化為0
	inline void init(int n)
	{
		array.clear();array.resize(n<<2);
	}
	//將線段樹以陣列建造起來
	inline void build(int *arr , int l , int r , int id = 1)
	{
		if(l == r)
		{
			array[id] = arr[l] + (b?l:-1*l);
			return;
		}
		int mid = (l+r)>>1;
		build(arr,l,mid,2*id);
		build(arr,mid+1,r,2*id+1);
		array[id] = pull(array[2*id],array[2*id+1]);
		return;
	}
	//將[ql,qr]的數據加上update_value
	inline void update(int update_value , int index , int l , int r , int id = 1)
	{
		if(l==r)
		{
			array[id] = update_value + (b?l:-1*l);
			return;
		}
		int mid = (l+r)>>1;
		if(index <= mid)update(update_value , index , l , mid , 2*id);
		else update(update_value , index , mid+1 , r , 2*id+1);
		array[id] = pull(array[2*id],array[2*id+1]);
		return;
	}
	//查詢[ql,qr]的數據
	inline int query(int ql , int qr , int l , int r , int id = 1)
	{
		if(ql > r || qr < l)return default_value;
		if(ql <= l && r <= qr)
		{
			return array[id];
		}
		int mid = (l+r)>>1;
		return pull(query(ql,qr,l,mid,2*id),query(ql,qr,mid+1,r,2*id+1));
	}
} segl , segr;

int n , q;
int a[200005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	segr.b = 1;
	cin >> n >> q;
	segl.init(n+5);segr.init(n+5);
	repeat(1,n+1,i)cin >> a[i];
	segl.build(a,1,n);
	segr.build(a,1,n);
	while(q--)
	{
		int x , i , j;cin >> x >> i;
		if(x&1)
		{
			cin >> j;
			segl.update(j,i,1,n);
			segr.update(j,i,1,n);
		}
		else
		{
			cout << min(segl.query(1,i,1,n) + i,segr.query(i,n,1,n) - i) << "\n";
		}
	}
	return 0;
}