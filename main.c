#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "polynomial.h"


int main(void)
{

    //double coef[] = { 1, -3, 2, -4 };
    //double coef[] = { -4, 2, -3, 1 };
    // size_t array_size = sizeof(coef) / sizeof(coef[0]); 

    // printf("coef size = %zu\n", array_size);
    // print_polynomial_terms(coef);

    // printf("an=%.f\n", max_coef(coef, array_size));

    // printf("%.8f\n", secant_method(0.23, 3.415, 2));

    printf("f(%d)=%.8f\n", 1, f(1, 5, 2));
    printf("d(%d)=%.8f\n", 1, d(1, 5, 2));

    printf("%.8f\n", newton_raphson(1, 5, 2));

    return 0;
}