#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int n , m , i , j , co;
queue<int> w;
vector<int> connect[100005] , a;
int route[100005];
bool done = 0;
 
void f(int c)
{
	a.push_back(c);
	co++;
	if(c == 1)return;
	f(route[c]);
}
 
int main()
{
	cin >> n >> m;                   
	for(i = 0 ; i < m ; i++)
	{
		int a , b;
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	
	w.push(1);
	while(!w.empty())
	{
		j = w.front();
		w.pop();
		if(j == n)
		{
			done = 1;
			break;
		}
		for(i = 0 ; i < connect[j].size() ; i++)
		{
			if(route[connect[j][i]] == 0)
			{
				w.push(connect[j][i]);
				route[connect[j][i]] = j;
			}
		}
	}
	if(done)
	{
		f(n);
		cout << co << "\n";
		for(i = co-1 ; i >= 0 ; i--)
		{
			cout << a[i] << " ";
		}
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
}
