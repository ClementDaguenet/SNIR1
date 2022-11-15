#include "boisson.h"
#include "menu.h"

void InitialiserBoissons(T_BOISSONS _boissons[])
{
    // Café sucre à 1 €
    _boissons[0]._prix = 100;
    strcpy(_boissons[0]._nom, "Café sucré   (1 euro)");
    // Café au lait à 1 €
    _boissons[1]._prix = 100;
    strcpy(_boissons[1]._nom, "Café au lait (1 euro)");
    // Chocolat à 1 €
    _boissons[2]._prix = 100;
    strcpy(_boissons[2]._nom, "Chocolat     (1 euro)");
    // Coca Cola à 1.5 €
    _boissons[3]._prix = 150;
    strcpy(_boissons[3]._nom, "Coca cola    (1,5 euro)");
    // Orangina à 1.5 €
    _boissons[4]._prix = 150;
    strcpy(_boissons[4]._nom, "Orangina     (1,5 euro)");
}

void RemplirStockBoissons(T_BOISSONS _boissons[])
{
    int indice;
    int numBoisson;
    char nomBoissons[NB_BOISSONS][TAILLE_NOM_OPTION]; // Initialisation des valeurs

    for (indice = 0; indice < NB_BOISSONS; indice++)
    {
        _boissons[indice]._nbStock = 0;
        strcpy(nomBoissons[indice], _boissons[indice]._nom); // Ajout des boissons dans le tableau
    }
    do
    {
        numBoisson = AfficherMenu("Ajouter des boissons dans le stock", nomBoissons, NB_BOISSONS);
        if (numBoisson != 0)
            _boissons[numBoisson - 1]._nbStock += 1;
    }
    while (numBoisson != 0);
}

void AfficherBoissonsEnStock(const T_BOISSONS _boissons[])
{
    system("clear");
    int indice;
    printf("Boissons en stock\n\n"); // Affichage des boissons en stock
    for (indice = 0; indice < NB_BOISSONS; indice++)
    {
        printf("%s x %d\n", _boissons[indice]._nom, _boissons[indice]._nbStock);
    }
}

int ChoisirBoisson(T_BOISSONS _boissons[])
{
    int indice;
    int choix;
    char nomBoissons[NB_BOISSONS][TAILLE_NOM_OPTION]; // Initialisation des valeurs
    for (indice = 0; indice < NB_BOISSONS; indice++)
    {
        _boissons[indice]._nbIntroduit = 0;
        strcpy(nomBoissons[indice], _boissons[indice]._nom);
    }
    do
    {
        choix = AfficherMenu("Choix de la boisson", nomBoissons, NB_BOISSONS); // Choix de la boisson
        if (choix != 0)
            _boissons[choix - 1]._nbIntroduit += 1;
    }
    while (choix != 0);
    return choix;
}

void AfficherBoissonsChoisies(T_BOISSONS _boissons[])
{
    system("clear");
    int indice;
    printf("Boissons choisies : \n");
    for (indice = 0; indice < NB_BOISSONS; indice++)
    {
        printf("%s x %d\n", _boissons[indice]._nom, _boissons[indice]._nbIntroduit); // Affichage du nombre de chaque boissons
    }
}