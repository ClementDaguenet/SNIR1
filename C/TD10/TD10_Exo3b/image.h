#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct{
    // Signature
    char type1 = 1;
    char type2 = 2;
    // Taille fichier
    int taille1 = 3;
    int taille2 = 4;
    int taille3 = 5;
    int taille4 = 6;
    // Réservé
    // +4 |
    // Adresse relative des informations de l'image
    char adresse1 = 11;
    char adresse2 = 12;
    char adresse3 = 13;
    char adresse4 = 14;
}T_ENTETE_FICHIER_BMP;

typedef struct{
    // Taille en-tête
    int tailleET1 = 1;
    int tailleET2 = 2;
    int tailleET3 = 3;
    int tailleET4 = 4;
    // Largeur image \\
    int largeur1 = 5;
    int largeur2 = 6;
    int largeur3 = 7;
    int largeur4 = 8;
    // Hauteur image
    int hauteur1 = 9;
    int hauteur2 = 10;
    int hauteur3 = 11;
    int hauteur4 = 12;
    // Nombre de plans (toujours = 1)
    // +2 |
    // Bits utilisés par pixel
    int nbbits1=15;
    int nbbits2=16;
    // Type de compression
    char type1=17;
    char type2=18;
    char type3=19;
    char type4=20;
    // Taille image
    int taille1=21;
    int taille2=22;
    int taille3=23;
    int taille4=24;
    // Résolution horizontale
    // +4 |
    // Résolution verticale
    // +4 |
    // Nb couleurs utilisées
    int couleurs1=33;
    int couleurs2=34;
    int couleurs3=35;
    int couleurs4=36;
    // Nb couleurs importantes
    int couleursIM1=37;
    int couleursIM2=38;
    int couleursIM3=39;
    int couleursIM4=40;
}T_ENTETE_IMAGE_BMP;

int AfficherEnTeteFichierBMP(FILE *fichier);
int AfficherEnTeteImageBMP(FILE *fichier);

#endif /* IMAGE_H */

