#include <iomanip>
#include <iostream>
#include <cmath>
#include <locale.h>
#include <cstring>

using namespace std;
int main ()
{
	cout<<fixed<<setprecision(2);
	float mi,i;
	int tempo=0;
	
	cout<<"Digite a massa inicial em gramas: ";
	cin>>mi;
	i=mi;
	while (i>=0.5)
	{
		tempo+=50;
		i=i/2;
	}
	cout<<"Massa inicial: "<<mi<<" gramas"<<endl;
	cout<<"Massa final: "<<i<<" gramas"<<endl;
	cout<<"Tempo gasto: "<<tempo<<" segundos"<<endl;
}