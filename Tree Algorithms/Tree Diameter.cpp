#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define ll long long
 
ll n , a , b , mx = -1;
vector<ll> adj[200005];
ll dp[200005] = {0};
bool vst[200005] = {0};
 
void dfs(ll node)
{
    ll x = 0, y = 0;
    for(ll a : adj[node])
    {
        if(vst[a])continue;
        vst[a] = 1;
        dfs(a);
        if(dp[a] > x)y = x,x = dp[a];
        else if(dp[a] > y)y = dp[a];
    }
    mx = max(mx,x+y);
    dp[node] = x+1;
    return;
}
 
int main()
{
    cin >> n;
    for(int i = 0 ; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vst[1] = 1;
    dfs(1);
    cout << mx;
    return 0;
}
