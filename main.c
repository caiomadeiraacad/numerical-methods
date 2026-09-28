#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
//#include "polynomial.h"


double max_coef(double *coef, int v_size) {
    double max = coef[0];
    for(int i = 0; i < v_size; i++) {
        if (coef[i] > max)
            max = coef[i];
    }
    return max;
}

double first_coef

void print_polynomial_terms(double* coef) {
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

int descartes_rule(double coef) {


}

int main(void)
{

    //double coef[] = { 1, -3, 2, -4 };
    double coef[] = { -4, 2, -3, 1 };
    size_t array_size = sizeof(coef) / sizeof(coef[0]); 

    printf("coef size = %zu\n", array_size);
    print_polynomial_terms(coef);

    printf("an=%.f\n", max_coef(coef, array_size));

    return 0;
}