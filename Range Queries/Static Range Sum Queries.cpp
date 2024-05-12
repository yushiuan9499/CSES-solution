#include <iostream>
using namespace std;
#define int long long
 
int arr[200005];
int n,q,a,b;
 
void up(int k ,int num)
{
     while(k <= n)
     {
             arr[k] += num;
             k += k&-k;
     }
}
 
int find_sum(int m)
{
     int ret = 0;
     while(m > 0)
     {
             ret += arr[m];
             m -= m&-m;
     }
     return ret;
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for(int i = 1 ; i <= n ;i++) 
    {
            int input;
            cin >> input;
            up(i,input);
    }
    for(int i = 0 ; i < q ; i++)
    {
            cin >> a >> b;
            int sum = find_sum(b)-find_sum(a-1);
            cout  << sum << "\n";
    }
    return 0;
}
