#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
ll n , p[200005] = {0} , dp[200005] = {0} , boss;
vector<ll> s[200005];
 
ll dfs(int e)
{
    for(ll ss : s[e])
    {
        if(ss != e)
            dp[e] += dfs(ss)+1;
    }
    return dp[e];
}
    
 
int main()
{
    cin >> n;
    for(int i = 2 ; i <= n ; i++)
    {
        cin >> p[i];
        s[p[i]].push_back(i);
    }
    dfs(1);
    for(int i = 1 ; i <= n ; i++)cout << dp[i] << " ";
    return 0;
}
