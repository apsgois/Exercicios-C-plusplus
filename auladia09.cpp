#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int main()
{
	struct dados
	{
		char desc[20];
		int quat,cod;
	}dados1[10];
	int i,codp,j,flag=0;
	for(int i=0;i<5;i++){
		
	cout<<"codigo: ";
	cin>>dados1[i].cod;
	cin.ignore();
	cout<<"Descricao: ";
	cin.getline(dados1[i].desc,20);
	cout<<"Quantidade: " ;
	cin>>dados1[i].quat;
	cout<<"-----------------------------------------"<<endl;
	}
	cout<<"\nDigite o codigo do produto: ";
	cin>>codp;
	for(j=0;j<5;j++)
	{
			if(dados1[j].cod==codp)
		{
			flag=1;
			cout<<endl<<"Descricao: "<<dados1[j].desc;
			cout<<endl<<"Quantidade: "<<dados1[j].quat;
		}
	}	
	if(flag==0)
			cout<<"Nao cadastrado"<<endl;
	
	
	
	return 0;	
}