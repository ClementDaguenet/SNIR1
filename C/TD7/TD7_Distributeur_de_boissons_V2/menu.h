#ifndef MENU_H
#define MENU_H
#define TAILLE_NOM_OPTION 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AfficherMenu(const char *_titre, const char _option[][TAILLE_NOM_OPTION], const int _nbOptions);

#endif // MENU_H