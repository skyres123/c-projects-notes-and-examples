#pragma once
#include <stdio.h>
#include <math.h>
/*
link 1 = 3 cm
link 2 = 5,5 cm
link 3 = 8,5 cm
*/
#define l1 3
#define l2 5.5
#define l3 8.5

#define c(x) cos(x)
#define s(x) sin(x)

void InvKin(double px, double py, double pz, double theta[3]);