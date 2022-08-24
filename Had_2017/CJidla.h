#pragma once
#include <vector>
#include "CJidlo.h"
#include "Lod.h"
class CJidla
{
	vector <CJidlo> m_Jidlo;
	int jidlo;
private:
	void VytvorJidlo(int x, int y);
public:
	void Pohni();
	void Zobraz();
	void GenerujJidlo(int pocet);
	bool OtestujKolize(CLod* lod);
	int VratPocet();
	CJidla();
};

