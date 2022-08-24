#include "stdafx.h"
#include "COcas.h"

void COcas::Pohni(CLod* lod)
{
	if (dilky.size() != 0) {
		dilky[0].SetPozice(lod->GetPoziciOld()); //bere si posledn� pozici hlavy
	}
	int delka = dilky.size() - 1;
	for (int i = 0; i < delka; i++) {
		dilky[i + 1].SetPozice(dilky[i].GetPoziciOld()); //bere si pozici z p�edchoz�ho
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
	if (dilky.size() == 0) {		//had m� je�t� jen hlavu
		CDilek dilek(lod->GetPoziciOld()); //vznikne d�lek na star� pozici lodi
		dilky.push_back(dilek);
	}
	else {
		int index = dilky.size() - 1; //index posledn�ho d�lku
		CDilek dilek(dilky[index]); // vznikne d�lek na star� pozici posledn�ho d�lku
		dilky.push_back(dilek);
	}
	
}

bool COcas::Lode(CLod* lod)
{

	int delka = dilky.size();
	for (int i = 0; i < delka; i++) {
		if (lod->GetPozici() == ((dilky)[i].GetPozici())) {		//zkus�me jestli se pozice libovoln�ho d�lku nerovn� pozici hlavy
			return true;
		}
	}
	return false;
}
vector<CDilek> * COcas:: GetDilky()
{
	return &dilky;
}
