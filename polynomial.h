#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double max_coef(double *coef, int v_size);
void print_polynomial_terms(double* coef);
int descartes_rule(double coef);
double secant_method(double x0, double x1, double p);

#endif