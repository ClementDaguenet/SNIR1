/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 20 octobre 2021, 09:19
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */

#define NB_ELEMENTS 5

int main(int argc, char** argv) {
    int tableau[NB_ELEMENTS] = {5, 8, 2, 21, 1};
    int i, j, k, cpt, temp;
    printf("Tableau avant le tri: \n");
    for (k = 0; k < NB_ELEMENTS; k++) {
        printf("%4d", tableau[k]);
    }
    printf("\n\n");
    for (i = 0; i < NB_ELEMENTS - 1; i++) {
        cpt = 0;
        for (j = 0; j < NB_ELEMENTS - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                cpt += 1;
            }
        }
        for (k = 0; k < NB_ELEMENTS; k++)
            printf("%4d", tableau[k]);
        printf("    Nombre de permutations : %d", cpt);
        printf("\n");
    }
    for (k = 0; k < NB_ELEMENTS; k++) {
        printf("%4d", tableau[k]);
    }
    printf("    Nombre de permutations : %d", cpt - 1);
    printf("\n");
    return (EXIT_SUCCESS);
}