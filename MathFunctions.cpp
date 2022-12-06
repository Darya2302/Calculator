#include <iostream>
#include <math.h>
#include "MathFunctions.h"


int Calculate::unaryMinus(int a) { return -a; }
int Calculate::unaryPlus(int a) { return +a; }
int Calculate::mod(int a, int b) { return a % b; }
int Calculate::sum(int term1, int term2) { return term1 + term2; }
int Calculate::sub(int term1, int term2) { return term1 - term2; }
int Calculate::mult(int term1, int term2) { return term1 * term2; }
double Calculate::division(int term1, int term2) { return static_cast<double>(term1) / term2; }

int Calculate::absolute(int a) {
	if (a < 0) { return -a; }
	else { return a; }}
double Calculate::sqruareroot(double a) {
	return sqrt(a);}
double Calculate::reciprocalFunc(double a) {
	return (1 / a);
}
