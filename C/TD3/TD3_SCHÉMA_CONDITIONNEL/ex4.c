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
    printf("Appuyez sur une touche suivie de Entrée : ");
    char touche;
    int puissance = 128;
    int total;
    char tc;
    do {
        touche = getchar();
        tc = touche;
        if (touche != 27 && touche != '\n') {
            printf("Touche étudiée : %c\n", touche);
            printf("Code ASCII en binaire : ");
            while (puissance >= 1) {
                if (touche >= puissance) {
                    printf("1");
                    touche -= puissance;
                    total += puissance;
                } else printf("0");
                puissance /= 2;
            }
            printf("\nCode ASCII en décimal : %d", total);
            printf("\nCode ASCII en hexadécimal : %X", total);
            printf("\nType : ");
            if (tc >= '0' && tc <= '9') {
                printf("Chiffre");
            } else {
                if (tc >= 'A' && tc <= 'Z') {
                    printf("Lettre majuscule");
                } else {
                    if (tc >= 'a' && tc <= 'z') {
                        printf("Lettre minuscule");
                    } else {
                        printf("Caractère autre");
                    }
                }
            }
            printf("\n\n");
        }
    } while (tc != 27);
    return (EXIT_SUCCESS);
}

