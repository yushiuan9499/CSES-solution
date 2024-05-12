#include <iostream>
using namespace std;
#define ll long long
 
int n , q , seg[800005] = {0} , x , a , b , o[200005];
 
void build(int id , int l , int r)
{
	if(l == r){
		seg[id] = o[l];
		return;
	}
	int mid = (l+r)>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	seg[id] = min(seg[2*id],seg[2*id+1]);
}
 
int query(int id , int l , int r , int ql , int qr)
{
	if(qr < l || ql > r)return 1e9;
	if(ql <= l && r <= qr)return seg[id];
	int mid = (l+r)>>1;
	return min(query(2*id,l,mid,ql,qr),
			   query(2*id+1,mid+1,r,ql,qr));
}
 
void update(int id , int l , int r , int k , int u)
{
	if(l==r){
		seg[id] = u;
		return;
	}
	int mid = (l+r)>>1;
	if(k <= mid)update(2*id,l,mid,k,u);
	else update(2*id+1,mid+1,r,k,u);
	seg[id] = min(seg[2*id] , seg[2*id+1]);
}
 
 
int main()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)cin >> o[i];
	build(1,1,n);
	for(int i = 0 ; i < q ; i++)
	{
		cin >> x >> a >> b;
		if(x == 1)update(1,1,n,a,b);
		else if(x == 2)cout << query(1,1,n,a,b) << "\n";
	}
	return 0;
}
