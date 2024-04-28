#include <iostream>
using namespace std;
long long input;
int main()
{
	cin >> input;
	while(input != 1)
	{
		cout << input << " ";
		if(input % 2 == 1)
		{
			input *= 3;
			input ++;
		}
		else
		{
			input /= 2;
		}
	}
	cout << "1";
}
