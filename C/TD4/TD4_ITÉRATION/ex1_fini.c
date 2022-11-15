/* 
 * File:   ex1_fini.c
 * Author: cdaguenet
 *
 * Created on 12 octobre 2021, 13:28
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int nbr = 10;
    int resultat;
    int ancien;
    int ancienAvant;
    int indice;
    nbr -= 1;
    if (nbr == 0 || nbr == 1) {
        resultat = nbr;
    } else {
        ancienAvant = 1;
        ancien = 1;
        for (indice >= 2; indice <= nbr;) {
            resultat = ancien + ancienAvant;
            ancienAvant = ancien;
            ancien = resultat;
            indice += 1;
            printf("%d", resultat);
        }
    }
    return (EXIT_SUCCESS);
}

