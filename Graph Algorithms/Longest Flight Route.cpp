#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
 
vector<ll> dag[200005] , ord;
ll n , m , a , b  , x , dist[200005] = {0}, from[200005];
bool state[200005] = {0}, can = 0;
 
void dfs(ll city)
{
    if(state[city] == 1)return;
    state[city] = 1;
    for(ll cnt : dag[city])
    {
        dfs(cnt);
    }
    ord.push_back(city);
    return;
}
 
void printpath(int f)
{
    if(f != 1)printpath(from[f]);
    cout << f << " ";
    return;
}
 
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        dag[a].push_back(b);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(!state[i])dfs(i);
    }
    memset(from,-1,sizeof(from));
    dist[1] = 1;
    for(int i = ord.size() - 1 ; i >= 0 ; i--)
    {
        if(!dist[ord[i]])continue;
        for(ll nxt : dag[ord[i]])
        {
            if(dist[nxt] < dist[ord[i]] + 1)
            {
                from[nxt] = ord[i];
                dist[nxt] = dist[ord[i]]+1;
            }
        }
    }
    if(dist[n])
    {
        cout << dist[n] << "\n";
        printpath(n);
    }
    else cout << "IMPOSSIBLE";
    return 0;
}
