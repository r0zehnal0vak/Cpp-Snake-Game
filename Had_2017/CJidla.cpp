#include "stdafx.h"
#include "CJidla.h"

void CJidla::VytvorJidlo(int x, int y)
{
	CJidlo jidlo(x, y);
	m_Jidlo.push_back(jidlo);
}

void CJidla::Pohni()
{
	for (int i = 0; i < m_Jidlo.size(); i++) m_Jidlo[i].Pohni();
}

void CJidla::Zobraz()
{
	for (int i = 0; i < m_Jidlo.size(); i++) m_Jidlo[i].Zobraz();

	char text[15];
	sprintf_s(text, 15, "Skore: %d", jidlo);
	PrintXY(85, 22, text);
}

void CJidla::GenerujJidlo(int pocet)
{
	for (int i = 0; i < pocet; i++) {
		VytvorJidlo(rand() % 80, rand() % 15);
	}
}

bool CJidla::OtestujKolize(CLod* lod)
{
	for (int i = 0; i < m_Jidlo.size(); i++) {
		if (lod->GetPozici() == m_Jidlo[i].GetPozice()) {
			m_Jidlo[i].SmazPoSobePozici();
			m_Jidlo.erase(m_Jidlo.begin() + i);			// mazu pozici asteroidu kdyz ho zasahnu lodi
			jidlo++;
			return true;
		}

	}
	return false;
}

int CJidla::VratPocet()
{
	return jidlo;
}

CJidla::CJidla()
{
	jidlo = 0;
}
