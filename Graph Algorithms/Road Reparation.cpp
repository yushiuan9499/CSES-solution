#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define plll pair<ll , pair<ll , ll> >
 
vector<ll> dsu , the_size_of_dsu; //the set that the element belong to ; the size of the set that the element belong to
 
//initialize the dsu
inline void init(ll dsu_size)
{
	dsu.resize(dsu_size);
	the_size_of_dsu.resize(dsu_size);
	for(int i = 0 ; i < dsu_size ; i++)dsu[i] = i,the_size_of_dsu[i] = 1;
	return;
}
 
//find the set that the element belong to
ll find_root(int dsu_element)
{
	return (dsu[dsu_element] == dsu_element)?dsu_element:dsu[dsu_element] = find_root(dsu[dsu_element]);
}
 
//determine whether the two elements is from the same set
inline bool same(ll dsu_x , ll dsu_y)
{
	return find_root(dsu_x) == find_root(dsu_y);
}
 
//merge two set by their elements
inline void unit(ll dsu_x , ll dsu_y)
{
	ll dsu_setX = find_root(dsu_x) ,
	   dsu_setY = find_root(dsu_y);
	if(dsu_setX == dsu_setY)return;
	if(the_size_of_dsu[dsu_setX] > the_size_of_dsu[dsu_setY])
		swap(dsu_setX,dsu_setY);
	dsu[dsu_setX] = dsu_setY;
	the_size_of_dsu[dsu_setY] += the_size_of_dsu[dsu_setX];
	return;
}
 
ll n , m , a , b , c , ans = 0;
vector<plll > edge;
bool can = 0;
 
int main()
{
	cin >> n >> m;init(n+5);
	for(int i = 0 ; i < m ; i++)
	{
	    cin >> a >> b >> c;
	    edge.pb(mp(c,mp(a,b)));
	}
	sort(edge.begin(),edge.end());
	ll j = 0;
	for(plll e : edge)
	{
	    if(same(e.s.f,e.s.s))continue;
	    ans += e.f;
	    unit(e.s.f,e.s.s);
	    j++;
	    if(j == n-1)
	    {
	        can = 1;break;
	    }
	}
	if(can)cout << ans;
	else cout << "IMPOSSIBLE";
	return 0;
}