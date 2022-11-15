/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 16 novembre 2021, 14:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Palindrome.h"
#include "Palindrome.c"

/*
 * 
 */

int main(int argc, char** argv)
{
    char laPhrase[TAILLE_CHAINE];
    int test1;
    int test2;

    printf("Entrez une phrase : ");
    fgets(laPhrase, TAILLE_CHAINE - 1, stdin);
    laPhrase[strlen(laPhrase) - 1 ] = '\0';

    VerifierPalindrome(laPhrase);
    if (VerifierPalindrome(laPhrase) == 0)
    {
        printf("Ça n'est pas un palindrome");
    }
    else
    {
        printf("C'est un palindrome");
    }

    return (EXIT_SUCCESS);
}