/* 
 * File:   ex2_2.c
 * Author: cdaguenet
 *
 * Created on 12 octobre 2021, 14:19
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int dividende=1;
    int diviseur=1;
    float div;
    double somme;
    while(somme>=0,7854){
        div=dividende/diviseur;
        somme=div;
        dividende*=-1;
        diviseur+=2;
    }
    printf("%f",somme);
    return (EXIT_SUCCESS);
}

