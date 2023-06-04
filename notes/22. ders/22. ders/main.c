#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#define ARRAY_SIZE 50
int main() {

	//Standart idatifiers stdio.h

	//FILE * t�r�nden kullan�labilen �zel isimler

	//stdout: yazma ama�l� kullan�lan isim(standart ��k�� ak�m�)

	fprintf(stdout, "Son c dersi");
	fprintf(stdout, "\nMerhaba");
	//fprintf fonksyonunu printf fonksiyonu gibi kulland�k

	//stderr : standart hata ak�m� yazma ama�l� kullan�l�r
	fprintf(stderr, "Son C dersi\n");

	//stdin: okuma ama�l� kullan�lan isim (standart giri� ak�m�)
	char str[ARRAY_SIZE];

	printf("Bir yaz� giriniz:\n");
	fgets(str, ARRAY_SIZE, stdin);//bso�luklu yaz�lar� fgets fonksiyonu ile alabiliriz
	printf("yazi = %s\n", str);
	
	//Assertion debug i�in kullan�l�rlar
	//verilen ifadenin do�rulu�u kontrol edilir yanl�� ise program sonland�r�l�r
	int a;
	char str1[50];

	printf("Enter an integer value: ");
	scanf("%d", &a);
	assert(a >= 10);//verilen ifadenin do�rulu�u kontrol edilir yanl�� ise program sonland�r�l�r
	printf("Integer entered is %d\n", a);

	printf("Enter string: ");
	scanf("%s", str1);
	assert(str != NULL);//verilen ifadenin do�rulu�u kontrol edilir yanl�� ise program sonland�r�l�r
	printf("String entered is: %s\n", str1);
	//assertion lar sadece debug modunda derlenince �al���rlar
	//ticari uygulamalar release modunda derlenirler





}