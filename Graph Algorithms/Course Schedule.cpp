#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
vector<int> adj[100005] , s;
int n , m , state[100005] = {0};
bool can = 1;
 
void dfs(int c)
{
    if(state[c] == 1 || !can)
    {
        can = 0;
        return;
    }
    state[c] = 1;
    for(int nxt : adj[c])
    {
        if(state[nxt] != 2)dfs(nxt);
    }
    state[c] = 2;
    s.push_back(c);
    return;
}
 
int main()
{
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
	    int a , b;cin >> a >> b;
	    adj[b].push_back(a);
	}
	for(int i = 1 ; i <= n ; i++)
	{
	    if(state[i] != 2)dfs(i);
	}
	if(can)
	{
	    for(int c : s)cout << c << " ";
	}
	else cout << "IMPOSSIBLE";
	return 0;
}
