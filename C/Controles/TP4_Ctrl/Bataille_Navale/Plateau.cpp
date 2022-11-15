#include "Plateau.h"

Plateau::Plateau(const string _nomDuFichier) :
laFlotte(_nomDuFichier)
{
}

void Plateau::AfficherGrille()
{
  char lettre = 'A';
  int laGrille[TAILLE][TAILLE];
  system("clear");
  cout << "     1   2   3   4   5   6   7   8   9  10" << endl;
  for (int ligne = 0; ligne < TAILLE - 1; ligne++)
  {
    cout << "   +";
    for (int indice = 0; indice < TAILLE; indice++)
    {
      cout << setw(4) << setfill('-') << '+';
    }
    cout << endl;
    cout << ' ' << lettre++ << ' ';
    for (int j = 0; j < TAILLE; j++)
    {
      if (laGrille[ligne][j] == 0)
      {
        cout << "|" << setw(3) << setfill(' ') << ' ';
      }
    }
    cout << "|" << endl;
  }
  cout << "   +";
  for (int indice = 0; indice < TAILLE; indice++)
  {
    cout << setw(4) << setfill('-') << '+';
  }
  cout << endl << " J ";
  for (int j = 0; j < TAILLE + 1; j++)
  {
    cout << "|" << setw(2) << setfill(' ') << ' ' << ' ';
  }
  cout << endl << "   +";
  for (int indice = 0; indice < TAILLE; indice++)
  {
    cout << setw(4) << setfill('-') << '+';
  }
  cout << endl;
}

void Plateau::Tirer(const char _vertical, const int _horizontal, const bool _cible)
{

}

void Plateau::Jouer()
{
  Bateau::ETATS_BATEAU torpille;
  bool sortie = false;
  char vertical;
  int horizontal;
  if (laFlotte.ObtenirNbBateaux() != 0)
  {
    cout << "Entrer les coordonnées de la torpille : ";
    do
    {
      cin >> vertical >> horizontal;
      torpille = laFlotte.TirerSurLaFlotte(vertical, horizontal);
      switch (torpille)
      {
      case Bateau::TOUCHE:
        Tirer(vertical, horizontal, true);
        cout << "Rejouer : ";
        break;
      case Bateau::COULE:
        Tirer(vertical, horizontal, true);
        cout << "Bateau coulé... ";
        if (laFlotte.VerifierEtatDeLaFlotte() != Bateau::COULE)
          cout << "Rejouer : ";
        else
          sortie = true;
        break;
      case Bateau::MANQUE:
        Tirer(vertical, horizontal, false);
        cout << "Rejouer : ";
        break;
      }
    }
    while (sortie == false);
  }
  cout << "Fin de la partie !" << endl;
}