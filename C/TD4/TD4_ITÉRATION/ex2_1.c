/* 
 * File:   ex2_1.c
 * Author: cdaguenet
 *
 * Created on 12 octobre 2021, 13:53
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int dividende=21;
    int diviseur=15;
    int memo;
    while(diviseur!=0){
        memo=diviseur;
        diviseur=dividende%diviseur;
        dividende=memo;
    }
    printf("Le PGCD est %d",dividende);
    return (EXIT_SUCCESS);
}

