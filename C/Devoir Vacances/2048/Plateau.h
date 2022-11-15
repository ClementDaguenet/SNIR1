/**
 * @file Plateau.h
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */
#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>

#include "Jeu2048.cpp"

using namespace std;

class Plateau : public Jeu2048
{
public:
    Plateau();
    ~Plateau();
    void Afficher();                               // ! Affichage du plateau
    bool JouerCoup();                              // ! Tourne en boucle pour que le joueur joue
    void AfficherFin(Jeu2048::ETATS_DU_JEU state); // ! Affichage du message de fin

private:
    int nbCoups;
    int score;
};

#endif /* PLATEAU_H */