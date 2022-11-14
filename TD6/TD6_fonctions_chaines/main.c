/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 10 novembre 2021, 10:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    char chaine1 [50];
    char chaine2 [50];

    /* 2)  Réalisez un programme en langage C permettant la saisie d’une chaîne de caractères
     * et affiche sa longueur obtenue avec la fonction strlen
     */

    printf("Saisir la chaîne 1 : ");
    gets(chaine1);
    printf("La longueur de chaîne 1 est : %ld\n", strlen(chaine1));

    /* 3) Complétez le programme en permettant la saisie d’une deuxième chaîne, le programme
     * doit afficher si la chaîne est identique à la précédente, si elle est plus petite
     * ou plus grande dans l’ordre lexicographique
     */

    printf("Saisir la chaîne 2 : ");
    gets(chaine2);
    printf("La longueur de chaîne 2 est : %ld\n", strlen(chaine2));
    int n = strcmp(chaine1, chaine2);
    if (n > 0)
    {
        printf("La chaîne 1 est après la chaîne 2 lexicographiquement\n");
    }
    if (n == 0)
    {
        printf("La chaîne 1 est égale à la chaîne 2 lexicographiquement\n");
    }
    if (n < 0)
    {
        printf("La chaîne 1 est avant la chaîne 2 lexicographiquement\n");
    }
    /* 4) Complétez votre programme pour qu’il indique si la première chaîne de caractères
     * contient la deuxième
     */

    char *pos;
    pos = strstr(chaine1, chaine2);
    if (pos == NULL)
    {
        printf("La chaîne 2 n'est pas dans la chaîne 1\n");
    }
    else
    {
        printf("La chaîne 2 est dans la chaîne 1\n");
    }

    /* 5) Complétez le programme pour qu’il affiche si la première chaîne contient
     * le caractère ‘ ‘ ESPACE et si oui combien
     */
    char *espace = chaine1;
    int cpt = 0;
    while (espace != NULL)
    {
        espace = strchr(espace + 1, ' ');
        if (espace != NULL)
        {
            cpt += 1;
        }
    }
    printf("La chaîne 1 contient %d espaces\n", cpt);

    /* 6) Complétez le programme pour qu’il affiche le nombre de mots contenu dans
     * la première chaîne de caractères
     */

    char *mots = chaine1;
    int nb = 0;
    while (mots != NULL)
    {
        mots = strchr(mots + 1, ' ');
        if (mots != NULL)
        {
            nb += 1;
        }
    }
    printf("La chaîne 1 contient %d mots\n", nb+1);

    /* 7) Complétez votre programme pour qu’il recopie les deux chaînes de caractères
     * dans une troisième, séparée par un espace.
     * Cette troisième chaîne sera ensuite affichée
     */

    char chaine3 [100];
    strcpy(chaine3, chaine1);
    strcat(chaine3, " ");
    strcat(chaine3, chaine2);
    printf("Les deux chaînes à la suite : %s", chaine3);

    return (EXIT_SUCCESS);
}