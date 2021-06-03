#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	cout<<fixed<<setprecision (2);
	int l,n;
	double t,d,sd=0,st=0,s;
	
	cin>>n;
	for(l=1;l<=n;l++) // essa condição está correta?
	{
		cin>>d>>t;
		st=st+t;
		sd=sd+d;
	
	}
	s=sd/st;
	cout<<"Velocidade media = " <<s;
	
}