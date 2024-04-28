#include <iostream>
#include <algorithm>
using namespace std;
#define str string
 
int n , k;
str s , ans1 = "" , ans2 = "";
bool can = 1 , che = 1;
char c;
 
int main()
{
	cin >> s;
	n = s.size();
	sort(s.begin(),s.end());
	k = 0;
	for(int i = 0 ; i < 26 ; i++)
	{
		int m = 0;
		while(s[k+m] == (char)('A'+i))m++;
		if(m % 2 == 1)
		{
			if(che)
			{
				che = 0;
				c = (char)('A'+i);
			}
			else 
			{
				can = 0;
				break;
			}
		}
		str sub = s.substr(k,m/2);
		ans1 += sub;
		ans2 = sub + ans2;
		k += m;
	}
	if(can)
	{
		if(che)cout << ans1 << ans2;
		else cout << ans1 << c << ans2;
	}
	else cout << "NO SOLUTION";
	return 0;
}
