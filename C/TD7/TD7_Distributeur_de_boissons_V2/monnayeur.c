#include "monnayeur.h"

void InitialiserPieces(T_PIECE _pieces[])
{
    // Pièce de 2 €
    _pieces[0]._valeur = 200;
    strcpy(_pieces[0]._montant, "2.00 €");
    // Pièce de 1 €
    _pieces[1]._valeur = 100;
    strcpy(_pieces[1]._montant, "1.00 €");
    // Pièce de 50 cents
    _pieces[2]._valeur = 50;
    strcpy(_pieces[2]._montant, "0.50 €");
    // Pièce de 20 cents
    _pieces[3]._valeur = 20;
    strcpy(_pieces[3]._montant, "0.20 €");
    // Pièce de 10 cents
    _pieces[4]._valeur = 10;
    strcpy(_pieces[4]._montant, "0.10 €");
}

void RemplirStockPieces(T_PIECE _pieces[])
{
    int numPiece;
    int indice;
    char nomPieces[NB_PIECES][TAILLE_NOM_OPTION]; // Initialisation des variables
    for (indice = 0; indice < NB_PIECES; indice++)
    {
        _pieces[indice]._nbStock = 0;
        strcpy(nomPieces[indice], _pieces[indice]._montant); // Copie des montants dans le tableau
    }
    do
    {
        numPiece = AfficherMenu("Ajouter des pièces dans le stock", nomPieces, NB_PIECES); // Affichage du menu
        if (numPiece != 0)
            _pieces[numPiece - 1]._nbStock += 1;
    }
    while (numPiece != 0);
}

void AfficherPiecesEnStock(T_PIECE _pieces[])
{
    system("clear");
    int indice;
    printf("Pièces en stock : \n\n"); // Affichage des pièces en stock
    for (indice = 0; indice < NB_PIECES; indice++)
    {
        printf("%s x %d\n", _pieces[indice]._montant, _pieces[indice]._nbStock);
    }
}

int RendreMonnaie(T_PIECE _pieces[], int _montant)
{
    system("clear");
    int indice;
    int retour = 0;
    for (indice = 0; indice < NB_PIECES - 1; indice++)
    {
        _pieces[indice]._nbRendu = 0;
        while (_montant > _pieces[indice]._valeur && _pieces[indice]._nbStock > 0)
        {
            _pieces[indice]._nbStock -= 1;
            _montant -= _pieces[indice]._valeur;
            _pieces[indice]._nbRendu += 1;
            retour += 1;
        }
    }
    if (_montant != 0)
        _montant = 0;
    return retour;
}

void AfficherPiecesRendues(T_PIECE _pieces[])
{
    system("clear");
    int indice;
    printf("Pièces rendues : \n\n");
    for (indice = 0; indice < NB_PIECES; indice++)
    {
        printf("%s x %d\n", _pieces[indice]._montant, _pieces[indice]._nbRendu);
    }
}

void IntroduirePieces(T_PIECE _pieces[])
{
    int indice;
    int numPiece;
    char nomPieces[NB_PIECES][TAILLE_NOM_OPTION];
    for (indice = 0; indice < NB_PIECES; indice++)
    {
        _pieces[indice]._nbIntroduit = 0;
        strcpy(nomPieces[indice], _pieces[indice]._montant);
    }
    do
    {
        numPiece = AfficherMenu("Ajouter des pièces pour payer", nomPieces, NB_PIECES);
        if (numPiece != 0)
            _pieces[numPiece - 1]._nbIntroduit += 1;
    }
    while (numPiece != 0);
}

void AfficherPiecesIntroduites(T_PIECE _pieces[])
{
    system("clear");
    int indice;
    printf("Pièces introduites :\n\n");
    for (indice = 0; indice < NB_PIECES; indice++)
    {
        printf("%s x %d\n", _pieces[indice]._montant, _pieces[indice]._nbIntroduit); // Affichage du nombre de chaque pièces
    }
}

int CalculerMontantIntroduit(T_PIECE _pieces[])
{
    int resultat = 0;
    int indice;
    for (indice = 0; indice < NB_PIECES; indice++)
    {
        resultat += _pieces[indice]._valeur * _pieces[indice]._nbIntroduit; // Calcul du montant
    }
    return resultat;
}