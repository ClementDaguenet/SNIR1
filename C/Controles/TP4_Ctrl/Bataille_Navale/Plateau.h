#ifndef PLATEAU_H
#define PLATEAU_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Flotte.h"

#define TAILLE 10

class Plateau {
public:
    Plateau(const string _nomDuFichier);
    void AfficherGrille();
    void Tirer(const char _vertical, const int _horizontal, const bool _cible);
    void Jouer();
private:
    char grille[100];
    Flotte laFlotte;
};

#endif /* PLATEAU_H */