#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
int n , m , g = 0;
multiset<int> ch;
 
 
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
            int w;cin >> w;
            ch.insert(w);
    }
    while(!ch.empty())
    {
                      int sum = 0;
                      int i = 0;
                      while(sum < m && i < 2)
                      {
                                auto x = ch.upper_bound(m-sum);
                                if(x == ch.begin())break;
                                sum += *next(x,-1);
                                ch.erase(next(x,-1));
                                i++;
                      }
                      g++;
    }
    cout << g;
    return 0;
}
