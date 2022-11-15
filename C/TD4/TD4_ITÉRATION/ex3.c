/* 
 * File:   ex3.c
 * Author: cdaguenet
 *
 * Created on 13 octobre 2021, 09:24
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int main(int argc, char** argv) {
    int x, y;
    int n = 5;
    for (y = 1; y <= n; y++) {
        for (x = 1; x <= n; x++) {
            printf("%2d", x);
        }
        printf("\n");
    }
    return (EXIT_SUCCESS);
}