#include "Flotte.h"

Flotte::Flotte(const string _nomDuFichier) :
nbBateaux(0)
{
  ifstream fichier(_nomDuFichier);
  int indice = 0;
  if (!fichier.is_open())
  {
    cout << "Erreur lors de l'ouverture du fichier " << endl;
  }
  else
  {
    string nom;
    string position;
    int taille;
    char sens;
    char lettre;
    int chiffre;
    do
    {
      fichier >> nom >> position >> taille >> sens;
      if (fichier.good() && indice < NB_BATEAUX_MAX)
      {
        lettre = position.front();
        stringstream ss(position.substr(1));
        ss >> chiffre;
        lesBateaux[indice++] = new Bateau(nom, lettre, chiffre, taille, sens);
      }
    }
    while (!fichier.eof() && indice < NB_BATEAUX_MAX);
    nbBateaux = indice;
  }
  while (indice < NB_BATEAUX_MAX)
  {
    lesBateaux[indice++] = nullptr;
  }
}

Flotte::~Flotte() // Pointeur non trouvé
{
  //  if (... == nullptr)
  //    delete[] lesBateaux;
}

Bateau::ETATS_BATEAU Flotte::TirerSurLaFlotte(const char _vertical, const int _horizontal)
{
  int indice = 0;
  nbBateaux = indice;
  while (Bateau::MANQUE && indice < nbBateaux)
  {
    if (lesBateaux[indice] != nullptr)
      lesBateaux[indice]->Torpiller(_vertical, _horizontal);
  }
  return Bateau::MANQUE;
}

Bateau::ETATS_BATEAU Flotte::VerifierEtatDeLaFlotte()
{
  nbBateaux = ObtenirNbBateaux();
  if (nbBateaux == 0)
    return Bateau::COULE;
  if (nbBateaux > 0 && nbBateaux < NB_BATEAUX_MAX)
    return Bateau::TOUCHE;
  if (nbBateaux == NB_BATEAUX_MAX)
    return Bateau::MANQUE;
}

const int Flotte::ObtenirNbBateaux()
{

}