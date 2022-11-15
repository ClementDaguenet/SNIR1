#include "Ecran.h"

Ecran::Ecran() :
SSD1306Wire(0x3c, SDA, SCL, GEOMETRY_128_64)
{
  init();
  flipScreenVertically();
}

void Ecran::AfficherMessage(const String _message, const int _ligne)
{
  // Changement de la police et de la place du texte
  setFont(Dialog_plain_16);
  uint16_t position = getStringWidth(String(_message));
  // Clear de l'écran + Affichage en fonction de la ligne
  if (_ligne == 0)
  {
    setColor(BLACK);
    fillRect(0, 0, 128, 32);
    setColor(WHITE);
    drawString(12, 0, String(_message));
  }
  else if (_ligne == 1)
  {
    setColor(BLACK);
    fillRect(0, 32, 128, 32);
    setColor(WHITE);
    drawString(128 - position, 32, String(_message));
  }
  display();
}