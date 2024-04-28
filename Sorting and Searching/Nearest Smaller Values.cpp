#include <iostream>
#include <stack>
#include <utility>
using namespace std;
 
int n , x;
stack<pair<int,int> > a;
 
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        pair<int , int> s;
        while(!a.empty())
        {
            s = a.top();
            if(s.second >= x)a.pop();
            else break;
        }
        cout << (a.empty()?0:s.first) << " ";
        a.push(make_pair(i,x));
    }
    return 0;
}
