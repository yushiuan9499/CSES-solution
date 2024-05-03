#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
ll n , m , x , ans = 0;
vector<ll> adj[100005] , path;
bool done = 0 , vst[100005] = {0} , can = 0;
 
bool dfs(ll now , ll from)
{
    for(ll next : adj[now])
    {
        if(next == from)continue;
        if(vst[next])
        {
            x = next;
            path.push_back(now);
            ans++;
            return 1;
        }
        vst[next] = 1;
        if(dfs(next,now))
        {
            if(!done)path.push_back(now),ans++;
            if(now == x)done = 1;
            return 1;
        }
    }
    return 0;
}
 
int main()
{
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(ll i = 1 ; i <= n & !can; i++)
    {
        if(vst[i])continue;
        vst[i] = 1;
        can = dfs(i,0);
    }
    if(!can)cout << "IMPOSSIBLE";
    else
    {
        cout << ans +1<< "\n";
        cout << x << " ";
        for(ll a : path)cout << a << " ";
    }
    return 0;
}
