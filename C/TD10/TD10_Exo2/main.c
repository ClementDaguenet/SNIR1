#pragma pack(push, 1)
#include "exo2.h"

int main()
{
    FILE *pFich;
    T_PERSONNE personnes[NB_PERSONNES];
    size_t nbEnreg;
    size_t nbEcrits;
    for (int indice = 0; indice < NB_PERSONNES; indice += 1)
    {
        printf("Personne n°%d\n", indice + 1);
        CreerNouvellePersonne(&personnes[indice]);
    }
    pFich = fopen("personnes.bin", "wb");
    nbEnreg = fwrite(personnes, sizeof (T_PERSONNE), NB_PERSONNES, pFich);
    if (nbEnreg != NB_PERSONNES)
        exit(errno);

    fclose(pFich);
    pFich = fopen("personnes.txt", "w");
    for (int indice2 = 0; indice2 < NB_PERSONNES; indice2 += 1)
    {
        nbEcrits = fprintf(pFich, "%s %s %d %.0f %c\n", personnes[indice2].prenom, personnes[indice2].nom,
                           personnes[indice2].age, personnes[indice2].poids, personnes[indice2].sexe);
        if (nbEcrits < 0)
            exit(errno);
    }
    fclose(pFich);
    if (pFich == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    return (EXIT_SUCCESS);
}

