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

// int descartes_rule(double coef) 
// {


// }

double secant_method(double x0, double x1, double p)
{
    double new_x = 0;
    double temp;

    printf("new_x - x1=%.f\n", fabs(new_x - x1));
    while(fabs(x0 - x1) > E) {
        new_x = x1 - ((pow(x1, 2) - p) * (x1 - x0))/((pow(x1, 2) - p) - (pow(x0, 2) - p));        
        printf("new_x=%.f\n", new_x);
        temp = x1;
        printf("temp=%.f\n", temp);
        x1 = new_x; // novo ponto
        printf("x1=%.f\n", x1);
        x0 = temp; // ponto anterior
        printf("x0=%.f\n", x0);
    }

    return new_x;
}

// preparando a funcao
// p eh o numero q queremos a raiz
// exp eh o expoente da raiz (se eh quadrada, cubica, etc)
/*

se o objetivo eh achar a raiz quadrada de 5 entao
estamos procurando um numero tal que x² = 5.
Pra usar o metodo de newton passamos tudo pra um lado
so pra igualar a zero 
x² - 5 = 0
*/
double f(double x, double p, double exp) {
    return pow(x, exp) - p;
}

double d(double x, double p, double exp) {
    return exp * pow(x, exp-1);
}

// objetivo do metodo de newton -raphson (q eh um metodo iterativo)
// eh desocbrir o valor de x onde a funcao se anula ou seja f(x) = 0
double newton_raphson(double x, double p, double exp) 
{   
    double new_x = 0;
    while(f(x, p, exp) > 0) {
        new_x = x - f(x, p, exp)/d(x, p, exp);
        x = new_x;
    }

    return new_x;
}