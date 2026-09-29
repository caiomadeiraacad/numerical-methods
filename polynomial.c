#include "polynomial.h"

#define E 10e-5

double max_coef(double *coef, int v_size) 
{
    double max = coef[0];
    for(int i = 0; i < v_size; i++) {
        if (coef[i] > max)
            max = coef[i];
    }
    return max;
}


void print_polynomial_terms(double* coef) 
{
    int a = 4;
    for(int e = 0; e < 4; e++) {
        if (e > 1) {
            printf("[a%d] = %.fx^%d\n", a, coef[e], e);
        } else {
            printf("[a%d] = %.f\n", a, coef[e]);
        }
        a--;
    }
}

int descartes_rule(double coef) 
{


}

double secant_method(double x0, double x1, double p)
{
    double new_x = 0;
    double temp;

    while(fabs(new_x - x1) < E) {
        new_x = x1 - (pow(x1, 2) * (x1 - x0))/(pow(x1, 2) - (pow(x0, 2) - p));
        printf("temp=%.f\n", temp);
    }
}