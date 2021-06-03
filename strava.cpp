#include<iostream>
#include<cmath>
#include<iomanip>
#include <fstream>

using namespace std;

ofstream arq;
double distancia(double latitudef , double longitudef , double latitudef1 , double longitudef1)
{
	double dlat , dlon , a , b , c;
	dlat = ((latitudef * 3.1415926536) / 180.0) - ((latitudef1 * 3.1415926536) / 180.0);
	dlon = ((longitudef * 3.1415926536) / 180.0) - ((longitudef1 * 3.1415926536) / 180.0);
	a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos((latitudef1 * 3.1415926536) / 180.0) * cos((latitudef * 3.1415926536) / 180.0) * sin(dlon / 2.0) * sin(dlon / 2.0);
	b = 2 * atan2(sqrt(a), sqrt(1 - a));
	c = (6371 * b);
	return c;
}
int calctemp(int horaf , int minutof , int segundof , int horaf1 , int minutof1 , int segundof1)
{
	return ((horaf - horaf1) * 3600 + (minutof - minutof1) * 60 + (segundof - segundof1));
}
double calcvel(double latitudef , double longitudef , double latitudef1 , double longitudef1 , int horaf , int minutof , int segundof , int horaf1 , int minutof1 , int segundof1)
{
	double dlat , dlon , a , b , c , t;
	dlat = ((latitudef * 3.1415926536) / 180.0) - ((latitudef1 * 3.1415926536) / 180.0);
	dlon = ((longitudef * 3.1415926536) / 180.0) - ((longitudef1 * 3.1415926536) / 180.0);
	a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos((latitudef1 * 3.1415926536) / 180.0) * cos((latitudef * 3.1415926536) / 180.0) * sin(dlon / 2.0) * sin(dlon / 2.0);
	b = 2 * atan2(sqrt(a), sqrt(1 - a));
	c = (6371 * b) * 1000;
	t = ((horaf - horaf1) * 3600 + (minutof - minutof1) * 60 + (segundof - segundof1));
	return (c / t) * 3.6;
}
double calcelev1(double elevacao , double elevacao1)
{
	double ganho = 0;
	if((elevacao1 - elevacao) < 0)
		ganho = ganho - (elevacao1 - elevacao);
	return ganho;
}
double calcelev2(double elevacao , double elevacao1)
{
	double perda = 0;
	if((elevacao1 - elevacao) > 0)
		perda = perda - (elevacao1 - elevacao);
	return perda;
}
void converseg(int tempemseg)
{

	int m , h;
	m = 0;
	while(tempemseg >= 60)
	{
		tempemseg = tempemseg - 60;
		m = m + 1;
	}
	h = 0;
	while(m >= 60)
	{
		m = m - 60;
		h = h + 1;
	}
	arq << "Tempo total decorrido: " << h << ":" << m << ":" << tempemseg << endl;
}

int main()
{
	ifstream arq1;

	double latitude , longitude , latitude1 , longitude1 , elevacao , elevacao1 , distotal = 0 , vel , maiorvel = 0 , ganhoelev = 0 , perdaelev = 0 , maiorelev = 0 , menorelev = 9000;
	int hora , minuto , segundo , hora1 , minuto1 , segundo1 , i = 0 , temptotalseg = 0;
	arq1.open("strava.txt", ifstream::in);
	arq1>> latitude >> longitude;
	if(longitude != -00.000000)
	arq1 >> elevacao >> hora >> minuto >> segundo;
	while(longitude != -00.000000)
	{
		if(i > 0)
		{
			vel = calcvel(latitude , longitude , latitude1 , longitude1 , hora , minuto , segundo , hora1 , minuto1 , segundo1);
			if(vel > maiorvel)
				maiorvel = vel;
		}
		if(i > 0)
			distotal = distotal + distancia(latitude , longitude , latitude1 , longitude1);
		latitude1 = latitude;
		longitude1 = longitude;
		if(i > 0)
			temptotalseg = temptotalseg + calctemp(hora , minuto , segundo , hora1 , minuto1 , segundo1);
		hora1 = hora;
		minuto1 = minuto;
		segundo1 = segundo;
		if(elevacao > maiorelev)
			maiorelev = elevacao;
		if(elevacao < menorelev)
			menorelev = elevacao;
		if(i > 0)
		{
			ganhoelev = ganhoelev + calcelev1(elevacao , elevacao1);
			perdaelev = perdaelev + calcelev2(elevacao , elevacao1);
		}
		elevacao1 = elevacao;
		arq1 >> latitude >> longitude;
		if(longitude != -00.000000)
		arq1 >> elevacao >> hora >> minuto >> segundo;
		i++;
		
	}
	arq1.close();
	//cout << fixed << setprecision(2) << "Distancia total: " << distotal << " km" << endl;
	arq.open("strava.txt", ofstream::out);
	arq << fixed << setprecision(2) << "Distancia total: " << distotal << " km" << endl;
	converseg(temptotalseg);
	//cout << fixed << setprecision(2) << "Velocidade maxima: " << maiorvel << " km/h" << endl;
	//arq.open("strava.txt", ofstream::out);
	arq << fixed << setprecision(2) << "Velocidade maxima: " << maiorvel << " km/h" << endl;
	//cout << fixed << setprecision(2) << "Velocidade media: " << ((distotal * 1000) / temptotalseg) * 3.6 << " km/h" << endl;
	//arq.open("strava.txt", ofstream::out);
	arq << fixed << setprecision(2) << "Velocidade media: " << ((distotal * 1000) / temptotalseg) * 3.6 << " km/h" << endl;
	//cout << fixed << setprecision(2) << "Ganho de elevacao: " << ganhoelev << " m" << endl;
//	arq.open("strava.txt", ofstream::out);
	arq <<fixed << setprecision(2) << "Ganho de elevacao: " << ganhoelev << " m" << endl;
	//cout << fixed << setprecision(2) << "Perda de elevacao: " << perdaelev << " m" << endl;
	//arq.open("strava.txt", ofstream::out);
	arq << fixed << setprecision(2) << "Perda de elevacao: " << perdaelev << " m" << endl;
	//cout << fixed << setprecision(2) << "Maior altitude: " << maiorelev << " m" << endl;
//	arq.open("strava.txt", ofstream::out);
	arq << fixed << setprecision(2) << "Maior altitude: " << maiorelev << " m" << endl;
	//cout << fixed << setprecision(2) << "Menor altitude: " << menorelev << " m" << endl;
//	arq.open("strava.txt", ofstream::out);
	arq << fixed << setprecision(2) << "Menor altitude: " << menorelev << " m" << endl;
	
	arq.close();
	return 0;
	
}
