#include <iostream>
#include <iomanip>
#include <cstring>
#include <locale.h>
#include <cmath>

using namespace std;

int main()

{
	int fat , n;
	
	cout<< "insira o valor de n: ";
	cin>> n;
	for (fat=1;n>1;n=n-1)
	{
		fat=fat*n;
	}
	cout<<"Fatorial e : " <<fat<<endl;
}
