#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include "utility.h"
#include <string.h>


//string k�t�phanesi
void st() {
	printf("\n==============================================================\n");
}
void myputs(const char* str) {
	while (*str != '\0')//null karakteri olmad�k�a devam et
		putchar(*str++);
	putchar("\n");
}
void revputs(const char* p) {
	size_t size = strlen(p);//uzunluk bulduk

	p += size;

	while (size--){
		putchar(*--p);
	}
	putchar("\n");
}

size_t mystrlen(const char* str) {
	int i;
	for ( i = 0; str[i] != '\0'; ++i);// str[i] null olmad�k�a devam et
	return i;
}
size_t mystrlen2(const char* str) {
	size_t size;
	while (*str != "\0")//pointer�n deperi null olmad�k�a devam et
		++size, str++;
	return size;
}
char* mystrchr(const char* p, int ch) {
	while (*p != '\0') {
		if (*p == ch)
			return (char*)p;
		++p;
	}
	return NULL;
}
char* mystrcat(char* p1, const char* p2) {
	strcpy(p1 + strlen(p1) , p2);
	return p1;
}
int main() {
	//strxyz tarz�nda fonksiyonlar
	//f1(char* str)   f2(const char* str)

	//const :  de�i�ken �zerinde de�i�iklik yap�lamaz

	//strlen, strchr, strcmp, strcat, stricmp, strpbrk, strtok ....

	char str[30] = "mehmet berat sen";

	printf(str);
	st();
	puts(str);
	st();
	myputs(str);
	st();
	revputs(str);//tersten yazd�rma

	//strlen(); string uzunlu�unu verir

	char str1[] = "Memolililililil";

	size_t size = strlen(str1);
	printf("%zu", size);//size_t  -----> %zu 

	size_t SIZE = mystrlen(str1);
	printf("Sizeof(str):� %d \n", SIZE);
	st();

	//strchr(const char* p, int ival)
	//strchr: string i�inde  string arar, bulamazsa null pointer d�ner


	char str2[40] = "Mehmet Berat �EN";
	/*	printf("Aranacak karakteri giriniz");
	int ch = getchar();
	char * ptr= strchr(str2, ch);//0 d�ner ise bulamad�, 0 dan farkl� de�er d�ner ise bulmu�tur
	if (ptr) 
		printf("Aranan karakter bulundu indexi = %d", ptr - str2);//geri d�n�� de�erinden ba�lang�� adresini ��kar�rsak indexe ula��r�z
	else
		printf("Karakter Bulunamadi");
	st();
	*/

	printf("Aranacak karakteri giriniz");
	int ch1 = getchar();
	char* ptr2 = str2;
	while (ptr2 != NULL) {
		int i = 0;
		ptr2 = strchr(str2 + i, ch1);
		if (ptr2) {
			*ptr2 = '*';
			i = ptr2 - str2;
		}
	}

	puts(str2);

	st();

	//strrchr(): sondan ba�layarak stringi arar

	//strcpy() stringi kaynaktan hedefer kopyalar

	char str3[20] = "Komiser Memoli";

	char str_name[20];

	char* new_name = strcpy(str_name, str3);//hedef adrese d�ner
	puts(str_name);
	puts(str3);

	printf("%p\n", str_name );//iki adres ayn�
	printf("%p\n", new_name);//
	st();

	char name[10] = "Mehmet";
	char surname[10] = "SEN";

	char full_name[30];
	strcpy(strcpy(full_name, name)+strlen(name), surname);//i�teki strcpy namedeki stringi full name ye d��taki ise surname yi nameden sonras�na kopyalamak i�in fullnamenin adresine namenin uzunlu�unu ekledik 
	printf("%s", full_name);
	st();
	
	char str4[20] = "Memoli";
	//strcpy(str4 + 2, str4);//source ve destination aras�nda kesi�im varsa strcpy yerine memmove fonksiyonu kullan�l�r
	memmove(str4 + 2, str4, strlen(str4) + 1);
	puts(str4);
	st();

	//strcat() bir yaz�n�n sonunaba�ka bir yaz�y� ekler
	/*	
	char name[10] = "Mehmet";
	char surname[10] = "SEN";
	*/
	strcat(name, surname);
	puts(name);
	st();

	//strcmp() iki yaz�y� kar��la�t�r�r
	//geri d�n�� de�eri >0 1. yaz� b�y�k
	//geri d�n�� de�eri <0 1. yaz� k�c�k
	//geri d�n�� degeri 0 ise yaz�lar ayn�==> daha �ok bununla ilgiliyiz

	//ascii karakter tablosuna g�re kar��la�t�r�r

	char s1[100];
	char s2[100];
	printf("�ki yaz� giriniz");
	scanf("%s %s", &s1, &s2);

	int res =  strcmp(s1,s2);//stricmp b�y�k k���k harf kar��la�t�rmas�n� durdurur

	if (!res)
		printf("Bunlar ayni yazi");
	else
		printf("Bu yazilar farkli");

	st();
	

	//strstr() yaz� i�inde yaz� arar

	char s3[100] = "Can�m koydun yoluna s�k bir kur�un asena";
	char s4[100];

	printf("Aranacak yaziyi giriniz");
	scanf("%s", &s4);
	

	int res2 = strstr(s3, s4);//s4 yzisini s4 yazisinin i�inde aradik

	if (res2!=NULL)
		printf("Aranan yazi bulundu");
	else
		printf("Aranan yazi bulunamadi");

	st();

	//string literals
	//"" i�inde yazd���mz ifadeler string literalidir
	//string literali char dizisi olu�ur ve o dizinin adresi tutulur
	//string literali de�i�tirilemez

	printf("%c", *"mehmet");//mehmet string litesalinin adresi tutulur ekrana ilk harf olan m yaz�l�r

	st();

	printf("%zu", strlen("mehmet"));//uzunlu�u yazd�rd�k

	st();

	const char* p = "Mehmet";//string literaller const dizilerdir const hep kullan�lmal�d�r
	//yaz�n�n tutuldu�u dizinin adresiyle p pointeri�na ilk de�er verildi

	char str5[] = "mehmet";//string literali de�il adres belirtmiyor

	char* p1 = "memolililili";//string literalleri de�i�mez

	puts(p1);

	//strcpy(p1, "memeler ba� kald�rm�� kavuimuyor dugmeler");//string literalleri de�i�mez

	puts(p1);

	char str6[30];//string literali de�il normal bir dizi oldu�u i�in de�i�tirileblir

	puts(str6);

	strcpy(str6, "memeler ba� kald�rm��");

	puts(str6);

	/*
	char* p = "mehmet";//read only ama�l� kullan�l�r derleyici cont bir dizi olu�turur
	*p = ":" //undefined behavior 
	
	
	
	char str[] = "mehmet";
	*str = "k" //kullan�labilir
	
	*/

	const char* pt1 = "memet";
	const char* pt2 = "memet";

	if (pt1 == pt2)
		printf("esit");
	else
		printf("esit degil");

	//derleyiciden dolay� ayn� stringler ayn� adreslerde tutuluyorsa esit yazar
	//ayn� stringler farkl� adreslerde tutuluyorsa esit degil yazar
	//implementatiom dependent
	st();

	char s6[] = "memolilili";
	char s7[] = "memolilili";
	if (s6 == s7)
		printf("esit");
	else
		printf("esit degil");

	//bunlar birbirinden tamamen farkl� diziler, dolay�s�yla farkl� adreslerde tutulurlar 
	//bu y�zden esit degil yazar

	st();

	const char* rp = "radikal c ve stm32 ile g�m�l� yazl�l�m geli�tirme kurlar� ekim ay�nda basl�yor. Python ve \\ \
diger kurslar da ac�lacak";

	puts(rp);
	st();

	const char* nullstr = "";//1 elemanl� null string literali(sadece null karakteri var)
	
	//POINTER ARRAYS(pointer dizileri): Elemanlar� pointer olan dizilere denir
	//adres tutan diziler

	//type* ad�[] = ;

	//int*a[5]; 5 elemanl�, integer tipinde adres tutan dizi

	//int *ptr 1 adet int adres tutar

	int* a[10];
	printf("%zu\n", sizeof(a));
	printf("%zu\n", sizeof(int*));
	int g1 = 10, g2 = 11, g3 = 12;
	int b[4] = { 1,2,3,4 };
	int* a2[4] = {&g1,&g2,&g3,b};//g1 g2 g3 �n adreslerini pointer arraye g�derdik
	printf("%d", a);//burada dizinin ilk eleman�n�n kendisine eri�tik
	printf("%d", *a);//burada dizinin ilk eleman�n�n adresne eri�tik
	//printf("%d", **a);//burada ise ilk eleman�n g�sterdi�i adresteki de�ere eri�tik
	printf("%d", a[3][1]); //a n�n 3 indexli eleman�n�n 1 indexli eleman�na eri�tik
	printf(" %d %d %d\n", a2[0], a2[1], a[3]);//burada pinter arrayin elemanlar� olan adresleri g�r�r�z
	printf(" %d %d %d\n", *a2[0], *a2[1], *a2[3]);//burada ise her eleman�n g�sterdi�i adresteki de�eri g�r�r�z

	st();
	int g4 = 100;

	a[3] = &g4;//dizi const olursa hata al�r�z

	*a[3] = 200;//g3� de�i�tirdik

	printf("%d\n", g3);

	//(a + 3) = &g4;//kullan�lamaz

	st();
	//lookup table

	const char const* pDays[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

	puts(*(pDays + 3));//thursday yazar

	for (size_t i = 0; i < 6; ++i)
		puts(pDays[i]);//t�m g�nleri alt alt yazar
		//printf("%s", pDays[i]);//bu �ekilde de t�m g�nler yaz�l�r
	st();
	int num;
	printf("kacinci gun ");
	scanf("%d", &num);


	if (num <= 7 && num>0)
		printf("haftanin %d. gunu", num-1,pDays[num-1]);
	else 
		printf("hafta g�n� 1 ile 7 aras�nda olmali");




	}