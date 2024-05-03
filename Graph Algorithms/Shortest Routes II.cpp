#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
 
ll n , m , q , a , b , c;
ll dist[502][502];
 
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q;
    memset(dist,-1,sizeof dist);
    for(int i = 1 ; i <= n ; i++)dist[i][i] = 0;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c;
        if(~dist[a][b])dist[a][b] = dist[b][a] = min(c,dist[a][b]);
        else dist[a][b] = dist[b][a] = c;
    }
    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i+1 ; j <= n ; j++)
            {
                if((~dist[i][k]) && (~dist[k][j]))
                {
                    if(!(~dist[i][j]))dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];
                    else
                    {
                        dist[i][j] = dist[j][i] = min(dist[i][j],dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
    return 0;
}