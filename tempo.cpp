#include<iostream>
#include <cmath>

using namespace std;


int main ()

{
	int st,h,r,hi,mi,si,m,s;
	int hf,mf,sf;
	
	cin>>hi>>mi>>si>>hf>>mf>>sf;
	st=(hf*3600+(mf*60)+sf)-(hi*3600+(mi*60)+si);
	cout<<st<<" Segundos" <<endl;
	
	h=st/3600;
	r=st%3600;
	m=r/60;
	s=r%60;
	
	cout<<h<<":" <<m<<":"<<s<<endl;
}