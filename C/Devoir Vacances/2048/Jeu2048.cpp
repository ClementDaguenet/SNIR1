/**
 * @file Jeu2048.cpp
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */
#include "Jeu2048.h"

Jeu2048::Jeu2048()
{
  srand(time(nullptr));
  for (int i = 0; i < TAILLE; i++)
  {
    for (int j = 0; j < TAILLE; j++)
    {
      grille[i][j] = 0;
    }
  }
  PlacerNouvelleTuile(); // * Placement de la première tuile de façon aléatoire
}

Jeu2048::~Jeu2048()
{
}

void Jeu2048::PlacerNouvelleTuile() // ! Plaçage de la nouvelle tuile
{
  int random_ligne = rand() % TAILLE;
  int random_colonne = rand() % TAILLE;
  int random_chiffre = (((rand() % 2) + 1) * 2);
  if (grille[random_ligne][random_colonne] == 0)
  {
    grille[random_ligne][random_colonne] = random_chiffre;
    tuile_ajoutee[0] = random_ligne;
    tuile_ajoutee[1] = random_colonne;
  } // * Placement de toutes les tuiles suivantes de façon aléatoire
  else
  {
    PlacerNouvelleTuile();
  }
}

bool Jeu2048::Calculer(const Clavier::TOUCHES _direction) // ! Calcul des tuiles si deux adjacentes
{
  int ligne;
  int colonne;
  bool retour = false;
  for (int indice = 0; indice < TAILLE; indice++)
  {
    switch (_direction)
    {
    case Clavier::LEFT: // * Calcul des tuiles adjacentes selon la direction choisie
      for (ligne = 0; ligne < TAILLE; ligne++)
      {
        for (colonne = 0; colonne < TAILLE - 1; colonne++)
        {
          if (grille[ligne][colonne] == grille[ligne][colonne + 1])
          {
            grille[ligne][colonne] += grille[ligne][colonne + 1];
            grille[ligne][colonne + 1] = 0;
            retour = true;
          }
        }
      }
      break;
    case Clavier::RIGHT: // * Calcul des tuiles adjacentes selon la direction choisie
      for (ligne = TAILLE - 1; ligne >= 0; ligne--)
      {
        for (colonne = TAILLE - 1; colonne >= 1; colonne--)
        {
          if (grille[ligne][colonne] == grille[ligne][colonne - 1])
          {
            grille[ligne][colonne] += grille[ligne][colonne - 1];
            grille[ligne][colonne - 1] = 0;
            retour = true;
          }
        }
      }
      break;
    case Clavier::UP: // * Calcul des tuiles adjacentes selon la direction choisie
      for (colonne = 0; colonne < TAILLE; colonne++)
      {
        for (ligne = 0; ligne < TAILLE - 1; ligne++)
        {
          if (grille[ligne][colonne] == grille[ligne + 1][colonne])
          {
            grille[ligne][colonne] += grille[ligne + 1][colonne];
            grille[ligne + 1][colonne] = 0;
            retour = true;
          }
        }
      }
      break;
    case Clavier::DOWN: // * Calcul des tuiles adjacentes selon la direction choisie
      for (colonne = TAILLE - 1; colonne >= 0; colonne--)
      {
        for (ligne = TAILLE - 1; ligne >= 1; ligne--)
        {
          if (grille[ligne][colonne] == grille[ligne - 1][colonne])
          {
            grille[ligne][colonne] += grille[ligne - 1][colonne];
            grille[ligne - 1][colonne] = 0;
            retour = true;
          }
        }
        break;
      }
    }
  }
  return retour;
}

void Jeu2048::Deplacer(const Clavier::TOUCHES _direction) // ! Déplacement des tuiles
{
  int ligne;
  int colonne;
  for (int indice = 0; indice < TAILLE; indice++)
  {
    switch (_direction)
    {
    case Clavier::LEFT: //* Déplacement selon la direction choisie
      for (ligne = 0; ligne < TAILLE; ligne++)
      {
        for (colonne = 0; colonne < TAILLE - 1; colonne++)
        {
          if (grille[ligne][colonne] == 0)
          {
            grille[ligne][colonne] = grille[ligne][colonne + 1];
            grille[ligne][colonne + 1] = 0;
          }
        }
      }
      break;
    case Clavier::RIGHT: //* Déplacement selon la direction choisie
      for (ligne = TAILLE - 1; ligne >= 0; ligne--)
      {
        for (colonne = TAILLE - 1; colonne >= 1; colonne--)
        {
          if (grille[ligne][colonne] == 0)
          {
            grille[ligne][colonne] = grille[ligne][colonne - 1];
            grille[ligne][colonne - 1] = 0;
          }
        }
      }
      break;
    case Clavier::UP: //* Déplacement selon la direction choisie
      for (colonne = 0; colonne < TAILLE; colonne++)
      {
        for (ligne = 0; ligne < TAILLE - 1; ligne++)
        {
          if (grille[ligne][colonne] == 0)
          {
            grille[ligne][colonne] = grille[ligne + 1][colonne];
            grille[ligne + 1][colonne] = 0;
          }
        }
      }
      break;
    case Clavier::DOWN: //* Déplacement selon la direction choisie
      for (colonne = TAILLE - 1; colonne >= 0; colonne--)
      {
        for (ligne = TAILLE - 1; ligne >= 1; ligne--)
        {
          if (grille[ligne][colonne] == 0)
          {
            grille[ligne][colonne] = grille[ligne - 1][colonne];
            grille[ligne - 1][colonne] = 0;
          }
        }
      }
      break;
    }
  }
}

int Jeu2048::CalculerScore() // ! Calcul du score
{
  int somme = 0;
  for (int i = 0; i < TAILLE; i++)
  {
    for (int j = 0; j < TAILLE; j++)
    {
      somme += grille[i][j]; // * Score calculé et affiché en haut
    }
  }
  return somme;
}

void Jeu2048::ObtenirGrille(int _grille[][TAILLE]) // ! Permet d'obtenir la grille
{
  for (int i = 0; i < TAILLE; i++)
  {
    for (int j = 0; j < TAILLE; j++)
    {
      _grille[i][j] = grille[i][j]; // * Obtention de la grille
    }
  }
}

Jeu2048::ETATS_DU_JEU Jeu2048::RechercherFinDePartie() // ! Fin de partie en fonction de l'état du jeu
{
  bool victoire = false;
  bool defaite = true;
  for (int i = 0; i < TAILLE; i++)
  {
    for (int j = 0; j < TAILLE; j++)
    {
      if (grille[i][j] == MAX)
      {
        victoire = true; // * Si la valeur de la tuile est égale à MAX, victoire
      }
      if (grille[i][j] == 0)
      {
        defaite = false; // * Si au moins une tuile est égale à 0, on continue
      }
      if ((j < TAILLE - 1 && grille[i][j] == grille[i][j + 1]) || (j > 0 && grille[i][j] == grille[i][j - 1]) || (i < TAILLE - 1 && grille[i][j] == grille[i + 1][j]) || (i > 0 && grille[i][j] == grille[i - 1][j]))
      {
        defaite = false; // * Si pour toutes les tuiles, au moins une adjacente avec la même valeur, on continue
      }
    }
  }
  if (victoire)
  {
    return GAGNE;
  }
  else if (defaite)
  {
    return PERDU;
  }
  return EN_COURS;
}