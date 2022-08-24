#include "stdafx.h"
#include "COcas.h"

void COcas::Pohni(CLod* lod)
{
	if (dilky.size() != 0) {
		dilky[0].SetPozice(lod->GetPoziciOld()); //bere si poslední pozici hlavy
	}
	int delka = dilky.size() - 1;
	for (int i = 0; i < delka; i++) {
		dilky[i + 1].SetPozice(dilky[i].GetPoziciOld()); //bere si pozici z pøedchozího
	}
}

void COcas::Zobraz()
{
	for (int i = 0; i < dilky.size(); i++) {
		dilky[i].Zobraz();
	}
}

void COcas::PridatDilek(CLod* lod)
{
	if (dilky.size() == 0) {		//had má ještì jen hlavu
		CDilek dilek(lod->GetPoziciOld()); //vznikne dílek na staré pozici lodi
		dilky.push_back(dilek);
	}
	else {
		int index = dilky.size() - 1; //index posledního dílku
		CDilek dilek(dilky[index]); // vznikne dílek na staré pozici posledního dílku
		dilky.push_back(dilek);
	}
	
}

bool COcas::Lode(CLod* lod)
{

	int delka = dilky.size();
	for (int i = 0; i < delka; i++) {
		if (lod->GetPozici() == ((dilky)[i].GetPozici())) {		//zkusíme jestli se pozice libovolného dílku nerovná pozici hlavy
			return true;
		}
	}
	return false;
}
vector<CDilek> * COcas:: GetDilky()
{
	return &dilky;
}
