#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "utility.h"
#include <string.h>
#include <ctype.h>
int sum(int x, int y) {
	return x + y;
}
void f1() {
	printf("f1\n");
}
void f2_() {
	printf("f2\n");
}
void f3() {
	printf("f3\n");
}
void func(void(*fp)(void)) {//fonksiyon adresi,  bir fonksiyon parametresi olabilir
	printf("func ca�r�ld� \n");
}
/*
int(*func(int ch))(int){//geri d�n�� de�eri bir fonksiyon adresi
	return &isupper;
}*/
typedef void* (fptr)(const char*, void*, size_t); 
void foo(void* (fptr1)(const char*, void*, size_t), void* (*fptr2)(const char*, int, size_t)){}
void foo2(fptr f1, fptr f2);



void f_0(int ival) {
	printf("1 cagirildi x=%d\n",ival);
}
void f_1(int ival) {
	printf("2 cagirildi x=%d\n",ival);
}
void f_2(int ival) {
	printf("3 cagirildi x=%d\n",ival);
}

typedef void(*fptr_1)(int);


//oyun algoritmas�

void sleep() {
	printf("uyuyorum la\n");
}
void run() {
	printf("Bu y�zden her gece ben her gece uzulmusum\n");
}
void eat() {
	printf("loooop loooop loooop\n");
}
typedef void(*warriorfptr)(void);


//�rnek fonksiyonlar tutorialspoint
int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);//k���kten b�y��e s�ralar, tersi olursa b�y�kten k����e s�ralar
}

//qsort examples
typedef struct Student {
	char name[15];
	char surname[20];
	int no;
}Student;

#define ASIZE 5
int cmp(const void* vp1, const void* vp2) {
	const Student* p1 = (const Student*)vp1;
	const Student* p2 = (const Student*)vp2;
	return (p1->no - p2->no);// nolar� kar��la�t�r�r
	//return strcmp(p1->name,p1->name)//isimleri kar��la�t�r�r
}

int main() {
	//function ponters(i�lev g�stericileri)
	//fonksiyonlar�n adresini tutan pointerlara function pointer denir

	//pointerlar ikiye ayr�l�r
	//-object pointer (nesnelerin, de�i�kenlerin adresini tutuyor)
	//-function pointers(fonksiyonlar�n adresini tutuyor)

	int x = 10;
	&x;
	&sum;//sum fonksiyonunun adresi

	int (*fptr)(int, int) = &sum;//function pointer
	printf("sum fonksiyonunun adresi:\n");
	printf("%p     %p \n", fptr, &sum);//ilkisi ayn� adersi tutuyor

	//function to pointer conversion
	int (*pptr)(int, int) = sum;//function to pointer convertion
	//& koymakla koymamak aras�nd pek fark kalmad�:)

	printf("%p %p %p \n", fptr, &sum, pptr);//��� de ayn� adersi tutuyor
	st();
	//fonksiyon ca�r� operat�r� ()
	//bu operat�r�n operand� bir fonksiyon adresi olmal�
	sum(2, 3);//olabilir
	(&sum)(2, 3);//operat�r onceli�inden dolay� parantez ile bu �ekilde kullanabiliriz

	printf("&malloc = %p\n", malloc);
	printf("&printf = %p\n", printf);

	st();

	///standart onksiyon adreslerini tutma

	//malloc()//void* malloc(size_t size)
	//strcmp()//int strcmp(const char* c1,const char*c2)
	printf("strcmp adres ve pointer\n");
	int(*fptr1)(const char*, const char*) = &strcmp;
	printf("fonksiyon adresi=%p\nfunction pointer degeri=%p\n", &strcmp, fptr1);//strcmp adresi,i ve function pointeri
	st();
	printf("malloc adres ve pointer\n");
	int(*fptr2)(size_t) = &malloc;
	printf("fonksiyon adresi=%p\nfunction pointer degeri=%p\n", &malloc, fptr2);//malloc adresi,i ve function pointeri

	st();

	void (*fp)() = &f1;
	fp();//f1 fonksiyonu �al���r
	fp = f2_;//f2nin adresi fpye ge�ti
	fp();//f2 fonksiyonu �al���r
	fp = f3;//f2nin adresi fpye ge�ti
	fp();//f3 fonksiyonu �al���r
	st();

	st();

	func(f1);//giri�teki funtion pointere a de�er ge�tik

	st();

	//void (*f_ptr)(fptr, fptr) = &foo;

	fptr_1 fpa[3] = { &f_0,&f_1,&f_2 };//fonksiyon adreslerini tutan bir dizi
	//function pointer array
	//jump table
	 
	for (int i = 0; i < 3; ++i)
		fpa[i](i);
	st();

	//jump table kullan�m�
	warriorfptr fpa1[3] = { &sleep,&run,&eat };
	randoms();
	while (1){
		fpa1[rand() % 3]();
		getchar();
	}

	st();

	//qsort function tutorialspoint example

	int n;

	printf("Before sorting the list is: \n");
	

	qsort(values, 5, sizeof(int), cmpfunc);

	printf("\nAfter sorting the list is: \n");
	displayArray(values, 5);

	st();
	//qsort examples

	Student MathNote[ASIZE] = { {"Tugce","Yildiz",89,},
						   {"Abdullah","Kahraman",72},
						   {"Kemal","Sener",16},
						   {"Merve","Aky�z",55},
						   {"Zeynep","Uncu",15} };
	qsort(MathNote, ASIZE, sizeof(Student), cmp);

	for (int i = 0; i < ASIZE; ++i)	{
		printf("%s %s %d\n", MathNote[i].name, MathNote[i].surname, MathNote[i].no);
	}

}


