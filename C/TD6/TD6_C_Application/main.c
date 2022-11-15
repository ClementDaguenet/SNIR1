/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 16 novembre 2021, 14:06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char loginA [10] = "cisco";
    char mdpA [10] = "class";
    char login [10];
    char mdp [10];
    printf("Votre login ? : ");
    scanf("%s", login);
    printf("Votre mot de passe ? : ");
    scanf("%s", mdp);
    if (strcmp(loginA, login) == 0 && strcmp(mdpA, mdp) == 0) {
        printf("Accès autorisé");
    } else {
        printf("Accès refusé");
    }
    return (EXIT_SUCCESS);
}

