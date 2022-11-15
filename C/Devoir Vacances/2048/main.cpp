/**
 * @file main.cpp
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */

#include "Plateau.cpp"

int main()
{
  Plateau plateau;
  plateau.Afficher(); // ! Appel de la fonction qui permet d'afficher le plateau de départ

  bool retour = false;
  while (!retour)
  {
    retour = plateau.JouerCoup(); // ! Boucle qui tourne tant que le jeu n'est pas fini
  }
  return 0;
}