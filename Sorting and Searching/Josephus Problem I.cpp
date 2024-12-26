// Problem: Josephus Problem I
// URL: https://cses.fi/problemset/task/2162
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define repeat(l,r,x) for(int x = (l) ; x < (r) ; x++)
#define int long long
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x) 

int n ;
queue<int> q;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	repeat(0,n,i)q.push(i+1);
	while(!q.empty())
	{
		q.push(q.front());q.pop();
		cout << q.front() << " ";q.pop();
	}
	return 0;
}