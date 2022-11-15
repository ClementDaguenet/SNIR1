#ifndef BOISSON_H
#define BOISSON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_BOISSON 30
#define NB_BOISSONS 5

typedef struct 
{
    int _prix;
    int _nbStock;
    int _nbIntroduit;
    char _nom[NOM_BOISSON];
} T_BOISSONS;

void InitialiserBoissons(T_BOISSONS _boissons[]);
void AfficherBoissonsEnStock(const T_BOISSONS _boissons[]);
void RemplirStockBoissons(T_BOISSONS _boissons[]);
int ChoisirBoisson(T_BOISSONS _boissons[]);
void AfficherBoissonsChoisies(T_BOISSONS _boissons[]);

#endif /* BOISSON_H */