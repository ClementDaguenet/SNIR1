/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 23 novembre 2021, 13:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CrypteurDecrypteur.h"

#define TAILLE_CHAINE 50

int main(int argc, char** argv)
{
    char laChaine[TAILLE_CHAINE];
    printf("Écrivez une phrase : \n");
    gets(laChaine);
    Menu(laChaine);
    printf("Devient : %s", laChaine);
    return (EXIT_SUCCESS);
}