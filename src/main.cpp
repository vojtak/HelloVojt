//============================================================================
// Name        : pokus11.cpp
// Author      : Vojtech Krejcirik
// Version     :
// Copyright   : Your copyright notice
// Description : pokus
//============================================================================

#include <iostream>      //standard libraries
#include <cstdlib>
#include <ctime>
#include <cmath>
 


#include "parameters.h"		// parameters setting the calculation


#include "randomc.h"		// random number generator

#include "metropolis.h"		// metropolis algortihm for configutaion generation
#include "functions.h"		//
#include "statistic.h"		//



using namespace std;




int main()
{

		// ----------------------------------------------------------------- declarations etc.


	int seed = (int)time(0);            // random seed
									// choose one of the random number generators:
	CRandomMersenne RanGen(seed);       // make instance of random number generator



	// field configurations and metropolis acceptance
	double fi[Nt][Nx];
	double accep;

	//green function
//	double Gfunbin[Nt/2+1][Nbinsize];
	double Gfun[Nt/2+1][Nbins];
	double Gf[Nt/2+1], Gferr[Nt/2+1];


	//calculation of energies
	double dE[Nt/2], dEerr[Nt/2];


	//set of bootstrab copies
	double Gfuncopy[Nt/2+1][Nbins];
	double Gfunboots[Nt/2+1][Nboots];


	// ----------------------------------------------------------------- actual code starts

	//initialization of the fi[Nt][Nx] field
	for(int i=0;i<Nt;i++){
//		cout << i << " ::\t";
			for(int j=0;j<Nx;j++){
			fi[i][j]= int(10*(RanGen.Random() -0.5));
//			cout << fi[i][j] << "\t" ;
		}
//		cout << "\n";
	}


	//thermalizing the lattice + metropolis acceptance check
	accep=0;
	for(int i=0;i<100*Ncorel;i++){
		accep=accep+xupdate(fi,RanGen);
//		cout<< green(fi,1) << "\n";
	}

	accep=int(accep/(100*Ncorel)*100)%100;     // take care about number of sweeps
	cout << " Metropolis acceptance ratio : " << accep  << " %\n";
	cout <<	"------------------------------------\n\n";

	bool cont;
	cout << " Is it OK? (0=no ; 1=OK, go on)  ";
	cin >> cont;
	  if (cont==false)
	  {
		  cout << "\n --- the end --- \n\n";
		  exit(EXIT_SUCCESS);
      }

	cout << "\n" << " Let's go on then :" << "\n";
	cout <<	"--------------------\n\n";


for(int i=0;i<Nbins;i++){

	for(int j=0;j<Nbinsize;j++){
		

		xupdate(fi,RanGen);


		for(int k=0;k<Nt/2+1;k++){
				Gfun[k][i]= (j* Gfun[k][i] + green(fi,k))/(j+1);
					}
				
	}

//	for(int k=0;k<Nt/2+1;k++){
//		Gfun[k][i]=mean(Gfunbin[k],Nbinsize);
//		cout <<k<<i << "\t" << Gfun[k][i] << "\n";
//	}

}



for(int j=0;j<Nboots;j++){
	for(int i=0;i<Nt/2+1;i++){
		bootscopy(Gfuncopy[i],Gfun[i],RanGen);

		Gfunboots[i][j] = mean(Gfuncopy[i],Nbins);
	}
}



//	for(int i=0;i<Nt/2;i++)
//	cout << j << i << "\t" << Gfunavboots[i][j] << "\t" << Gfunavboots[i+1][j] << "\t" << dEboots[i][j] <<  "\n";
//	cout <<  "\n";



for(int k=0;k<Nt/2+1;k++){

	Gf[k] = mean( Gfunboots[k],Nboots)  ;
	Gferr[k] = stdev( Gfunboots[k],Nboots)  ;

}


cout << "\n - Nconf = "<< Nconf << " -- Nbinsize = "<< Nbinsize;
cout << " -- Nbins = "<< Nbins << " -- Nboots = "<< Nboots << " -- \n\n";


for(int k=1;k<Nt/2+1;k++){

	dE[k-1]= log(Gf[k-1]/Gf[k]) /a ;
	dEerr[k-1] = 1/a * sqrt ( Gferr[k-1]*Gferr[k-1]/(Gf[k-1]*Gf[k-1])  +  Gferr[k]*Gferr[k]/(Gf[k]*Gf[k]) ) ;


	cout << k-1 << "\t"  << dE[k-1] << "\t" << dEerr[k-1] << "\n";

}







 return 0;
 }


