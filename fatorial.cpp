#include <bits/stdc++.h>
// Com Parâmetro por Referência e Sem Retorno 
using namespace std;

	int Fat(int x)// tipo nome e parametro 
{	
	if(x==0)
		x=1;
	else {
		for(int y=x-1;y>=1;y--)
		{
			x=x*y;
		}	
	}
	return x;
}

int main ()
{

	int x; 
	
	do
	{	cout<<"Digite o valor de x: ";
		cin>>x;
	}while(x>10 ||x<0);
	
	cout<<"Fatorial: "<<Fat(x)<<endl;
	
return 0;
}