#ifndef SERRURE_H
#define SERRURE_H

#include <Arduino.h>

class Serrure {
public:
    Serrure(uint8_t _broche);
    void Deverrouiller();
    void Verrouiller();
private:
    uint8_t broche = 2;
};

#endif /* SERRURE_H */

