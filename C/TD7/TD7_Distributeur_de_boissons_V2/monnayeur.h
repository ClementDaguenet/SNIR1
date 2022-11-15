#ifndef MONNAYEUR_H
#define MONNAYEUR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_NOM_OPTION 50
#define NB_PIECES 5

typedef struct
{
    int _valeur;
    int _nbStock;
    int _nbIntroduit;
    int _nbRendu;
    char _montant[10];
} T_PIECE;

void InitialiserPieces(T_PIECE _pieces[]);
void RemplirStockPieces(T_PIECE _pieces[]);
void AfficherPiecesEnStock(T_PIECE _pieces[]);
int RendreMonnaie(T_PIECE _pieces[], int _montant);
void AfficherPiecesRendues(T_PIECE _pieces[]);
void IntroduirePieces(T_PIECE _pieces[]);
void AfficherPiecesIntroduites(T_PIECE _pieces[]);
int CalculerMontantIntroduit(T_PIECE _pieces[]);

#endif /* MONNAYEUR_H */

