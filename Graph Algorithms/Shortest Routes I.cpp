#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
#define mp make_pair
 
vector<pll > adj[100005];
priority_queue<pll > q;
ll n ,  m , a , b , c;
bool vst[100005] = {0};
 
 
int main()
{
    cin >> n >> m;
    vector<ll> dist(n+1,1e17);
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(mp(b,c));
    }
    
    dist[1] = 0;
    q.push(mp(0,1));
    
    while(!q.empty())
    {
        pll v = q.top();
        q.pop();
        if(vst[v.s])continue;
        vst[v.s] = 1;
        
        for(pll u : adj[v.s])
        {
            if(vst[u.f])continue;
            if(dist[u.f] > dist[v.s] + u.s)
            {
                dist[u.f] = dist[v.s] + u.s;
                q.push(mp(-1*dist[u.f],u.f));
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)cout << dist[i] << " ";
    return 0;
}
