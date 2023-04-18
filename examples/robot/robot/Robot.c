
#ifndef ROBOT_H
#define ROBOT_H

#include "Robot.h"



void InvKin(double px, double py, double pz, double theta[3]) {

	

	
	double a = l3;
	double b = l2;
	double c = l1 + (cos(theta[0]) * px) + (sin(theta[0]) * py);
	double d = pz;

	double cthetaj = (c * c + d * d - a * a - b * b) / 2 * a * b;
	double sthetaj = (sqrt(1 - cthetaj * cthetaj));

	double r = a * cthetaj + b;
	double s = a * sthetaj;

	theta[0] = atan2(-1 * py, px);
	theta[1] = atan2((r * d - s * c), (r * c + s * d));
	theta[2] = atan2(sthetaj, cthetaj);

}

#endif // !ROBOT_H