#include "Coffre.h"

Coffre::Coffre()
{
  ecran = new Ecran;
  leClavier = new Keypad(touches, brochesEnLigne, brochesEnColonne, LIGNES, COLONNES);
}

//Coffre~Coffre()
//{
//
//};

void Coffre::Controler()
{
  char touche = leClavier->getKey();
  if (touche != NO_KEY)
  {
    Serial.println(touche);
  }
}

void Coffre::PurgerCode()
{
  switch (etat)
  {
  case OUVERT:
    codeOuverture = "";
    break;
  case FERME:
    codeFermeture = "";
    break;
  }
  ecran->AfficherMessage("Code : ", 1);
}

void Coffre::AjouterChiffre(const char _chiffre)
{
  switch (etat)
  {
  case OUVERT:
    codeOuverture = "" + _chiffre;
    break;
  case FERME:
    codeFermeture = "" + _chiffre;
    break;
  }
}

void Coffre::Ouvrir()
{
  etat = OUVERT;
  ecran->AfficherMessage("Porte ouverte");
  digitalWrite(broche, HIGH);
  PurgerCode();
}

void Coffre::Fermer()
{
  etat = FERME;
  ecran->AfficherMessage("Porte fermée");
  digitalWrite(broche, LOW);
  PurgerCode();
}