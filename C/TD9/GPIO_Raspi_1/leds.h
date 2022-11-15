#ifndef LEDS_H
#define LEDS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7
#define BP1 0
#define BP2 1
#define BP3 2
#define BP4 3
#define INTER 10

int Setup (int nb);
int Delete (int nb);

#endif /* LEDS_H */

