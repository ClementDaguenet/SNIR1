/**
 * @file Clavier.cpp
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */
#include "Clavier.h"

Clavier::TOUCHES Clavier::touche_appuyee()
{
    char key = 0;
    cin >> key;
    switch (toupper(key))
    {
    case 'Z':
        return UP; // ! Vers le haut
    case 'S':
        return DOWN; // ! Vers le bas
    case 'D':
        return RIGHT; // ! Vers la droite
    case 'Q':
        return LEFT; // ! Vers la gauche
    case 'F':
        return ESCAPE; // ! Fin du jeu
    default:
        return NO; // ! N'importe quelle touche
    }
}