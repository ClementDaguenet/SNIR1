#ifndef BATEAU_H
#define BATEAU_H

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Bateau {
public:

    enum ETATS_BATEAU {
        MANQUE,
        TOUCHE,
        COULE
    };
    Bateau(const string _nom, const char _vertical, const int _horizontal, const int _taille, const char _sens = 'H');
    ~Bateau();
    ETATS_BATEAU Torpiller(const char _vertical, const int _horizontal);
    string ObtenirNom();
    ETATS_BATEAU ObtenirEtatBateau();

private:
    string nom;
    char vertical;
    int horizontal;
    int taille;
    char sens;
    int *coque;
};

#endif /* BATEAU_H */