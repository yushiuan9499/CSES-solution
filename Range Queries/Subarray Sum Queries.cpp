// Problem: Subarray Sum Queries
// URL: https://cses.fi/problemset/task/1190
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

struct Node{
	int value = 0 , lvalue = 0 , rvalue = 0 , sum = 0;
	Node *lson = nullptr , *rson = nullptr;
};

void pull(Node* l , Node* r , Node *&now)
{
	now->value = max(l->rvalue + r->lvalue , max(l->value,r->value));
	now->lvalue = max(l->lvalue,l->sum+r->lvalue);
	now->rvalue = max(r->rvalue,r->sum+l->rvalue);
	now->sum = l->sum + r->sum;
	return;
}

void build(int* arr , int l , int r , Node *now)
{
	if(l==r)
	{
		now->sum = arr[l];
		now->value = now->rvalue = now->lvalue = max((int)0,arr[l]);
		return;
	}
	now->lson = new Node();
	now->rson = new Node();
	int mid = (l+r)>>1;
	build(arr,l,mid,now->lson);
	build(arr,mid+1,r,now->rson);
	pull(now->lson,now->rson,now);
	return;
}

void update(int uvalue , int index , int l , int r , Node *now)
{
	if(l==r)
	{
		now->sum = uvalue;
		now->value = now->rvalue = now->lvalue = max((int)0,uvalue);
		return;
	}
	int mid = (l+r)>>1;
	if(index <= mid)update(uvalue,index,l,mid,now->lson);
	else update(uvalue,index,mid+1,r,now->rson);
	pull(now->lson,now->rson,now);
	return;
}

int n , q;
int a[200005];
Node* root = new Node();

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	repeat(1,n+1,i)cin >> a[i];
	build(a,1,n,root);
	while(q--)
	{
		int i , v;cin >> i >> v;
		update(v,i,1,n,root);
		cout << root->value << "\n";
	}
	return 0;
}