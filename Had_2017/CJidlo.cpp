#include "stdafx.h"
#include "CJidlo.h"

void CJidlo::Zobraz()
{
	PrintXY(m_PoziceOld.x, m_PoziceOld.y, " ");
	PrintXY(m_Pozice.x, m_Pozice.y, "@");
}

bool CJidlo::Pohni()
{
	return false;
}

CPozice CJidlo::GetPozice()
{
	return(m_Pozice);
}

CJidlo::CJidlo(CPozice pozice)
{
	m_Pozice = pozice;
}

void CJidlo::SmazPoSobePozici()
{
	PrintXY(m_Pozice.x, m_Pozice.y, " ");
}

CJidlo::CJidlo(int x, int y)
{
	m_Pozice.x = x;
	m_Pozice.y = y;
}
