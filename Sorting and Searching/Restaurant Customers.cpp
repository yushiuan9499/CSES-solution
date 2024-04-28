#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
using namespace std;
 
vector<pair<int,int> > co;
int n , ma = 0 , now = 0;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
            int a ,b;
            cin >> a >> b;
            co.push_back(make_pair(a,1));co.push_back(make_pair(b+1,-1));
    }
    sort(co.begin(),co.end());
    for(auto x : co)
    {
             now += x.second;
             ma = now>ma?now:ma;
    }
    cout << ma;
    return 0;
}
