/**
 * @file Jeu2048.h
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */
#ifndef JEU2048_H
#define JEU2048_H

#include <iomanip>
#include <time.h>

#include "Clavier.cpp"

// ! Les valeurs peuvent être changées, fonctionnel sauf pour l'affichage selon la taille du terminal
#define TAILLE 4 // ! Taille de plateau
#define MAX 2048 // ! Nombre à atteindre (puissance de 2)

class Jeu2048
{

public:
    enum ETATS_DU_JEU
    {
        EN_COURS,
        PERDU,
        GAGNE
    };
    Jeu2048();
    ~Jeu2048();
    void PlacerNouvelleTuile();                       // ! Plaçage de la nouvelle tuile
    bool Calculer(const Clavier::TOUCHES _direction); // ! Calcul des tuiles si deux adjacentes
    void Deplacer(const Clavier::TOUCHES _direction); // ! Déplacement des tuiles
    int CalculerScore();                              // ! Calcul du score
    void ObtenirGrille(int _grille[][TAILLE]);        // ! Permet d'obtenir la grille
    ETATS_DU_JEU RechercherFinDePartie();             // ! Fin de partie en fonction de l'état du jeu

protected:
    int grille[TAILLE][TAILLE];
    int tuile_ajoutee[2];
};

#endif /* JEU2048_H */