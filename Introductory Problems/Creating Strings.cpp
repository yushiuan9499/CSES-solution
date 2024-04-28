#include <iostream>
#include <vector>
using namespace std;
#define str string
 
vector<str> check;
int l_c[26] , n;
str s;
 
void f(str x)
{
	if(x.size() == n)
	{
		check.push_back(x);
		return;
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		if(l_c[i] > 0)
		{
			l_c[i]--;
			f(x+(char)('a'+i));
			l_c[i]++;
		}
	}
	return;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)l_c[s[i]-'a']++;
	n = s.size();
	f("");
	cout << check.size() << "\n";
	for(str x : check)cout << x << "\n";
	return 0;
}
