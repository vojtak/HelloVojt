//metropolis algortihm for configutaion generation

#include <ctime>
#include <cmath>


#include "randomc.h"			// random number generator
#include "parameters.h"			//key parameters of the calculation


// part of action sensitive to fi[i][j]  i-time, j-space index

double Spartj(double fi[Nt][Nx], int i, int j){

 int ip= (i+1)%Nt ;
 int im= (i-1)%Nt<0 ? (i-1)%Nt+Nt : (i-1)%Nt ;

 int jp= (j+1)%Nx ;
 int jm= (j-1)%Nx<0 ? (j-1)%Nx+Nx : (j-1)%Nx  ;

 return (0.5 * a*a *M*M * fi[i][j]*fi[i][j] +  fi[i][j]*(2*fi[i][j]-fi[ip][j]-fi[im][j]-fi[i][jp]-fi[i][jm]));
}



double xupdate(double fi[Nt][Nx], CRandomMersenne &RanGen){


    double counter =0;
	double oldfi;
	double olds,ds;
	int num;

	for(int i=0;i<Nt;i++){
		for(int j=0;j<Nx;j++){
			oldfi=fi[i][j];
			olds=Spartj(fi,i,j);

			fi[i][j]=fi[i][j]+ 2*(RanGen.Random() -0.5)*eps;

			ds=Spartj(fi,i,j)-olds;

			if( (ds>0) && (exp(-ds)<(RanGen.Random() ) )){
				fi[i][j]=oldfi;
				counter=counter+1;
			}
		}
	}

	num=Nt*Nx;
	return ((num-counter)/num);
}

