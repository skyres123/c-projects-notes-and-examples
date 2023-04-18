#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#pragma pack(1)



typedef enum Gender {
	Kadýn, Erkek
}Gender;

#define Tecilli 0
#define Kýsa_Donem 1
#define Uzun_Donem 2

typedef union UData{
	int x, y;
	double z;
	int dval;
	char str[12];
}UData;

typedef struct SData {
	int x, y;
	double z;
	char str[12];
}SData;

typedef struct {
	int status;
	char location[30];
}miliInfo;

typedef union Person {
	miliInfo minfo;
	char maiden_name[];
}Person;

typedef struct Employee{
	int no;
	double wage;
	char name[20];
	char surname[25];
	int gender;
	Person data;
}Employee;


//enumerations(numaralandýrmalar)
//isimlendirilmiþ belirli tamsayý daðerlerini alabilien bir tüe yazýlmasýna olanak veren araç

typedef enum Color { BLue, White, Green, Red, Black }Color;
typedef enum DeviceStates { PowerOFF, PowerON, STANDBY } DeviceStates;
void setDeviceState(DeviceStates dev) {
	switch (dev)
	{
	case PowerOFF:
		printf("device off");
		//code
		break;
	case PowerON:
		printf("Device On");
		//code
		break;
	case STANDBY:
		printf("Standby mode");
		//code
		break;
	default:
		printf("another else");
		break;
	}
}

void bp(int val) {//herhangi bir sayýyý 2 lik tabana çevirir
	char buffer[40];
	_itoa(val, buffer, 2);
	printf("%s\n", buffer);
}

int main() {
	//unions(birlikler)
	union UData mydata;//typedef bildirimiz yapýlmazsa baþýnda union olmalýdýr
	SData mydata1; //typedef bildirimiz yapýlmýþsa baþýnda union olmasýna gerek yok
	
	printf("sizeof(union Data) = %zu\n", sizeof(UData));
	//unionun sizeofu en büyük boyutlu öðenin sizeofu kadar olacaktýr
	printf("sizeof(struct Data) = %zu\n", sizeof(SData));

	st();
	mydata.x = 100;
	mydata.y = 200;
	mydata.dval = 250;
	printf("y=%d, T=%d, Z=%d\n", mydata.x, mydata.y, mydata.dval);
	printf("y=%p, T=%p, Z=%p\n", mydata.x, mydata.y, mydata.dval);
	//union da bütün memeberlar ayný adrese kaydedilir. MEmberlerden biri deðiþince hepsi deðiþir

	st();

	Employee emp = { 12,10000,"Ayse","DUZDUVARATIRMANAN",Kadýn };
	strcpy(emp.data.maiden_name, "MERDIVEN");


	if (emp.gender == Kadýn)
		printf(" Kadýn ve : Maiden Name => %s\n", emp.data.maiden_name);
	else 
		printf("Erkek ve : Askerlik Bilgisi=> Konum %s Status %d", emp.data.minfo.location, emp.data.minfo.status);

	//çalýþan kadýn ise kýzlýk soyadý olur
	//çalýþan erkek ise askerlik bilgisi olur

	st();

	//enumerations(numaralandýrmalar)
	//isimlendirilmiþ belirli tamsayý daðerlerini alabilien bir tüe yazýlmasýna olanak veren araç

	Color  house_color = Green;
	Color roof_color = Black;

	//enum memberleri 0 dan baþlayarak sayýlardýr

	printf("white = %d\n", White);
	printf("Blue = %d\n", BLue);
	printf("Green = %d\n", Green);
	printf("Black = %d\n", Black);
	printf("Red = %d\n", Red);

	st();

	//Eðer enum öðelerine deðer verilirse daha sonrasýnda olam öðeler verilen sayýdan devam eder
	printf("%zu", sizeof(Color));

	st();

	DeviceStates dev = PowerON;
	setDeviceState(dev);//emun sabitlerini switch case ile kullandýk
	st();

	//Bitsel iþlemler ve bitsel operatörler

	/*
				- - - - - - - - //bitwise manuplation
				BÝTWISE OPERATIONS

				~     Bitwise not
				<< >> Bitwise Right Shift - Left Shift
				&     Bitwise and
				^	  Bitwise xor
				|     Bitwise or
				<<= >>= &= |= ^= ~= 
	*/

	bp(20); 
	st();
	//not operator ~

	unsigned char x = 10;//1010 ----- NOT ----- 0101
	bp(10);
	unsigned char res = ~x;
	bp(res);//101 yazmalý
	unsigned char res1 = ~~x;
	bp(res1);//1010

	bp(~x);//bitwise not    = 0 dýr
	bp(!x);//logical not;	= 


}