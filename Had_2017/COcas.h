#pragma once
#include <vector>
#include "CDilek.h"
#include "Lod.h"
using namespace std;
class COcas
{
	vector <CDilek> dilky;
public:
	void Pohni(CLod*);
	void Zobraz();
	void PridatDilek(CLod*);
	bool Lode(CLod*);
	vector <CDilek> * GetDilky();
};
// jeho vnit�n� prom�nn� je vektor d�lk�, m� metody kter� pracuj� se v�emi d�lky ulo�en�mi ve vektoru

