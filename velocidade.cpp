#include<iostream>
#include<iomanip>
#include <cmath>


using namespace std;
int main()
{
    cout<<fixed<<setprecision(2);
	// declaração de variaveis
	int i,No;
	double  hora, minimo, segundos, distancia, tempototal, tempoantes, distanciantes;
	double v[100], maior=0, menor=9999;

//	cout << "Digitre a quantidade de pontos durante o trajeto: ";
	cin >> No;



//	cout << "valor em horas: ";
	cin >> hora;

//	cout << "valor em minutos: ";
	cin >> minimo;

//	cout << "valor em segundos: ";
	cin >> segundos;

//	cout << "distancia do ponto: ";
	cin >> distancia;

	tempototal = hora * 3600 + minimo * 60 + segundos;

	for(i = 0; i < No - 1; i++)
	{
		tempoantes = tempototal;
		distanciantes = distancia;

	//	cout << "valor em horas: ";
		cin >> hora;

	//	cout << "valor em minutos: ";
		cin >> minimo;

	//	cout << "valor em segundos: ";
		cin >> segundos;

	//	cout << "distancia do ponto: ";
		cin >> distancia;

		tempototal = hora * 3600 + minimo * 60 + segundos;

		v[i] = abs( (distanciantes - distancia) / (tempoantes - tempototal));
        cout<<fixed<<setprecision(2);
	}
		
	for(i = 0; i < No - 1; i++)
	{
		cout<<abs(v[i])<<endl;
	}
	
	for(i = 0; i < No - 1; i++)
	{
		if(v[i] > maior)
		{
			maior=abs(v[i]);
		}
		if(v[i] < menor)
		{
			menor=abs(v[i]);
		}
	}
    
	cout<<"Velocidade Maxima: "<<maior<<endl;
	cout<<"Velocidade Minima: "<<menor<<endl;
	
	
	
	return 0;
	}