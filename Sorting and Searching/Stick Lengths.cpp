#include <iostream>
#include <algorithm>
using namespace std;
 
 
long long a[200005];
long long n , mid , sum = 0;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    sort(a,a+n);
    if(n % 2 == 1)mid = a[n / 2];
    else mid = (a[n / 2]+a[n / 2 -1])/2;
    for(int i = 0 ; i < n ; i++)sum += abs(a[i]-mid);
    cout << sum;
    return 0;
}
