#include <iostream>
#include <iomanip>
#include <cmath>

#define FS fixed <<setprecision (2)

using namespace std; //usar biblioteca

int main () { //funcao principal

double lat = 1, lon = 1, rlat[2019], rlon [2019], dist = 0.0;
int tam;

for (int i = 0; lat!= 0.0 && lon!= 0.0; i++){
    cin >> lat >> lon;
    rlat[i] = lat*3.1415926536/180.0;
    rlon[i] = lon*3.1415926536/180.0;
    tam = i;
}
for (int i = 0; i<(tam - 1); i++){
    dist+=6371.0*acos(sin(rlat[i])*sin(rlat[i+1])+cos(rlat[i])*cos(rlat[i+1])*cos(rlon[i+1]-rlon[i]));
}

cout << "Distancia total: " << FS << dist << " Km" <<endl;

return 0;
}