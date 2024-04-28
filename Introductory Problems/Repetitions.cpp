#include <iostream>
#include <string>
using namespace std;
string dna;
int a , b;
char k;
int main()
{
	cin >> dna;
	for(int i = 0;i <= dna.length();i++)
	{
		if(dna[i] == k)
		{
			a++;
		}
		else
		{
			if(a > b)b=a;
			a=0;
			k=dna[i];
		}
	}
	cout << b+1;
}
