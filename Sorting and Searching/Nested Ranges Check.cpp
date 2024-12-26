// Problem: Nested Ranges Check
// URL: https://cses.fi/problemset/task/2168
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n , mn = 1e9 + 1 , mx = 0;
pair<int,int> p[200005];
map<pair<int,int>,int> id;
bool ans[200005][2] = {0};

bool cmp(pair<int,int> a , pair<int,int> b)
{
	if(a.first == b.first)return a.second > b.second;
	return a.first < b.first;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)cin >> p[i].first >> p[i].second , id[p[i]] = i;;
	sort(p,p+n,cmp);
	repeat(0,n,i)
	{
		if(p[i].second <= mx)ans[id[p[i]]][1] = 1;
		else mx = p[i].second;
	}
	repeat(0,n,i)
	{
		if(p[n-i-1].second >= mn)ans[id[p[n-i-1]]][0] = 1;
		else mn = p[n-i-1].second;
	}
	repeat(0,n,i)cout << ans[i][0] << " ";cout << "\n";
	repeat(0,n,i)cout << ans[i][1] << " ";
	return 0;
}