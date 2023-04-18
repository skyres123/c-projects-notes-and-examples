#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include <time.h>

#define SIZE 5000


void bubbleSort(int a[], int n);

void func() {
	int y = 10;//otomatik ömürlü deðiþken fonksiyon çaðýrýldýðýnda
				//oluþur fonksiyonun iþi bitince ömrünü tamamlar

	static int z = 15;//bir defa oluþturulur program sonlananakadar ömrü devam eder
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
	//auto keyword: c de kullanýmý yok c++ da kullanýlýyor
	//auto x = 25.3;//tür tanýma iþlemi yapýyor





	//volatile keyword
	/*
	deðiþken deðiþimi


	senkron deðiþiklikler(program içi deðiþiklikler )
	asenkron deðiþiklikler(program dýþý deðiþiklikler)
	*/
	//senkron deðiþiklikler
	int x = 25;
	++x;
	x += 30;
	scanf("%d", &x);

	//deðiþken program dýþý kaynaklardan deðiþtirilebilecek bir deðiþken ise volatile keyword kullanýlýr
	//deðiþkenler normalde ramden okunur
	//derleyici optimizasyon yaparsa iþlemcinin registerlerýna kaydedilebilir
	//volatile keyword bu optimizasyonu o deðiþken için engeller

	volatile int x1 = 10;//bu deðiþken program dýþý kaynaklar tarafýndan deðiþtirilebilir
	//bunu sakýn optimize etme hep ramden oku


//static keyword
	func();
	func();
	func();
	func();

	st();

	for (int i = 0; i < 10; ++i){
		f1();//deðiþkenler deðiþmeyecekse static ömürlü olarak kullanýlabilir
	}
	st();

	//baðlantý(linkage) kavramý
	//bir varlýðýn diðer modüllertarafýndan ismiyle kullanýlabilmesi
	//ya da kullanýlamamasý özelliðine baðlantý(linkage) denir.
	/*
	internal linkage iç baðlantý bir varlýk iç modüller tarafýndan kullanýlacaksa
								   //buna iç baðlantý denir.

	external linkadge dýþ baðlantý bir varlýk dýþ modüller tarafýndan kullanýlacaksa 
								   //buna dýþ baðlantý denir.
	*/

	//static keyword kullanýldýðýnda fonksiyonlar internal linkage olur,
	//baþka modüllerden kullanýlamaz hale gelir
	// 
	//modül -> utility.h ve utility.c     baþka modül main.c  client code -> main.c

	
	//++ival;
	//bir global deðiþken kullanýlsýn istemiyorsak .h dosyasýnda tanýmlamamalýyýz
	// static keywordü ile .h dosyasýnda deðiþken tanýmlarsak dýþ baðlantýya açýlýr

	//extern keywordu baþka bir modül(baþka isimli bir.c dosyasý ) içindeki deðiþkeni kullanýma açar
	extern int defin;
	

	//linker çokluktan ya da yokluktan hata veriri

	//fonksiyon tanýmý bulunup deklare ediliþi bulunamazsa
	//f1();
	//fonksiyon iki defa tanýmlanmýþsa
	//f2();

	//time.h

	//01.01.1970  00.00.00 bunun üzerinden geçen saniye sayýsý 
	//01.01.1970  00.01.20 gecen 80 saniye
	//saklayabileceðimiz veri tipi time_t

	printf("sizeof(time.h)=%zu", sizeof(time_t));
	//8 byte yer kaplar
	st();
	//time.h tutorialspointden incelendi

	//time_t timer,seconds;
	//seconds=time(&timer);
	//printf("saniye = %lld saniye = %lld\n", seconds,seconds);
	//epokdan geçen saniyeler
	//giriþ deðeri de geri dönüþ deðeri de aynýdýr


	//struct tm* p1 = localtime(&timer);
	//struct tm* p2 = localtime(&timer);
	//struct tm* p3 = localtime(&timer);

	//printf("%p\n", p1);
	//printf("%p\n", p2);
	//printf("%p\n", p3);
	//localtime fonksiyonu static ömürlü deðiþkene dönüyor

	//öyle bir c kodu yazýn ki o anki saat bilgisini yazsýn
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

	printf("Sýralama baþlýyor");
	clock_t c_start = clock();//baþlama zamaný
	bubbleSort(p, SIZE);
	clock_t c_end = clock();//bitiþ zamaný
	displayArray(p, SIZE);
	printf("tick count : %ld",c_end - c_start);//buble sort kodunun ne kadar zaman çalýþtýðýný öðreniyoruz
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