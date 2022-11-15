#ifndef FLOTTE_H
#define FLOTTE_H

#include "Bateau.h"

class Flotte {
public:
    Flotte(const string _nomDuFichier);
    ~Flotte();
    Bateau::ETATS_BATEAU TirerSurLaFlotte(const char _vertical, const int _horizontal);
    Bateau::ETATS_BATEAU VerifierEtatDeLaFlotte();
    const int ObtenirNbBateaux();
private:
    static const int NB_BATEAUX_MAX = 5;
    int nbBateaux;
    Bateau *lesBateaux[NB_BATEAUX_MAX];
};

#endif /* FLOTTE_H */