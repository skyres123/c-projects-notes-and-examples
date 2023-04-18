#ifndef UTILITY_H
#define UTILITY_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void setRandomArray(int* pd, size_t n) {

    srand(time(NULL));
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












#endif // !UTILITY.H