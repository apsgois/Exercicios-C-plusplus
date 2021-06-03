#include <iostream>
#include <iomanip>
#include <cstring>
#include <locale.h>
#include <cmath>

using namespace std;

int main()
{
	int fat, n;
	cout<<"Insira o fatorial: " ;
	cin>>n;
	fat=1;
	while (n>0)
	{
		fat=fat*n;
		n=n-1;
	}
	cout<<"Fatorial: " << fat<< endl;
	return 0;
}