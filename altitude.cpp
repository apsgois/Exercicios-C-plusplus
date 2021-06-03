#include <iomanip>
#include <iostream>
#include <cmath>
#include <locale.h>
#include <cstring>
#include <iomanip>

using namespace std;
int main ()
{
	cout<<fixed<<setprecision(2)<<endl;
	double x,maior=0,menor=99999999;
	
	cin>>x;
	while(x!=-1){
		if(x>maior)
		{
			maior=x;
		}
		if (x<menor)
		{
			menor=x;
		}
		cin>>x;
}
cout<<"Maior altitude: " <<maior<<endl;
cout<<"Menor altitude: " <<menor<<endl;

	
}