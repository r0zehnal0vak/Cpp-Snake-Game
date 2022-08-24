// Had_2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "lod.h"
#include "CJidla.h"
#include "COcas.h"


HANDLE  hConsoleOut;                   /* Handle ke konzolovemu oknu */
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;   /* informace o konzolovem okne */


void PrintXY(int x,int y,char *str) {
 COORD coord;
 DWORD written;

	coord.X=x;
	coord.Y=y;

	WriteConsoleOutputCharacter(hConsoleOut,str,(DWORD)strlen(str),coord,&written);

}

// *** smaze konzolovou obrazovku
void ClearScreen( void )
{
    DWORD    dummy;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacter( hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy );
}


void Ohraniceni()
{
	for (int i = 0; i < 82; i++) PrintXY(i, 0, "*");
	for (int i = 0; i < 82; i++) PrintXY(i, 26, "*");
	for (int i = 0; i < 26; i++) PrintXY(0, i, "*");
	for (int i = 0; i < 26; i++) PrintXY(81, i, "*");
}

int _tmain(int argc, _TCHAR* argv[])
{
    /* Otevreme konzolove okno a ziskame informace o jejich parametrech.*/
    hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );

	ClearScreen();

	CLod lod;
	COcas ocas;
	bool konec = false;
	bool hranice = false;
	bool naraz_ocas = false;
	CJidla jidlo;
	int pocet = 0;
	jidlo.GenerujJidlo(20);
	Ohraniceni();
	do {

		konec = lod.Pohni();
		lod.Zobraz(pocet);
		hranice = lod.Hranice();
		naraz_ocas = ocas.Lode(&lod);

		jidlo.Pohni();
		jidlo.Zobraz();

		if (jidlo.OtestujKolize(&lod)) {
			pocet++;
			ocas.PridatDilek(&lod);
			if (pocet == 20) {
				PrintXY(35, 12, "V I C T O R Y");
				konec = true;
			}
		}
		ocas.Pohni(&lod);
		ocas.Zobraz();
		if (hranice == true || naraz_ocas == true ) {
			PrintXY(35, 12, "G A M E   O V E R");
			konec = true;
		}
		Sleep(100);
	} while (konec == false);


   printf("Stiskni cokoliv pro ukonceni aplikace ...\n");
   while( !_kbhit() );


   return 0;
}