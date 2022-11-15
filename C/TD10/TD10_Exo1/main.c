#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{
    FILE *pFich;
    char carLu;
    int minuscules = 0;
    pFich = fopen("FichierTexte.txt", "r");
    do
    {
        carLu = fgetc(pFich);
        if (carLu != EOF)
            printf("%c", carLu);
        if (carLu >= 'a' && carLu <= 'z')
            minuscules += 1;
    }
    while (!feof(pFich));
    if (pFich == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    printf("Ce fichier contient %d minuscules non accentuées\n\n", minuscules);
    fclose(pFich);
    return (EXIT_SUCCESS);
}