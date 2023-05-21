#define _CRT_SECURE_NO_WARNINGS
#ifndef UTILITY_H
#define UTILITY_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int ival = 100;

int defin;
int f2();
void randoms() {
    srand((unsigned int)time(NULL));//
}

void setRandomArray(int* pd, size_t n) {

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; ++i) {

        pd[i] = rand() % 50;


    }
}
void displayArray(int* pd, size_t n) {

    for (int i = 0; i < n; ++i) {

        printf("%d\n", pd[i]);

    }
}

void st() {
    printf("\n==============================================================================================\n");
}

void bp(int val) {//herhangi bir sayýyý 2 lik tabana çevirir
    char buffer[40];
    _itoa(val, buffer, 2);
    printf("%s\n", buffer);
}











#endif // !UTILITY.H