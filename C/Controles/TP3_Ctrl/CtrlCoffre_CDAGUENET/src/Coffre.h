#ifndef COFFRE_H
#define COFFRE_H

#include <Keypad.h>
#include "Ecran.h"

class Coffre {
public:
    Coffre();
    ~Coffre();

    enum ETATS_DU_COFFRE {
        OUVERT,
        FERME
    };
    void Controler();
    void PurgerCode();
    void Ouvrir();
    void Fermer();
    void AjouterChiffre(const char _chiffre);
private:

    Ecran *ecran;
    Keypad *leClavier;
    char codeOuverture;
    char codeFermeture;
    static const uint8_t LIGNES = 4;
    static const uint8_t COLONNES = 3;
    char touches[LIGNES * COLONNES] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9',
        '*', '0', '#'
    };
    uint8_t brochesEnLigne[LIGNES] = {33, 25, 26, 27};
    uint8_t brochesEnColonne[COLONNES] = {14, 12, 13};
    short etat;
};

#endif /* COFFRE_H */

