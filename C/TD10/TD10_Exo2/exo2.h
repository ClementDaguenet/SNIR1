#ifndef EXO2_H
#define EXO2_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NB_MAX_CAR 50
#define NB_PERSONNES 5

typedef struct 
{
    char nom[NB_MAX_CAR];
    char prenom[NB_MAX_CAR];
    int age;
    float poids;
    char sexe; // 'f' ou 'm'
} T_PERSONNE;

void CreerNouvellePersonne(T_PERSONNE *_personne);

#endif /* EXO2_H */

