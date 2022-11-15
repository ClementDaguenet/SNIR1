#ifndef ECRAN_H
#define ECRAN_H

#include <Arduino.h>
#include <SSD1306Wire.h>
#include "font.h"

class Ecran : public SSD1306Wire {
public:
    Ecran();
    void AfficherMessage(const String _message, const int _ligne = 0);
private:

};

#endif /* ECRAN_H */