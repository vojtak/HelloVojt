// action and green function

#include <cmath>


#include "parameters.h"


using namespace std;


// Greens function

double green(double fi[Nt][Nx], int n){

	double gr = 0;
	for(int j=0;j<Nx;j++){
		for(int i=0;i<Nt;i++){
		gr = gr + fi[i][j]*fi[(i+n)%Nt][j];
		}
	}
	return gr/(Nx*Nt);
}

double green3(double fi[Nt][Nx], int n){

	double gr = 0;
	for(int i=0;i<Nt;i++){
	gr = gr + fi[i][Nx/2]*fi[(i+n)%Nt][Nx/2]*fi[i][Nx/2]*fi[(i+n)%Nt][Nx/2]*fi[i][Nx/2]*fi[(i+n)%Nt][Nx/2];
	}

	return gr/Nt;
}

