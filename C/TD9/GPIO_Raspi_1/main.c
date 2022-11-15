#include "leds.h"

int main(int argc, char** argv)
{
    Setup(1);
    Delete(1);
    do
    {
        if (digitalRead(INTER))
        {
            // ET --------------------------------------------------------------
            if (digitalRead(BP1) != HIGH && digitalRead(BP2) != HIGH)
            {
                digitalWrite(LED1, HIGH);
            }
            else
            {
                digitalWrite(LED1, LOW);
            }
            // OU --------------------------------------------------------------
            if (digitalRead(BP4) != HIGH)
            {
                digitalWrite(LED3, HIGH);
            }
            else if (digitalRead(BP3) != HIGH)
            {
                digitalWrite(LED3, HIGH);
            }
            else if (digitalRead(BP3) != LOW || digitalRead(BP4) != LOW)
            {
                digitalWrite(LED3, LOW);
            }
        }
        else
        {
            // OU exclusif -----------------------------------------------------
            if (digitalRead(BP4) != HIGH)
            {
                digitalWrite(LED3, HIGH);
            }
            else if (digitalRead(BP3) != HIGH)
            {
                digitalWrite(LED3, HIGH);
            }
            else if (digitalRead(BP3) != HIGH ^ digitalRead(BP4) != HIGH)
            {
                digitalWrite(LED3, LOW);
            }
            else if (digitalRead(BP3) != LOW && digitalRead(BP4) != LOW)
            {
                digitalWrite(LED3, LOW);
            }
        }
    }
    while (1);
}

