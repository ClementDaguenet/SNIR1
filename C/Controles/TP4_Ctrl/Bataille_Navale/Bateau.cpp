#include "Bateau.h"

Bateau::Bateau(const string _nom, const char _vertical, const int _horizontal, const int _taille, const char _sens)
{
  Bateau::ETATS_BATEAU etatBateau = MANQUE;
  nom = _nom;
  vertical = _vertical;
  horizontal = _horizontal;
  taille = _taille;
  sens = _sens;
  coque[taille];
  for (int i = 0; i < _taille - 1; i++)
    coque[i] = 0;
}

Bateau::~Bateau() // Destructeur utilisé pour détruire le bateau quand son état = COULE
{
}

Bateau::ETATS_BATEAU Bateau::Torpiller(const char _vertical, const int _horizontal)
{
  int indice;
  int somme;
  switch (sens)
  {
  case 'H':
    if (_horizontal == horizontal && _vertical - vertical < taille)
    {
      coque[_horizontal - horizontal] = 1;
      return TOUCHE;
    }
    break;
  case 'V':
    if (_vertical == vertical && _horizontal - horizontal < taille)
    {
      coque[_vertical - vertical] = 1;
      return TOUCHE;
    }
    break;
  }
  for (indice = 0; indice < taille; indice++)
    somme += coque[indice];
  if (somme == taille)
    return COULE;
  return MANQUE;
}

string Bateau::ObtenirNom()
{
  return nom;
}

Bateau::ETATS_BATEAU ObtenirEtatBateau()
{

}