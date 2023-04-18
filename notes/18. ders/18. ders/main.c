#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include <time.h>

#define SIZE 5000


void bubbleSort(int a[], int n);

void func() {
	int y = 10;//otomatik �m�rl� de�i�ken fonksiyon �a��r�ld���nda
				//olu�ur fonksiyonun i�i bitince �mr�n� tamamlar

	static int z = 15;//bir defa olu�turulur program sonlananakadar �mr� devam eder
	y += 10;
	z += 10;
	printf("y=%d Z=%d\n", y, z);
}

void f1() {
	static const int primes[] = { 2, 3, 5,7,11,13,17,19,23,29,31,37 };
}
void displayCurrentDateTime() {
	static const char* const pmonths[] = { "January","February","March","April","May","June","July","Agust","September","October","November","December" };
	static const char* const pdays[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };


	time_t timer, seconds;
	seconds = time(&timer);
	struct tm* p1 = localtime(&timer);

	printf("%2d %s %d %s %2d:%2d:%2d", p1->tm_mday,pmonths[p1->tm_mon],1900+p1->tm_year,pdays[p1->tm_wday],p1->tm_hour,p1->tm_min,p1->tm_sec);
	 
}
int main() {
	//auto keyword: c de kullan�m� yok c++ da kullan�l�yor
	//auto x = 25.3;//t�r tan�ma i�lemi yap�yor





	//volatile keyword
	/*
	de�i�ken de�i�imi


	senkron de�i�iklikler(program i�i de�i�iklikler )
	asenkron de�i�iklikler(program d��� de�i�iklikler)
	*/
	//senkron de�i�iklikler
	int x = 25;
	++x;
	x += 30;
	scanf("%d", &x);

	//de�i�ken program d��� kaynaklardan de�i�tirilebilecek bir de�i�ken ise volatile keyword kullan�l�r
	//de�i�kenler normalde ramden okunur
	//derleyici optimizasyon yaparsa i�lemcinin registerler�na kaydedilebilir
	//volatile keyword bu optimizasyonu o de�i�ken i�in engeller

	volatile int x1 = 10;//bu de�i�ken program d��� kaynaklar taraf�ndan de�i�tirilebilir
	//bunu sak�n optimize etme hep ramden oku


//static keyword
	func();
	func();
	func();
	func();

	st();

	for (int i = 0; i < 10; ++i){
		f1();//de�i�kenler de�i�meyecekse static �m�rl� olarak kullan�labilir
	}
	st();

	//ba�lant�(linkage) kavram�
	//bir varl���n di�er mod�llertaraf�ndan ismiyle kullan�labilmesi
	//ya da kullan�lamamas� �zelli�ine ba�lant�(linkage) denir.
	/*
	internal linkage i� ba�lant� bir varl�k i� mod�ller taraf�ndan kullan�lacaksa
								   //buna i� ba�lant� denir.

	external linkadge d�� ba�lant� bir varl�k d�� mod�ller taraf�ndan kullan�lacaksa 
								   //buna d�� ba�lant� denir.
	*/

	//static keyword kullan�ld���nda fonksiyonlar internal linkage olur,
	//ba�ka mod�llerden kullan�lamaz hale gelir
	// 
	//mod�l -> utility.h ve utility.c     ba�ka mod�l main.c  client code -> main.c

	
	//++ival;
	//bir global de�i�ken kullan�ls�n istemiyorsak .h dosyas�nda tan�mlamamal�y�z
	// static keyword� ile .h dosyas�nda de�i�ken tan�mlarsak d�� ba�lant�ya a��l�r

	//extern keywordu ba�ka bir mod�l(ba�ka isimli bir.c dosyas� ) i�indeki de�i�keni kullan�ma a�ar
	extern int defin;
	

	//linker �okluktan ya da yokluktan hata veriri

	//fonksiyon tan�m� bulunup deklare edili�i bulunamazsa
	//f1();
	//fonksiyon iki defa tan�mlanm��sa
	//f2();

	//time.h

	//01.01.1970  00.00.00 bunun �zerinden ge�en saniye say�s� 
	//01.01.1970  00.01.20 gecen 80 saniye
	//saklayabilece�imiz veri tipi time_t

	printf("sizeof(time.h)=%zu", sizeof(time_t));
	//8 byte yer kaplar
	st();
	//time.h tutorialspointden incelendi

	//time_t timer,seconds;
	//seconds=time(&timer);
	//printf("saniye = %lld saniye = %lld\n", seconds,seconds);
	//epokdan ge�en saniyeler
	//giri� de�eri de geri d�n�� de�eri de ayn�d�r


	//struct tm* p1 = localtime(&timer);
	//struct tm* p2 = localtime(&timer);
	//struct tm* p3 = localtime(&timer);

	//printf("%p\n", p1);
	//printf("%p\n", p2);
	//printf("%p\n", p3);
	//localtime fonksiyonu static �m�rl� de�i�kene d�n�yor

	//�yle bir c kodu yaz�n ki o anki saat bilgisini yazs�n
	displayCurrentDateTime();

	time_t curtime;

	time(&curtime);

	printf("\nCurrent time = %s", ctime(&curtime));
	st();

	int* p = malloc(SIZE*sizeof(int));

	if (!p) {
		printf("bellek yetersiz");
		exit(EXIT_FAILURE);
	}
	setRandomArray(p, SIZE);

	printf("S�ralama ba�l�yor");
	clock_t c_start = clock();//ba�lama zaman�
	bubbleSort(p, SIZE);
	clock_t c_end = clock();//biti� zaman�
	displayArray(p, SIZE);
	printf("tick count : %ld",c_end - c_start);//buble sort kodunun ne kadar zaman �al��t���n� ��reniyoruz
	free(p);


	st();



}
void bubbleSort(int a[], int n)
{
	int i, j, temp; // for a={1,2,3,4,5} n is 5

	n = n - 1;    // bcz otherwise it will get out of index

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}

		}

	}

}