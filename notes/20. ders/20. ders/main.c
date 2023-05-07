#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
/*
* Multidimensional Arrays(�ok boyutlu diziler)
int x[a][b] a=dizinin boyutu   b=x in ��elerinin t�r�

int x1[3][3]
[0][0]	[0][1] [0][2]   
[1][0]	[1][1] [1][2]
[2][0]	[2][1] [2][2]
int a[5]
*/
#define  ROWS 3
#define  COLS 4
#define MATRIX_MAX 10

void displayMatrix3(const int(*p)[4], size_t size) {
	for (size_t i = 0; i < size; ++i){
		for (size_t j = 0; j < 4; ++j)
			printf("%d ", p[i][j]);
		printf("\n");
	}
}

int main() {
	int a[2][3];//6 elemanl� ve het eleman 4 byte

	printf("%zu\n", sizeof(a));//24
	printf("%zu\n", sizeof(a[0][1]));//1 elemal� ve 4 byte = 4

	st();

	printf("%p\n", &a[0][0]);
	printf("%p\n", &a[0][1]);
	printf("%p\n", &a[0][2]);
	printf("%p\n", &a[1][0]);
	printf("%p\n", &a[1][1]);
	printf("%p\n", &a[1][2]);
	//aralar�nda 4'er byte var

	st();

	//��eleri 10 elemanl� double bir dizi olan 15 elemanl� data isminda bir dizi

	double Data[15][10]; 
	double Data1[20][10];
	double Data2[30][10];
	double Data3[40][10];
	double Data4[50][10];
	//hepsi ayn� t�rdendir, boyutlar� farkl�d�r

	st();

	//tipik bir m�lakat sorusu
	 /*
	 int ar[][] = {1,2,3,4,5,6,7,8,9,10}//syntax err
	 int ar[][4] = {1,2,3,4,5,6,7,8,9,10}//no error
	 int ar[4][] = {1,2,3,4,5,6,7,8,9,10}//syntax error
	 int ar[4][4] = {1,2,3,4,5,6,7,8,9,10}//no error
	 */

	//int b[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int b1[3][4] = { {1,2,3,4},
					{5,6,7,8},
					{9,10,11,12}};

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; j++)
			printf("%d ", b1[i][j]);
		printf("\n");
	}

	st();
	b1[1][3] = 0;//8->0

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; j++)
			printf("%d ", b1[i][j]);
		printf("\n");
	}//8 say�s� 0'a d�nd�

	st();

	int a1[3][4] = { {1,2,3,4},
					{1,2,3,4},
					{3,3,3,3},
							};

	int(*p1)[3][4] = &a1;
	printf("%p\n", *p1);

	displayMatrix3(a1, 3);

	st();

	//bir okulda 20 ��rencili 30 s�n�f� olanbir dizi olarak yaz�n�nz

	int siniflar[30][20];

	//5 tane portu olan her portunda 8 pin olan gpio �evresel birimini �ok boyutlu dizi olarak g�steriniz
	
	int gpio[5][8];

	st();

	int matrix[MATRIX_MAX][MATRIX_MAX] = { 0 };

	int row;
	int col;

	printf("satir ve sutun sayisini giriniz:");
	scanf("%d%d",&row,&col);
	printf("row=%d,col=%d", row, col);

	st();

	for (size_t i = 0; i < row; ++i)
		for (size_t j = 0; j < col; j++) {
			printf("%d . sat�r, %d. sutun", i, j);
			scanf("%d", &matrix[i][j]);
		}//matrix eleman g�nderme

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; j++) {
			printf("%d . sat�r, %d. sutun", i, j);
		}//matrix elemanlar�n� g�sterme


	st();

	//locale
	double dval = 18.66;
	printf("%lf", dval);

	st();

	char* p = setlocale(LC_ALL, "turkish");
	if (p == NULL) {
		printf("locale de�i�tirilemedi");
		exit(EXIT_FAILURE);
	}
	printf("�ok g�zel oldu");


	st();

	//dosya i�lemleri
	//10101001110011100		.mp3
	//10101001110011100		.jpeg

	//fopen(): dosyay� a�ar handleyi al�r
	//okuma: dosyan�n i�indeki bytelar� okur
	//yazma: dosyan�n bytelar�n� de�i�tirmek

	//file pointer: dosya konum g�stericisi(ex: de�er 10 ise 10. byt� okuruz)

	
	//dosya a�ma modlar�
/*
1 "r":Opens a file for reading. The file must exist.
2 "w":Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.
3 "a":Appends to a file. Writing operations, append data at the end of the file. The file is created if it does not exist.
4 "r+":Opens a file to update both reading and writing. The file must exist.
5 "w+":Creates an empty file for both reading and writing.
6 "a+":Opens a file for reading and appending.*/
	FILE *f=fopen("mehmet.txt","w");//write modda a��ld�
	//verilen adreste dosya a��l�r
	if (f == NULL) {
		printf("the file can not opened\n");
		exit(EXIT_FAILURE);
	}
	printf("the file was open\n");


	fclose(f);//dosya kapand�

	st();

	//yaz�lan bilgiyi okuma
	FILE* f1 = fopen("berat.txt", "r");//read modda a��ld�
	//verilen adreste dosya a��l�r
	if (f == NULL) {
		printf("the file can not opened\n");
		exit(EXIT_FAILURE);
	}
	printf("the file was open\n");

	int ch =fgetc(f1);
	putchar(ch);//bir karakter okuduk ve yazd�rd�k

	int ch1;
	while ((ch1 = fgetc(f1)) != EOF)
		putchar(ch1);
	//t�m dosyay� okuduk ve yazd�rd�k
	fclose(f1);



} 