#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include "Robot.h"
int main() {
	double * p =(double *)malloc(3 * sizeof(double));
	double * theta =(double* ) malloc(3 * sizeof(double));
	double loc[3] = { 4,4,3.5 };
	memcpy(p, loc,(3*sizeof(double)));
	

	InvKin(*p, *(p + 1), *(p + 2), theta);

	printf("%lf \n %lf \n %lf\n",theta[0], theta[1], theta[2]);
	
}