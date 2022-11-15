#include "monnayeur.h"
#include "boisson.h"
#include "menu.h"

int main(int argc, char** argv)
{
    T_PIECE lesPieces[NB_PIECES];
    T_BOISSONS lesBoissons[NB_BOISSONS];
    int montant;
    int choixP;
    int choixB;
    int quitter = 0; // Initialisation des valeurs

    InitialiserPieces(lesPieces); // Appel de l'initialisation des pièces
    InitialiserBoissons(lesBoissons); // Appel de l'initialisation des boissons
    do
    {
        printf("Voulez vous remplir le stock de pièces ? (0/1) : "); // Stock de pièces
        scanf("%d", &choixP);
        if (choixP == 1)
        {
            RemplirStockPieces(lesPieces); // Appel du remplissage du stock de pièces
            AfficherPiecesEnStock(lesPieces); // Appel de l'affichage du stock de pièces
            printf("\nAppuyez sur Espace puis Entrée pour continuer");
            while (getchar() != ' '); // Cancel
        }

        system("clear");

        printf("Voulez vous remplir le stock de boissons ? (0/1) : "); // Stock de boissons
        scanf("%d", &choixB);
        if (choixB == 1)
        {
            RemplirStockBoissons(lesBoissons); // Appel du remplissage du stock de boissons
            AfficherBoissonsEnStock(lesBoissons); // Appel de l'affichage du stock de boissons
            printf("\nAppuyez sur Espace puis Entrée pour continuer");
            while (getchar() != ' '); // Cancel
        }

        ChoisirBoisson(lesBoissons); // Appel du choix de la boisson
        AfficherBoissonsChoisies(lesBoissons); // Appel de l'affichage des boissons choisies

        IntroduirePieces(lesPieces); // Appel de l'introduction des pièces
        AfficherPiecesIntroduites(lesPieces); // Appel de l'affichage des pièces introduites
        printf("\nAppuyez sur une Espace puis Entrée pour continuer");
        while (getchar() != ' '); // Cancel

        montant = CalculerMontantIntroduit(lesPieces); // Calcul du montant
        printf("Le montant à rendre est de %.2f €\n", montant / 100.0);

        if (RendreMonnaie(lesPieces, montant)) // Rendu de monnaie
        {
            printf("Les pièces ont été rendues\n");
        }
        else
        {
            printf("Les pièces n'ont pas pu être rendues\n");
        }
        AfficherPiecesRendues(lesPieces); // Appel de l'affichage des pièces rendues
        // AfficherPiecesEnStock(lesPieces); // Appel de l'affichage du stock
        printf("\nAppuyez sur Echap puis 2 x Entrée pour quitter\n");
        while ((quitter = getchar()) != 0x1B);
    }
    while (quitter != 0x1B);
    return (EXIT_SUCCESS);
}

