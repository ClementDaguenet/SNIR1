/* 
 * File:   main.c
 * Author: cdaguenet
 *
 * Created on 5 octobre 2021, 14:20
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int age=18 ;
    float taille=1.75 ;
    float note=15 ;
    char nom[255] = "toto" ;
    printf("bonjour %s vous avez %d ans, vous mesurez %f m, vous avez la note de %f /20",nom,age,taille,note);
    return (EXIT_SUCCESS);
}

