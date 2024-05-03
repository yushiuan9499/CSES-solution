#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
vector<ll> dag[200005] , path;
ll n , m , a , b , state[200005] = {0} , x;
bool done = 0 , can = 0;
 
bool dfs(ll city)
{
    if(state[city] == 2)return 0;
    if(state[city] == 1)
    {
        can = 1;x = city;
        path.push_back(city);
        return 1;
    }
    state[city] = 1;
    for(ll cnt : dag[city])
    {
        if(dfs(cnt))
        {
            if(!done)path.push_back(city);
            if(city == x)done = 1;
            return 1;
        }
    }
    state[city] = 2;
    return 0;
}
 
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        dag[a].push_back(b);
    }
    for(int i = 0 ; i < n && !can ; i++)
    {
        if(!state[i])dfs(i);
    }
    if(can)
    {
        cout << path.size() << "\n";
        for(int i = path.size() - 1 ; i >= 0; i--)cout << path[i] << " ";
    }
    else cout << "IMPOSSIBLE";
    return 0;
}
