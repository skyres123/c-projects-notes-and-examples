#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#define ARRAY_SIZE 50
int main() {

	//Standart idatifiers stdio.h

	//FILE * türünden kullanýlabilen özel isimler

	//stdout: yazma amaçlý kullanýlan isim(standart çýkýþ akýmý)

	fprintf(stdout, "Son c dersi");
	fprintf(stdout, "\nMerhaba");
	//fprintf fonksyonunu printf fonksiyonu gibi kullandýk

	//stderr : standart hata akýmý yazma amaçlý kullanýlýr
	fprintf(stderr, "Son C dersi\n");

	//stdin: okuma amaçlý kullanýlan isim (standart giriþ akýmý)
	char str[ARRAY_SIZE];

	printf("Bir yazý giriniz:\n");
	fgets(str, ARRAY_SIZE, stdin);//bsoþluklu yazýlarý fgets fonksiyonu ile alabiliriz
	printf("yazi = %s\n", str);
	
	//Assertion debug için kullanýlýrlar
	//verilen ifadenin doðruluðu kontrol edilir yanlýþ ise program sonlandýrýlýr
	int a;
	char str1[50];

	printf("Enter an integer value: ");
	scanf("%d", &a);
	assert(a >= 10);//verilen ifadenin doðruluðu kontrol edilir yanlýþ ise program sonlandýrýlýr
	printf("Integer entered is %d\n", a);

	printf("Enter string: ");
	scanf("%s", str1);
	assert(str != NULL);//verilen ifadenin doðruluðu kontrol edilir yanlýþ ise program sonlandýrýlýr
	printf("String entered is: %s\n", str1);
	//assertion lar sadece debug modunda derlenince çalýþýrlar
	//ticari uygulamalar release modunda derlenirler





}