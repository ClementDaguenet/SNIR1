#define TAILLE_CHAINE 50

void Menu(char _chaine[])
{
    char demande[TAILLE_CHAINE];
    printf("Voulez vous la crypter ou la décrypter ? :\n");
    scanf("%s", demande);
    if (demande[0] == 'C' || demande[0] == 'c')
        Crypteur(_chaine);
    else if (demande[0] == 'D' || demande[0] == 'd')
        Decrypteur(_chaine);
    else
        printf("Erreur\n");
}

void Crypteur(char _chaine[])
{
    Convertir(_chaine);
    printf("Cryptage en cours...\n");
    char tableau2[] = "@8[03{6#1}:7wz*?o4$-v^m+/n";
    int indice;
    char lettre;
    for (indice = 0; _chaine[indice] != '\0'; indice += 1)
    {
        if (_chaine[indice] == ' ')
            _chaine[indice] = '-';
        else
        {
            lettre = _chaine[indice] - 'A';
            _chaine[indice] = tableau2[lettre];
        }

    }
}

void Decrypteur(char _chaine[])
{
    printf("Décryptage en cours...\n");
    char tableau1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char tableau2[] = "@8[03{6#1}:7wz*?o4$-v^m+/n-";
    int indice;
    int indice2;
    for (indice = 0; _chaine[indice] != '\0'; indice += 1)
        for (indice2 = 0; _chaine[indice2] != '\0'; indice2 += 1)
            if (_chaine[indice] == tableau2[indice2])
                _chaine[indice] == tableau1[indice2];
}

void Convertir(char _chaine[])
{
    int up;
    for (up = 0; _chaine[up] != '\0'; up += 1)
        _chaine[up] = toupper(_chaine[up]);
}