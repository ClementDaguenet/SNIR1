#define TAILLE_CHAINE 50

int SupprimerEspace(char _chaine[])
{
    int lecture = 0;
    int ecriture = 0;
    for (lecture = 0; _chaine[lecture] != '\0'; lecture++)
    {
        if (_chaine[lecture] != ' ')
        {
            _chaine[ecriture] = _chaine[lecture];
            ecriture += 1;
        }
    }
    _chaine[ecriture] = '\0';
    return lecture - ecriture;
}

void ConvertirMajusculeEnMinuscule(char _chaine[])
{
    int maj = 0;
    for (maj = 0; _chaine[maj] != '\0'; maj++)
    {
        _chaine[maj] = tolower(_chaine[maj]);
    }
}

int VerifierPalindrome(char _chaine[])
{
    SupprimerEspace(_chaine);
    ConvertirMajusculeEnMinuscule(_chaine);
    int debut = 0;
    int fin = strlen(_chaine) - 1;
    int i = 1;
    while (debut <= fin && _chaine[debut] == _chaine[fin])
    {
        debut += 1;
        fin -= 1;
    }
    if (_chaine[debut] != _chaine[fin])
    {
        i = 0;
    }
    return i;
}
