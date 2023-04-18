#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "utility.h"
#pragma pack(1)
typedef struct CoplexNumber {

	double real;
	double ing;
}ComplexNumber;

void checked_malloc(size_t n) {
	void* vp = malloc(n);
	if (vp == NULL) {
		printf("bellek yetersiz");
		exit(EXIT_FAILURE);
	}
	return vp;
}
typedef struct Data {
	int x; int y;
}Data;
struct Data foo(struct Data x, const struct Data y);
void f1(struct Data x);//call by value
void f2(struct Data* x);//call by reference (veri 8 byte ge�iyorsa daha fazla kullan�l�r )
void f3(const struct Data* x);//struct data x giri� olarak ayarlanm��t�r, sadece salt okunurdur
Data f4();
Data* f5();//data cinsinden adrese d�nen fonksiyon
//adrese d�nen fonksiyonlar otomatik �m�rl� olmamal�d�r


ComplexNumber addComplexNumber(const ComplexNumber* n1, const ComplexNumber* n2) {
	ComplexNumber res;
	res.real = n1->real + n2->real;
	res.ing = n1->ing + n2->ing;

	return res;
}//fonksiyon tan�mlad�k a�a��da �a��raca��z, call by referance kullan�ld�

void displayComplexNumber(const ComplexNumber n) {
	printf("\n%f+%f*i\n", n.real, n.ing);
}

typedef struct Birthday {
	int d;
	int m;
	int y;
}Birthday;

struct Worker{//Composition Structure (Bile�ik yap�lar)
	char Name[15];
	char Surname[20];
	int regist_number;
	Birthday birth;
}Worker;

int main() {

	//10 tane int dizinin adresini tutacak bir dizi dinamik olarak olu�turun

	int** pd = (int**)malloc(10 * sizeof(int*));
	free(pd);
	//realloc: dinamik bellek blo�unu b�y�tmek yada k���ltmeye yarar
	size_t n;
	size_t nplus;
	printf("kac tam sayi");
	scanf("%zu", &n);

	int* pd2 = (int*)malloc(n * sizeof(int));
	if(!pd2){
		printf("bellek yetersiz");
		exit(EXIT_FAILURE);
	}

	setRandomArray(pd2, n);
	displayArray(pd2, n);
	printf("realloc= %p=\n", pd2);
	st();

	printf("kac tam say� daha eklensin");
	scanf("%zu", &nplus);

	pd2 = (int*)realloc(pd2, (n + nplus) * sizeof(int));//eleman say�s�n�n toplam� + bir eleman�n sizeofu 
	if (!pd2) {
		printf("bellek yetersiz");
		exit(EXIT_FAILURE);
	}
	setRandomArray(pd2 + n, nplus);
	displayArray(pd2, n + nplus);
	printf("realloc= %p=\n", pd2);
	
	free(pd2);

	//user defined types
	//structers union,enumarations
	/*
	* struct struct_tag{
	
	
	}
	*/
	typedef struct Data {
		int x;	//data members
		int a[4];//
		double y,z;//
	}Data;

	struct Data mydata;
	printf("sizeof(struct Data)=%zu\n", sizeof(struct Data));

	//struct Data* pt = (struct Data*)mallloc(sizeof(struct Data));//structre cinsinden dinamik �m�rl� de�i�kenler i�in malloc ile yer al�nabilir

	Data a[20];//typedef bildirimi yaparak structurelerdeki structure s�zc���nden kurtulabiliriz

	//yap� t�r�nden nesnelerin ��elerine eri�im

	//. oprat�r�      
	Data mydata1,mydata2;
	mydata1.x = 30;
	mydata1.y = 20;
	mydata1.z = 40;
	mydata1.a[0] = 100;

	printf("x=%d, y=%.2f, z=%.2f, a[0]=%d", mydata1.x, mydata1.y, mydata1.z, mydata1.a[0]);

	st();

	//-> operat�r�
	mydata1.x = 30;
	mydata1.y = 20;
	mydata1.z = 40;

	mydata2.x = 100;
	mydata2.y = 200;
	mydata2.z = 300;

	 const Data* pdata = &mydata1; 

	printf("x=%d y=%f z=%f", pdata->x, pdata->y, pdata->z);
	st();
	//yap� nesnelerine ilk de�er verilmesi

	typedef struct data {
		int x;	//data members
		int a[3];
		char name[20];
		char surname[30];
		double wage;
		int y, z;//
	}data;

	data mydata3 = { 60,{70,80,90},"mehmet","sen",68.3,100,110};//ilk de�er verdik(initialize)

	data* pData = &mydata3;
	displayArray(mydata3.a, 3);//diziyi yazd�rd�k
	printf("x=%d y=%d z=%d, name=%s, surname=%s, weight = %.2f", pData->x, pData->y, pData->z,pData->name,pData->surname,pData->wage);//kalan elemanlar� yazd�rd�k
	//structurelarda farkl� tiplerde memberlar olabilir
/*
	typedef struct CoplexNumber {
		
		double real;
		double ing;
	}ComplexNumber;
*/
	typedef struct CoplexNumber_ {//farkl� bir structure

		double real;
		double ing;
	}ComplexNumber_;

	ComplexNumber n1 = { 1,2.3 };//structure cinsinden bir nesne
	ComplexNumber n2 = { 5,3.4 };//structure cinsinden bir nesne

	ComplexNumber* cptr = &n1;//struct cinsinden pointer

	ComplexNumber_ d1 = { 100,200 };
	(*cptr).real = 30;//Bu ikili kod tamamen ayn�d�r;
	cptr->real = 30;//
	printf("before ......................real=%f, ing= %f", n1.real, n1.ing);
	st();
	n1 = n2;
	printf("after ......................real=%f, ing= %f", n1.real, n1.ing);

	//n1=d1 yap�lamaz, Birbirinden farkli structure nesneleri birbiirne atanamaz
	//memcpy(&n1,&d1) ile yap�labilir

	ComplexNumber* pdate =  (ComplexNumber* )malloc(sizeof(ComplexNumber));
	pdate->real = 20;
	pdate->ing = 30;
	//dinamik structure nesnesi olu�turduk
	free(pdate);
	//ve free ettik
	st();

	struct {
		int Day;
		int Mon;
		int Year;
	}Date;
	
	//structure tag olmaz ise Date haricinde ba�ka bir nesne olu�turulamaz

	st();

	//f1(mydata);//cal by value fonksiyon �a��rma
	//f2(&mydata);//cal by referance fonksiyon �a��rma

	ComplexNumber n3 = { 3,5 };
	ComplexNumber n4 = { 7,10 };

	ComplexNumber res = addComplexNumber(&n3, &n4);

	printf("Cikan Sonucun reel kismi %f, sanal kismi ise %f", res.real, res.ing);//sonucu yazd�r�yoruz
	displayComplexNumber(res);//karma��k say�y� i'li formda yazma fonsiyonunu yukar�da yazd�k burada �a��rd�k
	st();

	printf("sizeof birthday %d\n", sizeof(Birthday));
	printf("sizeof Workers %d\n", sizeof(struct Worker));
	struct Worker w1 = { "Hasan","Yilmaz",120,{18,12,1997} };//initializing composite structure
	
	st();

	//Allignment (Hizalama)
	typedef struct Data_ {
		char c1;
		int ival;
		char c2;
	}Data_;

	printf("sizeof(data) = %zu\n", sizeof(Data_));
	//pragma pack(1) varken 6byte
				//   yokken 12byte

	//yap� nesnesinin ��elerini 4 ve katlar� olarak yerle�tirir 

	Data_ Data1;
	printf("Data1 adres= %p\n", &Data1);
	printf("c1 adres= %p\n", &(Data1.c1));
	printf("ival adres= %p\n", &(Data1.ival));
	printf("c2 adres= %p\n", &(Data1.c2));

	//pragma pack varken b�t�n ��eler kendi boyutlar� kadar yer tutar
	//pragma pack yok iken b�t�n ��eler 4 ve 4�n katlar� olacak �ekilde yer tutar(padding)
	//alignment nesneleri pragma pack kullan�lmad���nda kullan�lmayan byte ler olu�ur

	//struct adresi ile ilk ��enin adresi birdir

	struct address {
		char name[50];
		char street[50];
		int phone;
	};

	printf("name offset = %d byte in address structure.\n",
		offsetof(struct address, name));

	printf("street offset = %d byte in address structure.\n",
		offsetof(struct address, street));

	printf("phone offset = %d byte in address structure.\n",
		offsetof(struct address, phone));

	//offset bir yeri referens alarak kat edilen uzakl�k

	//Alignment yap�lan hata!!!!!!!!!!!!!!!!!!!
	Data_ d1_;
	Data_ d2_;
	memset(&d1_, 0, sizeof(d1_));
	memset(&d2_, 0, sizeof(d2_));
	d1_ = { 'A',456,'K' };
	d2_ = { 'A',456,'K' };

	if (memcmp(&d1_, &d2_, sizeof(d1_))==0)
		printf("esit");
	else
		printf("esit degil");








}	
