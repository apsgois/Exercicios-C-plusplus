#include <iomanip>
#include <iostream>
#include <cmath>
#include <locale.h>
#include <cstring>
#include <iomanip>

using namespace std;
int main ()
{
	int mat, s = 0, x = 0;
	float np1, np2, m;

	do
	{
		cout << "Digite a matricula ou zero para sair: " ;
		cin >> mat;

	}
	while (mat < 0);//validar se a matricula é valida ou seja maior que zero 

	while (mat != 0)//matricula diferente de zero 
	{

		do // faz: entre com a nota 1 para validar 
		{
			cout << "Entre com a NP1o: ";
			
			cin >> np1;
		}
		while (np1 < 0 || np1 > 100);// enquanto a nota1 for maior que zero e menor que 100.

		do//faz: entra com a np2 e verifica 
		{
			cout << "Entre com o NP2: ";
			cin >> np2;

		}
		while (np2 < 0 || np2 > 100);// se é maior que zero e menor que 100

			m = ((np1 + np2) / 2); // calcula a media 
		cout<<"media do aluno: " << m <<endl; // media 

		s = s + m;// encremenata na variavel s a quantidade da media  


		x++;//contador de vezes que entrou com a matricula 
		do
		{
			cout << "Digite a matricula ou zero para sair : " ; // valida se entra com a matricula novamente 
			cin >> mat;

		}
		while (mat < 0);// matricula menor que zero refaz. 



	}
	cout << "Media greal: " << s / x << endl;// media s(media encrementada) e x (quantidade de matricula) 
}



