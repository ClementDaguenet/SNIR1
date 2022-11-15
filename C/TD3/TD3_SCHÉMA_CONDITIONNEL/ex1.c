/* 
 * File:   ex1.c
 * Author: cdaguenet
 *
 * Created on 6 octobre 2021, 09:37
 */

#include <stdio.h>
#include <stdlib.h>
#define TAUX 8.11
/*
 * 
 */

int main(int argc, char** argv) {
    int volumeHeures=41;
    float total=0;
    if(volumeHeures>=35){
        volumeHeures=volumeHeures-35;
        total=35*TAUX;
    }else{
        total=volumeHeures*TAUX;
        volumeHeures=0;
    }
    if(volumeHeures>=4){
        volumeHeures=volumeHeures-4;
        total=(4*TAUX*1.2)+total;
    }else{
        total=(volumeHeures*TAUX*1.2)+total;
    }
    if(volumeHeures>=6){
        volumeHeures=volumeHeures-6;
        total=(6*TAUX*1.5)+total;
    }else{
        total=(volumeHeures*TAUX* 1.5)+total;
    }
    if(volumeHeures>0){
        total=(volumeHeures*TAUX* 1.8)+total;
    }
    printf("total = %.2f €",total);
    return (EXIT_SUCCESS);
}