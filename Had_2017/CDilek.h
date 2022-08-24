#pragma once
#include "pozice.h"
#include "printxy.h"
class CDilek
{
	CPozice m_Pozice;
	CPozice m_PoziceOld;
private:
public:
	void Zobraz();
	CPozice GetPozici();
	CPozice GetPoziciOld();
	void SetPozice(CPozice pozice);

	CDilek(CPozice pozice);
};
//záznam pozice, zobrazení
