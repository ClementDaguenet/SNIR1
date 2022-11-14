/* 
 * File:   ex2.c
 * Author: cdaguenet
 *
 * Created on 19 octobre 2021, 14:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
#define NB_ELEMENTS 5

int main(int argc, char** argv) {
    int tableau[NB_ELEMENTS] = {5, 7, 2, 1, 4};
    int tour;
    int indice;
    int temp;
    
    for (indice = 0; indice < NB_ELEMENTS; indice++) {
            printf("%2d", tableau[indice]);
        }
        printf("\n\n");
    for (tour = 0; tour < NB_ELEMENTS -1; tour++) {
        for (indice = tour + 1; indice < NB_ELEMENTS; indice++) {
            if (tableau[tour] > tableau[indice]) {
                temp = tableau[tour];
                tableau[tour] = tableau[indice];
                tableau[indice] = temp;
            }
        }
        for (indice = 0; indice < NB_ELEMENTS; indice++) {
            printf("%2d", tableau[indice]);
        }
        printf("\n");
    }
    return (EXIT_SUCCESS);
}

