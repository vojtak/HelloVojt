#include <iostream>      //standard libraries
#include <cmath>


#include "randomc.h"		// random number generator
#include "statistic.h"

#include "parameters.h"

double mean(double func[], int size){

	double result =0;

	for(int i=0;i<size;i++){
		result=result+func[i];
	}

	return result/size;
}


double stdev(double func[], int size){

	double result =0;
	double av =0;

	for(int i=0;i<size;i++){
		result=result+func[i]*func[i];
	}

	av = mean(func, size);

	return sqrt(result/size-av*av);
}



void bootscopy(double neww[Nbins], double orig[Nbins], CRandomMersenne &RanGen){

	for(int i=0;i<Nbins;i++){
		neww[i]=orig[RanGen.IRandom(0,Nbins-1)];
	}

}



