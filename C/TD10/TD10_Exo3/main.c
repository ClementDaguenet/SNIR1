#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#pragma (push,1)
#define MAX 4

int main()
{
    FILE *pFich = fopen("imgBMP/plasma.bmp", "r");
    if (pFich != NULL)
    {
        int largeur;
        size_t chercherLargeur = fseek(pFich, 18, SEEK_SET);
        fread(&largeur, MAX, 1, pFich);

        int hauteur;
        fread(&hauteur, MAX, 1, pFich);

        int taille;
        size_t chercherTaille = fseek(pFich, 8, SEEK_CUR);
        fread(&taille, MAX, 1, pFich);

        int couleurs;
        size_t chercherCouleurs = fseek(pFich, 12, SEEK_CUR);
        fread(&couleurs, MAX, 1, pFich);

        printf("IMAGE :\n\nLargeur : %d\n\nHauteur : %d\n\nTaille : %d\n%d x %d = %d\n\nCouleurs : %d\n",
               largeur, hauteur, taille, largeur, hauteur, largeur*hauteur, couleurs);
        fclose(pFich);
    }
    else
    {
        printf("ERROR :\n\n%s\n\n", strerror(errno));
        exit(errno);
    }
    return (EXIT_SUCCESS);
}

int fseek(FILE *stream, long offset, int whence);
/*
 * La fonction fseek() définit l'indicateur de position du flux pointé par
 * stream. La nouvelle position, mesurée en octets, est obtenue  en  addi‐
 * tionnant offset octets au point de départ indiqué par whence. Si whence
 * vaut SEEK_SET, SEEK_CUR, ou SEEK_END, le  point  de  départ  correspond
 * respectivement au début du fichier, à la position actuelle, ou à la fin
 * du fichier. Un appel réussi à fseek() efface  l'indicateur  de  fin  de
 * fichier  du  flux, et annule les effets de toute fonction ungetc(3) sur
 * le même flux.
 */

size_t fread(void *ptr, size_t size, size_t nmemb, FILE * stream);
/*
 * La  fonction  fread()  lit  nmemb éléments de données, chacun d'eux représentant
 * size octets de long, depuis le flux pointé par stream,
 * et les stocke à l'emplacement pointé par ptr.
 */