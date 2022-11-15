/* 
 * File:   ex3.c
 * Author: cdaguenet
 *
 * Created on 6 octobre 2021, 11:17
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char touche;
    touche = getchar();
    int puissance = 128;
    int total;
    printf("Code ASCII de %c en binaire :", touche);
    while (puissance >= 1) {
        if (touche >= puissance) {
            printf("1");
            touche -= puissance;
            total += puissance;
        } else printf("0");
        puissance /= 2;
    }
    printf("\nCode ASCII de %c en décimal %d", touche, total);
    printf("\nCode ASCII de %c en hexadécimal %X", touche, total);
    return (EXIT_SUCCESS);
}

