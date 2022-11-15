/* 
 * File:   ex2.c
 * Author: cdaguenet
 *
 * Created on 5 octobre 2021, 15:25
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float tempCapteur = 17.568;
    float Celsius = (tempCapteur - 32)*5 / 9;
    printf("Température obtenue du capteur : %lf °F\n", tempCapteur);
    printf("Température convertie en degrés Celsius : %f °C", Celsius);
    return (EXIT_SUCCESS);
    
    float tempCelsius = -8.017777;
    float Fahrenheit = (tempCelsius *1.8)+32;
    printf("Température obtenue du capteur : %lf °C\n", tempCelsius);
    printf("Température convertie en degrés Fahrenheit : %f °F", Fahrenheit);
    return (EXIT_SUCCESS);
}


