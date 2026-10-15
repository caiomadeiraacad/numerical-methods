/*
 * Métodos Numéricos - Trabalho II
 * Autor: Caio Madeira e João Sperb
 * Compilação: gcc -O2 main.c -o main
 * Execução:   ./main 980
 *
 * Resultado para 980 figurinhas:
 * - 50%: 7107 figurinhas
 * - 75%: 7968 figurinhas
 * - 95%: 9657 figurinhas
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <numero_de_figurinhas>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("O numero de figurinhas deve ser maior que zero.\n");
        return 1;
    }

    double *P = (double *)calloc(N + 1, sizeof(double));
    if (P == NULL) {
        perror("Erro ao alocar memoria");
        return 1;
    }

    P[0] = 1.0;

    int compradas = 0;
    int meta50 = 0, meta75 = 0, meta95 = 0;

    while (P[N] <= 0.95) {
        compradas++;

        for (int k = N; k >= 1; k--) {
            double prob_repetida = (double)k / N;
            double prob_inedita  = (double)(N - (k - 1)) / N;

            P[k] = P[k] * prob_repetida + P[k - 1] * prob_inedita;
        }

        P[0] = 0.0;

        if (meta50 == 0 && P[N] > 0.50) {
            meta50 = compradas;
        }
        if (meta75 == 0 && P[N] > 0.75) {
            meta75 = compradas;
        }
        if (meta95 == 0 && P[N] > 0.95) {
            meta95 = compradas;
        }
    }

    printf("// %d figurinhas\n", N);
    printf("Para chegar a 50%% comprar %d figurinhas\n", meta50);
    printf("Para chegar a 75%% comprar %d figurinhas\n", meta75);
    printf("Para chegar a 95%% comprar %d figurinhas\n", meta95);

    free(P);
    return 0;
}
