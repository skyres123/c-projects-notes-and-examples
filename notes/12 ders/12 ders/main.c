#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include "utility.h"
#include <string.h>


//string kütüphanesi
void st() {
	printf("\n==============================================================\n");
}
void myputs(const char* str) {
	while (*str != '\0')//null karakteri olmadýkça devam et
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
	for ( i = 0; str[i] != '\0'; ++i);// str[i] null olmadýkça devam et
	return i;
}
size_t mystrlen2(const char* str) {
	size_t size;
	while (*str != "\0")//pointerýn deperi null olmadýkça devam et
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
	//strxyz tarzýnda fonksiyonlar
	//f1(char* str)   f2(const char* str)

	//const :  deðiþken üzerinde deðiþiklik yapýlamaz

	//strlen, strchr, strcmp, strcat, stricmp, strpbrk, strtok ....

	char str[30] = "mehmet berat sen";

	printf(str);
	st();
	puts(str);
	st();
	myputs(str);
	st();
	revputs(str);//tersten yazdýrma

	//strlen(); string uzunluðunu verir

	char str1[] = "Memolililililil";

	size_t size = strlen(str1);
	printf("%zu", size);//size_t  -----> %zu 

	size_t SIZE = mystrlen(str1);
	printf("Sizeof(str):Ç %d \n", SIZE);
	st();

	//strchr(const char* p, int ival)
	//strchr: string içinde  string arar, bulamazsa null pointer döner


	char str2[40] = "Mehmet Berat ÞEN";
	/*	printf("Aranacak karakteri giriniz");
	int ch = getchar();
	char * ptr= strchr(str2, ch);//0 döner ise bulamadý, 0 dan farklý deðer döner ise bulmuþtur
	if (ptr) 
		printf("Aranan karakter bulundu indexi = %d", ptr - str2);//geri dönüþ deðerinden baþlangýç adresini çýkarýrsak indexe ulaþýrýz
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

	//strrchr(): sondan baþlayarak stringi arar

	//strcpy() stringi kaynaktan hedefer kopyalar

	char str3[20] = "Komiser Memoli";

	char str_name[20];

	char* new_name = strcpy(str_name, str3);//hedef adrese döner
	puts(str_name);
	puts(str3);

	printf("%p\n", str_name );//iki adres ayný
	printf("%p\n", new_name);//
	st();

	char name[10] = "Mehmet";
	char surname[10] = "SEN";

	char full_name[30];
	strcpy(strcpy(full_name, name)+strlen(name), surname);//içteki strcpy namedeki stringi full name ye dýþtaki ise surname yi nameden sonrasýna kopyalamak için fullnamenin adresine namenin uzunluðunu ekledik 
	printf("%s", full_name);
	st();
	
	char str4[20] = "Memoli";
	//strcpy(str4 + 2, str4);//source ve destination arasýnda kesiþim varsa strcpy yerine memmove fonksiyonu kullanýlýr
	memmove(str4 + 2, str4, strlen(str4) + 1);
	puts(str4);
	st();

	//strcat() bir yazýnýn sonunabaþka bir yazýyý ekler
	/*	
	char name[10] = "Mehmet";
	char surname[10] = "SEN";
	*/
	strcat(name, surname);
	puts(name);
	st();

	//strcmp() iki yazýyý karþýlaþtýrýr
	//geri dönüþ deðeri >0 1. yazý büyük
	//geri dönüþ deðeri <0 1. yazý kücük
	//geri dönüþ degeri 0 ise yazýlar ayný==> daha çok bununla ilgiliyiz

	//ascii karakter tablosuna göre karþýlaþtýrýr

	char s1[100];
	char s2[100];
	printf("Ýki yazý giriniz");
	scanf("%s %s", &s1, &s2);

	int res =  strcmp(s1,s2);//stricmp büyük küçük harf karþýlaþtýrmasýný durdurur

	if (!res)
		printf("Bunlar ayni yazi");
	else
		printf("Bu yazilar farkli");

	st();
	

	//strstr() yazý içinde yazý arar

	char s3[100] = "Caným koydun yoluna sýk bir kurþun asena";
	char s4[100];

	printf("Aranacak yaziyi giriniz");
	scanf("%s", &s4);
	

	int res2 = strstr(s3, s4);//s4 yzisini s4 yazisinin içinde aradik

	if (res2!=NULL)
		printf("Aranan yazi bulundu");
	else
		printf("Aranan yazi bulunamadi");

	st();

	//string literals
	//"" içinde yazdýðýmz ifadeler string literalidir
	//string literali char dizisi oluþur ve o dizinin adresi tutulur
	//string literali deðiþtirilemez

	printf("%c", *"mehmet");//mehmet string litesalinin adresi tutulur ekrana ilk harf olan m yazýlýr

	st();

	printf("%zu", strlen("mehmet"));//uzunluðu yazdýrdýk

	st();

	const char* p = "Mehmet";//string literaller const dizilerdir const hep kullanýlmalýdýr
	//yazýnýn tutulduðu dizinin adresiyle p pointeriýna ilk deðer verildi

	char str5[] = "mehmet";//string literali deðil adres belirtmiyor

	char* p1 = "memolililili";//string literalleri deðiþmez

	puts(p1);

	//strcpy(p1, "memeler baþ kaldýrmýþ kavuimuyor dugmeler");//string literalleri deðiþmez

	puts(p1);

	char str6[30];//string literali deðil normal bir dizi olduðu için deðiþtirileblir

	puts(str6);

	strcpy(str6, "memeler baþ kaldýrmýþ");

	puts(str6);

	/*
	char* p = "mehmet";//read only amaçlý kullanýlýr derleyici cont bir dizi oluþturur
	*p = ":" //undefined behavior 
	
	
	
	char str[] = "mehmet";
	*str = "k" //kullanýlabilir
	
	*/

	const char* pt1 = "memet";
	const char* pt2 = "memet";

	if (pt1 == pt2)
		printf("esit");
	else
		printf("esit degil");

	//derleyiciden dolayý ayný stringler ayný adreslerde tutuluyorsa esit yazar
	//ayný stringler farklý adreslerde tutuluyorsa esit degil yazar
	//implementatiom dependent
	st();

	char s6[] = "memolilili";
	char s7[] = "memolilili";
	if (s6 == s7)
		printf("esit");
	else
		printf("esit degil");

	//bunlar birbirinden tamamen farklý diziler, dolayýsýyla farklý adreslerde tutulurlar 
	//bu yüzden esit degil yazar

	st();

	const char* rp = "radikal c ve stm32 ile gömülü yazlýlým geliþtirme kurlarý ekim ayýnda baslýyor. Python ve \\ \
diger kurslar da acýlacak";

	puts(rp);
	st();

	const char* nullstr = "";//1 elemanlý null string literali(sadece null karakteri var)
	
	//POINTER ARRAYS(pointer dizileri): Elemanlarý pointer olan dizilere denir
	//adres tutan diziler

	//type* adý[] = ;

	//int*a[5]; 5 elemanlý, integer tipinde adres tutan dizi

	//int *ptr 1 adet int adres tutar

	int* a[10];
	printf("%zu\n", sizeof(a));
	printf("%zu\n", sizeof(int*));
	int g1 = 10, g2 = 11, g3 = 12;
	int b[4] = { 1,2,3,4 };
	int* a2[4] = {&g1,&g2,&g3,b};//g1 g2 g3 ün adreslerini pointer arraye göderdik
	printf("%d", a);//burada dizinin ilk elemanýnýn kendisine eriþtik
	printf("%d", *a);//burada dizinin ilk elemanýnýn adresne eriþtik
	//printf("%d", **a);//burada ise ilk elemanýn gösterdiði adresteki deðere eriþtik
	printf("%d", a[3][1]); //a nýn 3 indexli elemanýnýn 1 indexli elemanýna eriþtik
	printf(" %d %d %d\n", a2[0], a2[1], a[3]);//burada pinter arrayin elemanlarý olan adresleri görürüz
	printf(" %d %d %d\n", *a2[0], *a2[1], *a2[3]);//burada ise her elemanýn gösterdiði adresteki deðeri görürüz

	st();
	int g4 = 100;

	a[3] = &g4;//dizi const olursa hata alýrýz

	*a[3] = 200;//g3ü deðiþtirdik

	printf("%d\n", g3);

	//(a + 3) = &g4;//kullanýlamaz

	st();
	//lookup table

	const char const* pDays[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

	puts(*(pDays + 3));//thursday yazar

	for (size_t i = 0; i < 6; ++i)
		puts(pDays[i]);//tüm günleri alt alt yazar
		//printf("%s", pDays[i]);//bu þekilde de tüm günler yazýlýr
	st();
	int num;
	printf("kacinci gun ");
	scanf("%d", &num);


	if (num <= 7 && num>0)
		printf("haftanin %d. gunu", num-1,pDays[num-1]);
	else 
		printf("hafta günü 1 ile 7 arasýnda olmali");




	}