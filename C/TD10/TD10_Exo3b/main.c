#pragma (push,1)
#include "image.h"
#include "menu.h"

// WORK IN PROGRESS !!

int main()
{
    T_ENTETE_FICHIER_BMP enteteFichier;
    T_ENTETE_IMAGE_BMP enteteImage;
    char *menu[] = {"En-tête Fichier", "En-tête Image"};

    FILE *pFich = fopen("imgBMP/plasma.bmp", "r");
    if (pFich != NULL)
    {
        int choix = AfficherMenu("Gestion d'image :", menu, 2);
        printf("%d\n", choix);
        //        printf(enteteFichier.taille1);
        //        printf(enteteImage.taille1);
    }
    else
    {
        printf("ERROR :\n\n%s\n\n", strerror(errno));
        exit(errno);
    }
    return (EXIT_SUCCESS);
}

