#include "stdafx.h"
#include "CDilek.h"

void CDilek::Zobraz()
{
	PrintXY(m_PoziceOld.x, m_PoziceOld.y, " ");
	PrintXY(m_Pozice.x, m_Pozice.y, "#");
}

void CDilek::SetPozice(CPozice pozice)
{
	m_PoziceOld = m_Pozice;
	m_Pozice = pozice;
}

CDilek::CDilek(CPozice pozice)
{
	m_Pozice = pozice;
	m_PoziceOld = pozice;
}

CPozice CDilek::GetPozici()
{
	return m_Pozice;
}

CPozice CDilek::GetPoziciOld()
{
	return m_PoziceOld;
}
