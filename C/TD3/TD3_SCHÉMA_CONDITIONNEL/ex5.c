/* 
 * File:   ex5.c
 * Author: cdaguenet
 *
 * Created on 13 octobre 2021, 10:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int a = 2;
    int b = -3;
    int c = -4;
    float delta;
    float resultat1;
    float resultat2;
    delta = b * b - 4 * a*c;
    if (delta > 0) {
        resultat1 = ((-b - sqrt(delta)) / (a * 2));
        resultat2 = ((-b + sqrt(delta)) / (a * 2));
        printf("x1= %f\nx2= %f", resultat1, resultat2);
    }
    if (delta == 0) {
        resultat1 = -b / (2 * a);
        printf("%f", resultat1);
    }
    if (delta < 0) {
        printf("Pas de solution réelle");
    }
    return (EXIT_SUCCESS);
}

