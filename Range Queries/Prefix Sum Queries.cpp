// Problem: Prefix Sum Queries
// URL: https://cses.fi/problemset/task/2166
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)

struct Node{
	int value = 0 , sum = 0;
	Node *lson = nullptr , *rson = nullptr;
};

inline void pull(Node* l , Node* r , Node *&now)
{
	now->sum = (l ? l->sum : 0) + (r ? r->sum : 0);
    now->value = max(l ? l->value : 0, (l ? l->sum : 0) + (r ? r->value : 0));
	return;
}

Node *root = new Node();
inline void build(int *arr , int l , int r , Node *&now)
{
	if(l == r)
	{
		now->value = max((int)0,arr[l]);
		now->sum = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	if(now->lson == nullptr)now->lson = new Node();
	if(now->rson == nullptr)now->rson = new Node();
	build(arr,l,mid,now->lson);
	build(arr,mid+1,r,now->rson);
	pull(now->lson,now->rson,now);
	return;
}

inline void update(int update_value , int index , int l , int r , Node *&now)
{
	if(l==r)
	{
		now->value = max((int)0,update_value);
		now->sum = update_value;
		return;
	}
	int mid = (l+r)>>1;
	if(index <= mid)update(update_value , index , l , mid ,now->lson);
	else update(update_value , index , mid+1 , r , now->rson);
	pull(now->lson,now->rson,now);
	return;
}
//查詢[ql,qr]的數據
inline Node* query(int ql , int qr , int l , int r , Node *now)
{
	if(ql > r || qr < l)return nullptr;
	if(ql <= l && r <= qr)
	{
		return now;
	}
	Node *ret = new Node();
	int mid = (l+r)>>1;
	pull(query(ql,qr,l,mid,now->lson),query(ql,qr,mid+1,r,now->rson),ret);
	return ret;
}

int n , q , a[200005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	repeat(0,n,i)cin >> a[i];
	build(a,0,n-1,root);
	while(q--)
	{
		int x , y , z;cin >> x >> y >> z;
		if(x&1)update(z,y-1,0,n-1,root);
		else cout << query(y-1,z-1,0,n-1,root)->value << '\n';
	}
	return 0;
}