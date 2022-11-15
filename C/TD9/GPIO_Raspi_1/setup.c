#include "leds.h"

int Setup(int nb)
{
    if (nb == 1)
    {
        wiringPiSetup();
        int indice;
        for (indice = LED1; indice <= LED4; indice++)
            pinMode(indice, OUTPUT);
        for (indice = BP1; indice <= BP4; indice++)
            pinMode(indice, INPUT);
        pinMode(INTER, INPUT);
    }
}

int Delete(int nb)
{
    if (nb == 1)
    {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
    }
    else
    {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
    }
}