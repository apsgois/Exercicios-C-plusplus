#include <bits/stdc++.h>
// Com Parâmetro por Referência e Sem Retorno 
using namespace std;

	void soma(double x,double y)// tipo nome e parametro 
{		
	double soma;
	soma=x+y;
	cout<<" "<<soma;
}

	void menos(double x,double y)// tipo nome e parametro 
{		
	double menos;
	menos=x-y;
	cout<<" "<<menos;
}
	void vezes(double x,double y)// tipo nome e parametro 
{		
	double vezes;
	vezes=x*y;
	cout<<" "<<vezes;
}
int main ()
{

	double x,y;
	char op;
	 
	
	cout<<"Digite os valores: ";
	cin>>x>>op>>y;
	//cout<<"Digite a operacao: ";
//	cin>>op;
	
	if(op=='+')
		soma(x,y);
	else if(op=='-')
		menos(x,y);
	else if(op=='*')
		vezes(x,y);
	
		
	
	
return 0;
}

