#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
	int idade;
	char nome[30];
	float altura, peso, imc;
	
	cin >> idade;
	cin.ignore();
	cin.getline(nome, 30);
	cin >> altura >> peso;
	
	imc = peso / pow(altura, 2);
	
	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << fixed << setprecision(2) << "IMC: " << imc << " kg/m^2" << endl;
	
	if (imc <= 15)
		cout << "Extremamente abaixo do peso" << endl;
	else if (imc <= 16)
		cout << "Gravemente abaixo do peso" << endl;
	else if (imc <= 18.5)
		cout << "Abaixo do peso ideal" << endl;
	else if (imc <= 25)
		cout << "Peso Ideal" << endl;
	else if (imc <= 30)
		cout << "Sobrepeso" << endl;
	else if (imc <= 35)
		cout << "Obesidade de grau I" << endl;
	else if (imc <= 40)
		cout << "Obesidade de grau II (grave)" << endl;
	else
		cout << "Obesidade de grau III (morbida)" << endl;
	return 0;
}