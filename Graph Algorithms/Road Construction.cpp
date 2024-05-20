// Problem: Road Construction
// URL: https://cses.fi/problemset/task/1676
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , m , mx = 1;

struct dsu{
	vector<int> parent , the_size_of_dsu; //the set that the element belong to ; the size of the set that the element belong to

	//initialize the dsu
	inline void init(int dsu_size)
	{
		parent.resize(dsu_size);
		the_size_of_dsu.resize(dsu_size);
		for(int i = 0 ; i < dsu_size ; i++)parent[i] = i,the_size_of_dsu[i] = 1;
		return;
	}
	
	//find the set that the element belong to
	int find_root(int dsu_element)
	{
		return (parent[dsu_element] == dsu_element)?dsu_element:parent[dsu_element] = find_root(parent[dsu_element]);
	}
	
	//determine whether the two elements is from the same set
	inline bool same(int dsu_x , int dsu_y)
	{
		return find_root(dsu_x) == find_root(dsu_y);
	}
	
	//merge two set by their elements
	inline void unit(int dsu_x , int dsu_y)
	{
		int dsu_setX = find_root(dsu_x) ,
		    dsu_setY = find_root(dsu_y);
		if(dsu_setX == dsu_setY)return;
		n--;
		if(the_size_of_dsu[dsu_setX] > the_size_of_dsu[dsu_setY])
			swap(dsu_setX,dsu_setY);
		parent[dsu_setX] = dsu_setY;
		the_size_of_dsu[dsu_setY] += the_size_of_dsu[dsu_setX];
		mx = max(mx,the_size_of_dsu[dsu_setY]);
		return;
	}
} d;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	d.init(n+1);
	repeat(0,m,i)
	{
		int u , v;cin >> u >> v;
		d.unit(u,v);
		cout << n << " " << mx << "\n";
	}
	return 0;
}