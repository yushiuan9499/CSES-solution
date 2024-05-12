#include <iostream>
using namespace std;
#define ll long long
 
ll n , q , seg[800005] = {0} , x , a , b , o[200005] , tag[800005] = {0};
 
void build(int id , int l , int r)
{
	if(l == r){
		seg[id] = o[l];
		return;
	}
	int mid = (l+r)>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);;
}
 
ll query(int id , int l , int r , int k)
{
	if(l==r){
		seg[id] += tag[id];
		tag[id] = 0;
		return seg[id];
	}
	tag[2*id] += tag[id];
	tag[2*id+1] += tag[id];
	tag[id] = 0;
	int mid = (l+r)>>1;
	if(k <= mid)return query(2*id,l,mid,k);
	else return query(2*id+1,mid+1,r,k);
}
 
void update(int id , int l , int r , int ql , int qr , ll u)
{
	if(qr < l || ql > r)return;
	if(ql <= l && r <= qr){
		tag[id] += u;
		return;
	}
	int mid = (l+r)>>1;
	update(2*id,l,mid,ql,qr,u);
	update(2*id+1,mid+1,r,ql,qr,u);
}
 
 
int main()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)cin >> o[i];
	build(1,1,n);
	for(int i = 0 ; i < q ; i++)
	{
		cin >> x ;
		if(x == 1){
			ll u;cin >> a >> b >> u;
			update(1,1,n,a,b,u);
		}
		else if(x == 2)
		{
			cin >> a;
			cout << query(1,1,n,a) << "\n";
		}
	}
	return 0;
}
