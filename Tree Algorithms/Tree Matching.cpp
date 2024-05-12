#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define ll long long
#define f first
#define s second
#define pll pair<ll , ll> 
 
ll n , a , b;
vector<ll> adj[200005];
pll dp[200005];
bool vst[200005] = {0};
 
pll dfs(ll node)
{
    bool flag = 0;
    for(ll a : adj[node])
    {
        if(vst[a])continue;
        vst[a] = 1;
        pll x = dfs(a);
        if(x.f >= x.s)
        {
            dp[node].f += x.f;
            flag = 1;
        }
        else dp[node].f += x.s;
    }
    dp[node].s = dp[node].f + flag;
    return dp[node];
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
    cout << max(dp[1].f , dp[1].s);
    return 0;
}
