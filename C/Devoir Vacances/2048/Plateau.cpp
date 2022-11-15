/**
 * @file Plateau.cpp
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */
#include "Plateau.h"

void sleep(int second)
{
  time_t t = time(nullptr);
  while (time(nullptr) - t < second)
  {
    // * Fonction d'attente
  }
}

Plateau::Plateau()
{
  nbCoups = 0;
  score = CalculerScore(); // * Appel du calcul de score
}

Plateau::~Plateau()
{
}

void Plateau::Afficher() // ! Affichage du plateau de jeu
{
  int laGrille[TAILLE][TAILLE];
  system("clear");
  ObtenirGrille(laGrille);
  cout << "|\033[30;107m Score : " << score << " \033[0m|\033[30;107m Nombre de coups : " << nbCoups << " \033[0m|" << endl; // * Affichage du score et du nombre de coups
  cout << endl;
  for (int ligne = 0; ligne < TAILLE; ligne++)
  {
    cout << " +";
    for (int indice = 0; indice < TAILLE; indice++)
    {
      cout << setw(8) << setfill('-') << '+'; // *  Remplissage des lignes de jonction
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < TAILLE; j++)
    {
      if (laGrille[ligne][j] == 0)
      {
        cout << "|" << setw(6) << setfill(' ') << ' ' << ' ';
      }
      else
      {
        cout << "| \033[30m";
        if (tuile_ajoutee[0] == ligne && tuile_ajoutee[1] == j)
        {
          cout << "\033[1;3m"; //* Ajout d'une nouvelle tuile en gras et italique
        }

        string taille = to_string(laGrille[ligne][j]); // * Convertit le nombre en chaîne de caractère

        switch (laGrille[ligne][j])
        {
        case 2:
          cout << "\033[41m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 4:
          cout << "\033[42m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 8:
          cout << "\033[44m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 16:
          cout << "\033[43m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 32:
          cout << "\033[45m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 64:
          cout << "\033[46m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 128:
          cout << "\033[101m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 256:
          cout << "\033[102m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 512:
          cout << "\033[103m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 1024:
          cout << "\033[104m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        case 2048:
          cout << "\033[105m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break; // * Changement de la couleur de fond de la tuile
        default:
          cout << "\033[0m" << setw(3 + taille.length() / 2) << setfill(' ') << laGrille[ligne][j];
          break;
        } // * Limite de l'esthétique des tuiles pour ne pas surchager le code

        cout << setw(3 - taille.length() / 2) << setfill(' ') << '\0' << "\033[0m ";
      }
    }
    cout << '|' << endl;
  }
  cout << " +";
  for (int indice = 0; indice < TAILLE; indice++)
  {
    cout << setw(8) << setfill('-') << '+';
  }
  cout << endl;
  cout << endl;
  cout << "+" << setw(34) << setfill('-') << "+" << endl;
  cout << "| Z : ^ | S : v | Q : <- | D : -> |" << endl;
  cout << "| F : Fin du jeu                  |" << endl;
  cout << "+" << setw(34) << setfill('-') << "+" << endl;
  cout << "Votre choix : "; // * Affichage des possibilités de directions
}

bool Plateau::JouerCoup() // ! Tourne en boucle pour que le joueur joue
{
  bool retour = false;
  Clavier::TOUCHES touche = Clavier::touche_appuyee();
  if (touche == Clavier::UP || touche == Clavier::DOWN || touche == Clavier::LEFT || touche == Clavier::RIGHT)
  {
    Deplacer(touche); // * Déplacement selon la touche
    bool calcul = Calculer(touche);
    if (calcul)
    {
      Deplacer(touche); // * Déplacement selon la touche si on a calculé
    }

    bool tuile = false;
    for (int i = 0; i < TAILLE; i++)
    {
      for (int j = 0; j < TAILLE; j++)
      {
        if (grille[i][j] == 0)
        {
          tuile = true; // * Vérification de si on peut poser ou non une nouvelle tuile
        }
      }
    }

    if (tuile)
    {
      PlacerNouvelleTuile();
    }

    Jeu2048::ETATS_DU_JEU state = RechercherFinDePartie(); // * Recherche de la fin de partie
    nbCoups++;
    if (state == EN_COURS)
    {
      score = CalculerScore();
      Afficher(); // * Calcul du score + affichage si le jeu est toujours en cours
    }
    else
    {
      Afficher();
      cout << "Partie terminée !" << endl;
      sleep(2);
      AfficherFin(state); // * Affichage de l'écran de fin si partie terminée
      retour = true;
    }
  }

  if (touche == Clavier::ESCAPE)
    retour = true;

  if (touche == Clavier::NO)
  {
    Afficher();
    return JouerCoup(); // * Si une autre touche est appuyée
  }
  return retour;
}

void Plateau::AfficherFin(Jeu2048::ETATS_DU_JEU state)
{
  system("clear");
  if (state == Jeu2048::GAGNE)
  {
    cout << "+" << setw(36) << setfill('-') << "+" << endl;
    cout << "| \033[0m"
         << "\033[32m";
    cout << "BRAVO VOUS AVEZ GAGNÉ LA PARTIE !";
    cout << "\033[0m";
    cout << " |" << endl;
    cout << "+" << setw(36) << setfill('-') << "+" << endl;
  } // * Écran d'affichage de victoire
  else if (state == Jeu2048::PERDU)
  {
    cout << "+" << setw(40) << setfill('-') << "+" << endl;
    cout << "| \033[0m"
         << "\033[31m";
    cout << "DOMMAGE VOUS AVEZ PERDU LA PARTIE ...";
    cout << "\033[0m";
    cout << " |" << endl;
    cout << "+" << setw(40) << setfill('-') << "+" << endl;
  } // * Écran d'affichage de défaite
}