#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "polynomial.h"


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