/* 
 * File:   ex2.c
 * Author: cdaguenet
 *
 * Created on 6 octobre 2021, 10:46
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int an=52;
    if (0==an%400){
        printf("%d est bissextile",an);
    }else{
        if(0==an%4){
            if(00!=an%100){
                printf("%d est bissextile",an);
            }else{
                printf("%d est non bissextile",an);
            }
        }else{
            printf("%d est non bissextile",an);
        }
    }

    return (EXIT_SUCCESS);
}

