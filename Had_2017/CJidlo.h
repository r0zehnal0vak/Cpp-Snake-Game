#pragma once
#include "printxy.h"
#include "Pozice.h"
class CJidlo
{
private:
	CPozice m_Pozice;
	CPozice m_PoziceOld;


public:
	void Zobraz();
	bool Pohni();
	CPozice GetPozice();
	CJidlo(CPozice pozice);
	void SmazPoSobePozici();
	CJidlo(int x, int y);
};

