#define _CRT_SECURE_NO_WARNINGS
#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>//typedef bildirimi yapýlmýþ veri tipleri buradadýr
#include "utility.h"

int main(int argc,char** argv) {

	int x0 =15 ;
	bp(x0);
	bp(~x0);//bitwise not
	bp(~x0);//kendisi
	bp(!x0);//logical not

	st();

	//bitsel kaydýrma opetörleri

	//<<(left shift operator)				>>(Right shift operator)
	

	// op1<<op2   iþlem op1 e yapýlýr
	//ival<<2   
	//<<(left shift operator)
	uint8_t num = 255;
	unsigned char cval = 255;
	
	bp(num);
	bp(num << 2);//sayýnýn en saðýna 2 adet 0 eklendi en baþýndaki 1 ise kayboldu


	st();
	//atamalý operatörler
	bp(num);//önceki hal
	num = num << 2;
	//num <<= 2 bu þekilde de olabilirdi
	bp(num);//sonraki hal
	//sayýnýn en saðýna 2 adet 0 eklendi en baþýndaki 2 bit ise kayboldu

	st();

	unsigned int uval = 1;
	while (uval){
		printf("%u\n", uval);
		uval <<= 1;//2 nin kuvvetlerini yazdýrdý
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
	
	// op1>>op2   iþlem op2 ye yapýlýr
	//saðdan bitler çýkar besleme soldan yapýlýr
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
	printf("iki tam sayý giriniz");
	scanf("%d, %d", &x, &y);
	bp(x);
	bp(y);
	bp(x & y);
	//x=	011011
	//y=    100011
	//res   11 olmalý
	st();

	//bitwise | (or) operator

		/*
	1 0=1
	0 1=1
	1 1=1
	0 0=0
	*/
	int i, j;
	printf("iki tam sayý giriniz");
	scanf("%d, %d", &i, &j);
	bp(i);
	bp(j);
	bp(i | j);
	st();
	//x=	011011
	//y=    100011
	//res   111011 olmalý
	bp(i);
	bp(j);
	//i ve j deðiþmez


	i |= j;
	//i ve j veya islemine girer sonuç i ye atanýr
	bp(i);
	bp(j);
	st();

	//xor Operator  ^
	//oprandlar sonuç 1 
	//ayný ise sonuç 0
	/*
	1 0=1
	0 1=1
	1 1=0
	0 0=0
	*/

	int i1, j1;
	printf("iki tam sayý giriniz");
	scanf("%d, %d", &i1, &j1);
	bp(i1);
	bp(j1);
	bp(i1^j1);
	st();
	//i1=	011011
	//j1=   100011
	//res   111000 olmalý

	//Bitsel iþlemlerde yapýlan 4 tipik senaryo

	/*
	1. bir tam sayýnýn belirli bir bitini birlemek
	2. bir tam sayýnýn belirli bir bitini sýfýrlamal
	3- bir tam sayýnýn belirli bir bitini deðiþtirmek
	4- bir tam sayýnýn belirli bir bitini öðrenmek 
	*/

	//1. bir tam sayýnýn belirli bir bitini birlemek(set etmek)
	//1011 1011 0000 0110   4üncü biti nasýl set edilir
	// 
	// 
	//1011 1011 000? 0110 
	//0000 0000 0001 0000 bitsel maske

	//bu bitsel maske ile sayýyý veya iþlemine sokarsak 
	//4 üncü biti set etmiþ oluruz

	//x |= (1<<n) bu iþlem ile bir tam sayýnýn belirli bir bitini birlemiþ oluruz

	unsigned char x1 = 128;
	bp(x1);
	x1 |= (1 << 3);
	bp(x1);//3. bit birlendi
	st();

	//2. bir tam sayýnýn belirli bir bitini sýfýrlama(clear etmek)
	//1011 1011 0001 0110   4üncü biti nasýl clear edilir
	// 
	// 
	//1011 1011 000? 0110 
	//1111 1111 1110 1111 bitsel maske
	//bu bitsel maskeyi ~(1<<4) þeklinde gösterebiliriz

	//bu bitsel maske ile sayýyý ve iþlemine sokarsak 
	//4 üncü biti clear etmiþ oluruz

	//x &= ~(1<<n) bu iþlem ile bir tam sayýnýn belirli bir bitini sýfýrlamýþ oluruz

	unsigned char x2 = 105;
	bp(x2);
	x2 &= ~(1 << 3);
	bp(x2);//3. bit sýfýrlandý
	st();

	//3 - bir tam sayýnýn belirli bir bitini deðiþtirmek(Toggle etmek)
	//1011 1011 0001 0110   4üncü biti nasýl deðiþtirilir
	//0000 0000 0001 0000 bitsel maske 
	//1011 1011 0000 0110 
	//bu (1<<4) bitsel maske ile sayýyý xor iþlemine sokarsak 
	//4 üncü biti toggle etmiþ oluruz
	//x ^= (1<<n)

	unsigned char x3 = 107;
	bp(x3);
	x3 ^= (1 << 3);
	bp(x3);//3. bit toggle edildi
	st();

	//4- bir tam sayýnýn belirli bir bitini öðrenmek(get etmek)
	//1011 1011 0001 0110   4üncü biti nasýl öðrenilir
	//0000 0000 0001 0000 bitsel maske 
	
	//bu (1<<4) bitsel maske ile sayýyý ve iþlemine sokarsak 
	//4 üncü biti get etmiþ oluruz
	//x & (1<<n)

	unsigned char x4 = 107;
	unsigned int y1;
	bp(x4);
	printf("kacinci bit");
	scanf("%u", &y1);
	unsigned int res = x4 & (1 << y1);//get etme iþlemi

	if (res)
		printf("ilgili bit 1 mis");
	else
		printf("ilgili bit 0 mis");

	//bitfield member
	//bir tm sayýnýn bit alanlarýný kullnan bellek modeli

	typedef struct Data {
		int a : 3;//derleyicide 3 bitlik yer ayrýldý
		int b : 2;//derleyicide 2 bitlik yer ayrýldý
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
		int mday : 5;//1 den 31 e kadar olan deðerleri tutabilirim
		int mmon : 4;//1 den 12 ye kadar olan deðerleri tutabilirim 
		int myear : 7;//1980 refetans alýndý, gösterilen deðer 1980e
		              //eklenerek yýl ifade edilecek
		int mhour : 5;//0 dan 23 kadar deðer tutabilirim
		int mmin  : 7;//0 dan 59 a kadar deðer tutabilirim
		int msec  : 7;//0 dan 59 a kadar deðer tutabilirim 
	}DateTime;

	printf("sizeof(DateTime) = %zu", sizeof(DateTime));
	st();
	DateTime datetime = { 31,7,20,13,35,59 };
	printf("%d %d %d %d %d %d", datetime.mday, datetime.mmon, datetime.myear, datetime.mhour, datetime.mmin, datetime.msec);
	st();

	//komut satýrý argümanlarý(command line argüments)

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
			printf("sýfýr ile bölme yapýlamaz");
			break;
		}
		else {
			printf("sonuc = %f\n", (double)op1 / op2);
			break;
		}
	default:
		printf("%c gecelrli bir iþlem deðil", *argv[2]);
		break;
	}




}