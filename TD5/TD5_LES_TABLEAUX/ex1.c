/* 
 * File:   ex1.c
 * Author: cdaguenet
 *
 * Created on 20 octobre 2021, 09:04
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Si le résultat dans la console n'est pas complet merci de re-run le projet, 
 * c'est un bug que je n'arrive pas à résoudre mais l'exercice est bien fini
 */

#define NB_MESURES 28

int main(int argc, char** argv) {
    float temperatures[NB_MESURES] = {9.6, 9.4, 9.5, 5.1, 5.9, 7.7, 0.9, 1.4, -0.5,
        -3.6, -6.6, -3.1, -5.5, -4.8, 2.1, 5.4, 8.6,
        8.1, 3.7, 10.3, 9.2, 9.4, 8.5, 9.2, 6, 6.5, 2.7, 2.7};
    int indice;
    int cpt = 0;
    int jourf;
    int jourc;
    float min = temperatures[0];
    float max = temperatures[0];
    float somme = 0;
    for (indice = 0; indice <= NB_MESURES - 1; indice++) {
        printf("Le %1d février température : %.1f °C\n", indice + 1, temperatures[indice]);
        if (temperatures[indice] < 0) {
            cpt += 1;
        }
        if (min > temperatures[indice]) {
            min = temperatures[indice];
            jourf=indice+1;
        }
        if (max < temperatures[indice]) {
            max = temperatures[indice];
            jourc=indice+1;
        }
        somme += temperatures[indice];
    }
    printf("\nAu mois de février, il y a eu %d jours où la température était négative\n", cpt);
    printf("La moyenne des températures était de %.2f °C\n", somme / NB_MESURES);
    printf("Le %1d février était la journée la plus froide avec %.1f °C\n", jourf, min);
    printf("Le %1d février était la journée la plus chaude avec %.1f °C\n", jourc, max);
    return (EXIT_SUCCESS);
}