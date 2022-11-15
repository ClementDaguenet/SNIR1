#include "menu.h"

int AfficherMenu(const char *_titre, const char *_options[], const int _nbOptions)
{
    int indice;
    int choix;
    do
    {
        system("clear");
        printf("%s\n\n", _titre);
        for (indice = 0; indice < _nbOptions; indice++)
        {
            printf("%d - %s\n", indice + 1, _options[indice]);
        }
        printf("\n0 - Pour Sortir\n\n");
        printf("Votre choix svp : ");
        scanf("%d", &choix);
    }
    while (choix < 0 || choix > _nbOptions);
    return choix;
}