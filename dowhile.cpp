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
	fat=1;
	do
	{
		fat=fat*n;
		n=n-1;
	}
	while(n>0);
	
	cout<<"Fatorial e : " <<fat<<endl;
	
	
}