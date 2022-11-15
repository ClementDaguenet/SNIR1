#include "Coffre.h"

Coffre *leCoffre;
int broche = 2;

void setup()
{
  Serial.begin(115200);
  leCoffre = new Coffre;
}

void loop()
{
  leCoffre->Controler();
  leCoffre->PurgerCode();
}