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
// jeho vnitøní promìnná je vektor dílkù, má metody které pracují se všemi dílky uloženými ve vektoru

