#include "Serrure.h"

Serrure::Serrure(uint8_t _broche)
{

}

void Serrure::Deverrouiller()
{
  digitalWrite(broche, LOW);
  delay(500);
}

void Serrure::Verrouiller()
{
  digitalWrite(broche, HIGH);
  delay(500);
}