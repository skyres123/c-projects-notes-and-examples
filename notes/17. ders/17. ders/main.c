#define _CRT_SECURE_NO_WARNINGS
#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>//typedef bildirimi yap�lm�� veri tipleri buradad�r
#include "utility.h"

int main(int argc,char** argv) {

	int x0 =15 ;
	bp(x0);
	bp(~x0);//bitwise not
	bp(~x0);//kendisi
	bp(!x0);//logical not

	st();

	//bitsel kayd�rma opet�rleri

	//<<(left shift operator)				>>(Right shift operator)
	

	// op1<<op2   i�lem op1 e yap�l�r
	//ival<<2   
	//<<(left shift operator)
	uint8_t num = 255;
	unsigned char cval = 255;
	
	bp(num);
	bp(num << 2);//say�n�n en sa��na 2 adet 0 eklendi en ba��ndaki 1 ise kayboldu


	st();
	//atamal� operat�rler
	bp(num);//�nceki hal
	num = num << 2;
	//num <<= 2 bu �ekilde de olabilirdi
	bp(num);//sonraki hal
	//say�n�n en sa��na 2 adet 0 eklendi en ba��ndaki 2 bit ise kayboldu

	st();

	unsigned int uval = 1;
	while (uval){
		printf("%u\n", uval);
		uval <<= 1;//2 nin kuvvetlerini yazd�rd�
		/*
		00000000000000000000000000000001=1
		00000000000000000000000000000010=2
		00000000000000000000000000000100=4
		00000000000000000000000000001000=8
		00000000000000000000000000010000=16
		00000000000000000000000000100000=32
		00000000000000000000000001000000=64
		00000000000000000000000010000000=128
		.
		.
		.
		10000000000000000000000000000000
		*/
	}

	st();
	//>>(right shift operator)
	
	// op1>>op2   i�lem op2 ye yap�l�r
	//sa�dan bitler ��kar besleme soldan yap�l�r
	unsigned int uval2 = 255;
	while (uval2) {
		printf("%u\n", uval2);
		uval2 >>= 1;
	}

	//bitwise & (and) operator

	/*
	1 0=0
	0 1=0
	1 1=1
	0 0=0
	*/
	int x, y;
	printf("iki tam say� giriniz");
	scanf("%d, %d", &x, &y);
	bp(x);
	bp(y);
	bp(x & y);
	//x=	011011
	//y=    100011
	//res   11 olmal�
	st();

	//bitwise | (or) operator

		/*
	1 0=1
	0 1=1
	1 1=1
	0 0=0
	*/
	int i, j;
	printf("iki tam say� giriniz");
	scanf("%d, %d", &i, &j);
	bp(i);
	bp(j);
	bp(i | j);
	st();
	//x=	011011
	//y=    100011
	//res   111011 olmal�
	bp(i);
	bp(j);
	//i ve j de�i�mez


	i |= j;
	//i ve j veya islemine girer sonu� i ye atan�r
	bp(i);
	bp(j);
	st();

	//xor Operator  ^
	//oprandlar sonu� 1 
	//ayn� ise sonu� 0
	/*
	1 0=1
	0 1=1
	1 1=0
	0 0=0
	*/

	int i1, j1;
	printf("iki tam say� giriniz");
	scanf("%d, %d", &i1, &j1);
	bp(i1);
	bp(j1);
	bp(i1^j1);
	st();
	//i1=	011011
	//j1=   100011
	//res   111000 olmal�

	//Bitsel i�lemlerde yap�lan 4 tipik senaryo

	/*
	1. bir tam say�n�n belirli bir bitini birlemek
	2. bir tam say�n�n belirli bir bitini s�f�rlamal
	3- bir tam say�n�n belirli bir bitini de�i�tirmek
	4- bir tam say�n�n belirli bir bitini ��renmek 
	*/

	//1. bir tam say�n�n belirli bir bitini birlemek(set etmek)
	//1011 1011 0000 0110   4�nc� biti nas�l set edilir
	// 
	// 
	//1011 1011 000? 0110 
	//0000 0000 0001 0000 bitsel maske

	//bu bitsel maske ile say�y� veya i�lemine sokarsak 
	//4 �nc� biti set etmi� oluruz

	//x |= (1<<n) bu i�lem ile bir tam say�n�n belirli bir bitini birlemi� oluruz

	unsigned char x1 = 128;
	bp(x1);
	x1 |= (1 << 3);
	bp(x1);//3. bit birlendi
	st();

	//2. bir tam say�n�n belirli bir bitini s�f�rlama(clear etmek)
	//1011 1011 0001 0110   4�nc� biti nas�l clear edilir
	// 
	// 
	//1011 1011 000? 0110 
	//1111 1111 1110 1111 bitsel maske
	//bu bitsel maskeyi ~(1<<4) �eklinde g�sterebiliriz

	//bu bitsel maske ile say�y� ve i�lemine sokarsak 
	//4 �nc� biti clear etmi� oluruz

	//x &= ~(1<<n) bu i�lem ile bir tam say�n�n belirli bir bitini s�f�rlam�� oluruz

	unsigned char x2 = 105;
	bp(x2);
	x2 &= ~(1 << 3);
	bp(x2);//3. bit s�f�rland�
	st();

	//3 - bir tam say�n�n belirli bir bitini de�i�tirmek(Toggle etmek)
	//1011 1011 0001 0110   4�nc� biti nas�l de�i�tirilir
	//0000 0000 0001 0000 bitsel maske 
	//1011 1011 0000 0110 
	//bu (1<<4) bitsel maske ile say�y� xor i�lemine sokarsak 
	//4 �nc� biti toggle etmi� oluruz
	//x ^= (1<<n)

	unsigned char x3 = 107;
	bp(x3);
	x3 ^= (1 << 3);
	bp(x3);//3. bit toggle edildi
	st();

	//4- bir tam say�n�n belirli bir bitini ��renmek(get etmek)
	//1011 1011 0001 0110   4�nc� biti nas�l ��renilir
	//0000 0000 0001 0000 bitsel maske 
	
	//bu (1<<4) bitsel maske ile say�y� ve i�lemine sokarsak 
	//4 �nc� biti get etmi� oluruz
	//x & (1<<n)

	unsigned char x4 = 107;
	unsigned int y1;
	bp(x4);
	printf("kacinci bit");
	scanf("%u", &y1);
	unsigned int res = x4 & (1 << y1);//get etme i�lemi

	if (res)
		printf("ilgili bit 1 mis");
	else
		printf("ilgili bit 0 mis");

	//bitfield member
	//bir tm say�n�n bit alanlar�n� kullnan bellek modeli

	typedef struct Data {
		int a : 3;//derleyicide 3 bitlik yer ayr�ld�
		int b : 2;//derleyicide 2 bitlik yer ayr�ld�
		int c;
	}Data;

	Data mydata;
	Data* ptr = &mydata;

	ptr->a = 2;

	typedef struct Data2 {
		int a1 : 2;
		int a2 : 3;
		int a3 : 1;
		int a4 : 4;
		int a5 : 5;
		int a6 : 6;
	}Data2;
	Data2 mydata2;
	mydata2.a1 = 3;
	mydata2.a2 = 10;
	mydata2.a3 = 16;

	printf("x1=%d x2=%d x3=%d", mydata2.a1, mydata2.a2, mydata2.a3);
	st();
	Data2 mydata3 = { 2,1,1,5,12,25 };

	printf("x1=%d x2=%d x3=%d x4=%d x5=%d x6=%d", mydata2.a1, mydata2.a2, mydata2.a3, mydata2.a4, mydata2.a5, mydata2.a6);

	st();

	typedef struct DateTime {
		int mday : 5;//1 den 31 e kadar olan de�erleri tutabilirim
		int mmon : 4;//1 den 12 ye kadar olan de�erleri tutabilirim 
		int myear : 7;//1980 refetans al�nd�, g�sterilen de�er 1980e
		              //eklenerek y�l ifade edilecek
		int mhour : 5;//0 dan 23 kadar de�er tutabilirim
		int mmin  : 7;//0 dan 59 a kadar de�er tutabilirim
		int msec  : 7;//0 dan 59 a kadar de�er tutabilirim 
	}DateTime;

	printf("sizeof(DateTime) = %zu", sizeof(DateTime));
	st();
	DateTime datetime = { 31,7,20,13,35,59 };
	printf("%d %d %d %d %d %d", datetime.mday, datetime.mmon, datetime.myear, datetime.mhour, datetime.mmin, datetime.msec);
	st();

	//komut sat�r� arg�manlar�(command line arg�ments)

	/*
	argc : argument count
	arcv : argument vector
	*/
	/*
	printf("argc=%d\n", argc);
	for (int i = 0; i < argc; ++i)
		printf("argv[%d]=%s\n", i, argv[i]);
	*/
	st();

	//programadi.exe <op1> <operrator> <op2>


	//hesap makinesi
	if (argc != 4) {
		printf("programadi.exe <op1> <operrator> <op2>");
		exit(EXIT_FAILURE);
	}

	int op1 = atoi(argv[1]);
	int op2 = atoi(argv[3]);

	switch (*argv[2])
	{
	case '+':
		printf("sonuc = %d\n", op1 + op2);
		break;
	case '-':
		printf("sonuc = %d\n", op1 - op2);
		break;
	case '*':
		printf("sonuc = %d\n", op1 * op2);
		break;
	case '/':
		if (op2 == 0) {
			printf("s�f�r ile b�lme yap�lamaz");
			break;
		}
		else {
			printf("sonuc = %f\n", (double)op1 / op2);
			break;
		}
	default:
		printf("%c gecelrli bir i�lem de�il", *argv[2]);
		break;
	}




}