#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include <stdio.h>
#include <string.h>
//fopen fclose fputc fgetc fprintf fscanf fputs fgets fwrite fread

#define FILENAME 60

typedef struct Student {
    char name[20];
    char surname[20];
    int no;
}Student;

int main() {

   //fputc
    FILE* fp;
    int ch;

    fp = fopen("file.txt", "w+");
    for (ch = 33; ch <= 100; ch++) {
        fputc(ch, fp);
    }
    fclose(fp);

    st();

    FILE*f1=fopen("ali.txt", "w");

    if (f1==NULL) {
        printf("Dosya a��lamad�");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 26; ++i)
        fputc('A' + i, f1);//b�y�k harfler dosyaya yazildi
    fputc('\n', f1);
    for (int i = 0; i < 26; ++i)
        fputc('a' + i, f1);//k�c�k harfler dosyaya yazildi

    fclose(f1);

    st();

    //text modu ve binary mod

    FILE*f2=fopen("deneme1", "wb");
    if (!f2){
        printf("dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i)
        fputc('\n', f2);

    fclose(f2);//binary modda a��ld�
    st();//
    FILE* f3 = fopen("deneme2", "w");
    if (!f2) {
        printf("dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i)
        fputc('\n', f3);

    fclose(f3);//normal modda a��ld�
    //normal modda a��lan dosya binary modda a��lan dosyaya g�re daha fazla yer kaplar
    st();

    //////////////////////////////////////////////////////////////////
    //bir dosyadan okuyup di�er dosyaya yazma
    //////////////////////////////////////////////////////////////////
    char source_file_name[FILENAME];
    char destination_file_name[FILENAME];

    printf("Okunacak dosya ad�");
    scanf("%s", source_file_name);

    printf("yaz�lacak dosya ad�");
    scanf("%s", destination_file_name);

    
    FILE* fs = fopen(source_file_name, "r");
    //okuma dosyas� a��ld�
    if (!fs) {
        printf("dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    FILE* fd = fopen(destination_file_name, "w");
    //yazma dosyas� a��ld�
    if (!fd) {
        printf("dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    int ch1;
    int byte_count = 0;//byte say�s�n� bulmak i�in saya� da�i�kenimiz
    while ((ch1=fgetc(fs))!=EOF){//bir karakter okuduk dosya karakter g�stericisi 1 artt�
        fputc(ch1, fd);//bir karakter yazd�k dosya karakter g�stericisi 1 artt�
        byte_count++;
    } 
    //bu �ekilde dosyan�n sonuna kadar yazd�k
    printf("%s dosyas�ndan %s dosyas�na %d byte yazma i�lemi yap�lm��t�r.",source_file_name,destination_file_name,byte_count);
    fclose(fs);
    fclose(fd);
    ///////////////////////////////////////////
    // 
    ///////////////////////////////////////////
     
    st();

    //formatl� okuma yazma islemleri
    //fprintf()
    //!!!!!!!!dosya text modunda a��lmal�!!!!!!!!!!!!!
    //
    int a = 10, b = 20;
   FILE *f4= fopen("example.txt", "w");
   if (f4==NULL) {
       printf("dosya acilamadi");
       exit(EXIT_FAILURE);
   }
   fprintf(f4,"meraba d�nya %d,%d\n",a,b);
   fprintf(f4, "ilk sayi=%d,ikinci sayi=%d  toplam=%d\n", a, b, a+b);//fprintf kullan�m�

   fclose(f4);

   //////////////////////////////////
   st();
   /////////////////////////////////

   //structuredan yazd�rma

   FILE* f5 = fopen("deniyok.txt", "w");
   if (f5 == NULL) {
       printf("dosya acilamadi");
       exit(EXIT_FAILURE);
   }
   Student s = { "Ali","Baba",178 };

   fprintf(f5, "***************��renci Milleti**********\n");
   fprintf(f5, "�sim           Soyisim        ��renci No\n");
   fprintf(f5, "%s             %s             %d\n",s.name,s.surname,s.no);
   
   fclose(f5);

   st();

    //fscanf() fonksiyonu
   char str1[10], str2[10], str3[10];
   int year;
   FILE* f6;

   f6 = fopen("file.txt", "w+");
   fputs("We are in 2012", f6);

   rewind(f6);
   fscanf(f6, "%s %s %s %d", str1, str2, str3, &year);

   printf("Read String1 |%s|\n", str1);
   printf("Read String2 |%s|\n", str2);
   printf("Read String3 |%s|\n", str3);
   printf("Read Integer |%d|\n", year);

   fclose(f6);

   st();

   char buffer[100];

   FILE * f7 = fopen("source_file_data.txt", "r");

   while (fscanf(f7, "%s", buffer) != EOF) {
       printf("%s",buffer);
   }

  
   //fscanf fonksiyonu dosya i�eri�ini bo�luksuz okur

   char buffer2[30];
   /*
   while (fscanf(f7, "%s  %s", buffer,buffer2) ) {
       printf("%s", buffer2);
   }
   */
   /*
   while (fscanf(f7, "%s  %s", buffer, buffer2));
       printf("%s", buffer2);//okuyacak bir �ey oldu�u i�in bekler

    */
       fclose(f7);

       st();

       FILE* f8 = fopen("deniyok1.txt", "r");
       fscanf(f8, "%s", buffer);

       printf("%s", buffer);
       /*
       fscanf(f8, "%s %s %d", buffer, buffer2, &year);

       printf("%s %s %d", buffer, buffer2, year);
       */
       //dosyadan okuyup ekrana yazd�k
       //bo�luk karakterini g�rd�k�e sonraki format specifiere ge�er
       
       st();
      
       
       char temp[30];
       
     
       printf("\n");

       while (fscanf(f8,"%s",temp)!=EOF){//dosyadakileri tempe kaydettik
           
           strcat(buffer, " ");//aras�na bo�l�k ekledik
           strcat(buffer, temp);//tempi bufferin sonuna ekledik
       }
       puts(buffer);
       fclose(f8);


       st();
       //fputs kullan�m�
       FILE* f9;

       f9 = fopen("deniyok2.txt", "w+");

       fputs("This is c programming.\n", f9);
       fputs("This is a system programming language.\n", f9);

       fclose(f9);
       st();

       //fgets kullan�m�

       FILE* f10;
       char str5[100];

       /* opening file for reading */
       f10 = fopen("file.txt", "r");//
       if (f10 == NULL) {
           perror("Error opening file");
           return(-1);
       }
       if (fgets(str5, 100, f10) != NULL) {//60 byte okuduk str de�i�kenine yazd�rd�k
           /* writing content to stdout */
           puts(str5);
       }
       fclose(f10);
       //fgets sat�r bazl� okuma yapar(new line g�rene kadar)
       st();

       //fread ve fwrite

       //fwirte() fonksiyonu
       //bellekten okur dosyaya direkt yazar(karakter kodlar� �nemsizse)
       //formats�z yazma i�lemleri

       FILE* f11;
       char str4[] = "This is tutorialspoint.com";
       char str6[100];
       f11 = fopen("file.txt", "w+");
       fwrite(str4, 1, sizeof(str4), f11);//bellek blo�undan dosyaya yazd�k
       //fwrite(str4, sizeof(str4),1, f11) bu �ekildede olabilir
     

       st();
       fseek(f11, 0, SEEK_SET);//dosyan�n en ba��na d�ner
       //fread() fonsksiyonu
       //dosyadan okur belle�e yazar
       fread(str6, strlen(str6)+1, 1, f11);
       printf("%s\n", str6);
       fclose(f11);
       

       st();
       //Dosya konum g�stericisi
       // 
       // 
       //fseek() fonksiyonu: dosya konum g�stericisini set eder
       FILE* f12;

       f12 = fopen("file.txt", "w+");
       fputs("This is tutorialspoint.com", f12);

       fseek(f12, 7, SEEK_SET);//dosya konum g�stericisini ba�lang��tan 7 byte sonras�na ta��d�k
       fputs(" C Programming Language", f12);//dosya konum g�stericisinin  ulundu�u yerde karakterler varsa onlar�n� yerine yazar
       //"This is C programming Language" yazar

       fseek(f12, -8, SEEK_END);//dosya konum g�stericisini sondan 8 byte �ncesine ta��d�k
       fputs(" C++", f12);
       fclose(f12);
       //"This is tutorialspoC++.com" yazar
       
       st();
       //ftell() fonksiyonu
       //dosya konum g�stericinin yerini s�yler
       FILE* f13;

       f13 = fopen("file.txt", "w+");
       unsigned long index = ftell(f13);
       printf("%i\n", index);
       fputs("This is tutorialspoint.com", f13);
       index = ftell(f13);
       printf("%i\n", index);
       fseek(f13, -5, SEEK_END);
       index = ftell(f13);
       printf("%i\n", index);
       fputs("C++", f13);
       printf("%i\n", index);
       fclose(f13);

       st();

       //fsetpos
   

   

}
