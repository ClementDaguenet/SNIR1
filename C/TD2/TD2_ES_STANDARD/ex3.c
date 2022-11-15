/* 
 * File:   ex3.c
 * Author: cdaguenet
 *
 * Created on 6 octobre 2021, 09:21
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char caractere;
    printf("valeur d'un caractere %d octet\n",sizeof(char));
    caractere = 0x80;
    printf("valeur minimum caractere %d \n",caractere);
    caractere = 0x7f;
    printf("valeur maximum caractere %d \n",caractere);

    short entierCourt;
    printf("valeur d'un entierCourt %d octet\n",sizeof(short));
    entierCourt = 0x8000;
    printf("valeur minimum entierCourt %d \n",entierCourt);
    entierCourt = 0x7fff;
    printf("valeur maximum entierCourt %d \n",entierCourt);

    int entier;
    printf("valeur d'un entierCourt %d octet\n",sizeof(int));
    entier = 0x80000000;
    printf("valeur minimum entierCourt %d \n",entier);
    entier = 0x7fffffff;
    printf("valeur maximum entierCourt %d \n",entier);

    long entierLong;
    printf("valeur d'un entierCourt %d octet\n",sizeof(long));
    entierLong = 0x8000000000000000;
    printf("valeur minimum entierCourt %ld \n",entierLong);
    entierLong = 0x7fffffffffffffff;
    printf("valeur maximum entierCourt %ld \n",entierLong);

    return (EXIT_SUCCESS);
}