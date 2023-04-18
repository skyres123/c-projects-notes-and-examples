#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void displayArray(const int* pa, size_t size) {
    int loop;
    for (loop = 0; loop < size; loop++)
        printf("%d ", pa[loop]);
}
int sumArray(const int* pa, size_t size) {
    int sum = 0;

    for (int i = 0; i < size; ++i)
        sum += pa[i];

    return sum;
}
void st() {
    printf("\n==================================================\n");
}

double getAverage(const int* pa, size_t size) {
    return (sumArray(pa, size) / (double)size);
}
/*
int maxArray(const int* pa, size_t size) {
    int max;
    for (int i = 0; i < size-1; ++i){
        if (*pa[i] > &pa[i + 1]) {
            max = *pa[i];
        }
    }
    return max;
}*/

int main() {
    int dizi[ARRAY_SIZE] = { 5,1,2,3,5 };

    int result = sumArray(dizi, ARRAY_SIZE);

    printf("%d", result);
    
    st();

    double res2 = getAverage(dizi, ARRAY_SIZE);
    printf("%.2f", res2);
    
    st();

   

}