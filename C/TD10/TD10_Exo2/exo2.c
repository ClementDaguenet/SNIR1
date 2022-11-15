#include "exo2.h"

void CreerNouvellePersonne(T_PERSONNE *_personne)
{
    printf("Entrez le nom de la personne : ");
    scanf("%s", _personne->nom);
    printf("Entrez le prénom de la personne : ");
    scanf("%s", _personne->prenom);
    printf("Entrez l'âge de la personne : ");
    scanf("%d", &_personne->age);
    printf("Entrez le poids de la personne : ");
    scanf("%f", &_personne->poids);
    printf("Entrez le sexe de la personne : ");
    while (scanf("%c", &_personne->sexe) != 1 || _personne->sexe == '\n')
        fflush(stdin);
    system("clear");
}