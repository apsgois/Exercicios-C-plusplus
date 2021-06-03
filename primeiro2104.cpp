#include <iomanip>
#include <iostream>
#include <cmath>
#include <locale.h>
#include <cstring>

using namespace std;
int main ()
{
	int s, h = 0, m = 0, i = 0;
	float a, n, soma1 = 0;
	
	cout<<"Digite o numero de pessoas: ";
	cin >> n;
	do
	{
		cout << "Digite a altura: ";
		cin >> a;
		cout << "Digite o sexo: ";
		cin >> s;

		while(s != 1 && s != 2)
			{
				cout << "sexo inválido\n";
				cout << "digite o sexo: ";
				cin >> s;
			}
		
		if(s == 1)
			h++;

		else if(s == 2)
			m++;
		
		soma1 = soma1 + a;
		i++;
	}
	while(i < n);

	cout << "homem " << h << endl;
	cout << "mulher " << m << endl;
	cout << soma1 / (h + m) << endl;
}

