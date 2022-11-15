/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 17 novembre 2021, 10:36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

#define TAILLE_CHAINE 50

int Verifier(char _chaine[]);
void SupprimerTerminaisons(char _chaine[]);
void Conjuguer(char _chaine[]);

int main(int argc, char** argv)
{
    char leVerbe[TAILLE_CHAINE];
    printf("Écrire un verbe à l'infinitif : ");
    scanf("%s", leVerbe);
    if (Verifier(leVerbe))
    {
        printf("C'est un verbe du 1er groupe\n");
        printf("Ses conjugaisons sont : \n");
        SupprimerTerminaisons(leVerbe);
        Conjuguer(leVerbe);
    }
    else
    {
        printf("Merci d'entrer un verbe du 1er groupe\n");
    }
    return (EXIT_SUCCESS);
}

int Verifier(char _chaine[])
{
    int retour;
    int len = strlen(_chaine);
    if (_chaine[len - 1] == 'r' && _chaine[len - 2] == 'e')
    {
        retour = 1;
    }
    return retour;
}

void SupprimerTerminaisons(char _chaine[])
{
    int len = strlen(_chaine);
    _chaine[len - 2] = '\0';
}

void Conjuguer(char _chaine[])
{
    char *terminaisons [6] = {"e", "es", "e", "ons", "ez", "ent"};
    char *sujets1 [6] = {"Je", "Tu", "Il/Elle", "Nous", "Vous", "Ils/Elles"};
    char *sujets2 [6] = {"J'", "Tu", "Il/Elle", "Nous", "Vous", "Ils/Elles"};
    int indice;
    for (indice = 0; indice < 6; indice++)
    {
        if (_chaine[0] == "a" || _chaine[0] == "e" || _chaine[0] == "é" || _chaine[0] == "i" || _chaine[0] == "o" || _chaine[0] == "u" || _chaine[0] == "y")
        {
            printf("%s %s%s\n", sujets2[indice], _chaine, terminaisons[indice]);
        }
        else
        {
            printf("%9s %s%s\n", sujets1[indice], _chaine, terminaisons[indice]);
        }
    }
}