#include "StdAfx.h"
#include "Lod.h"
using namespace std;
CLod::CLod(void)
{
	m_Pozice.y=13;
	m_Pozice.x = 15;
	m_Smer = -1;
}

CLod::~CLod(void)
{
}

bool CLod::Pohni() {
	int znak;
	if (_kbhit()) {
		znak = _getch();
		m_PoziceOld = m_Pozice;
		if (znak == 'a' && m_Smer != DOPRAVA) m_Smer = DOLEVA;
		if (znak == 'd' && m_Smer != DOLEVA) m_Smer = DOPRAVA;
		if (znak == 'w' && m_Smer != DOLU) m_Smer = NAHORU;
		if (znak == 's' && m_Smer != NAHORU) m_Smer = DOLU;
		if (znak == 'q') return(true);
	}
	m_PoziceOld = m_Pozice;
	if (m_Smer == DOLEVA) m_Pozice.x--;
	if (m_Smer == DOPRAVA) m_Pozice.x++;
	if (m_Smer == NAHORU) m_Pozice.y--;
	if (m_Smer == DOLU) m_Pozice.y++;

	return(false);
}

bool CLod::Hranice()
{
	if (m_Pozice.x < 1) {
		m_Pozice.x = 1;
		return(true);
	}
	if (m_Pozice.x > 80) {
		m_Pozice.x = 80;
		return(true);
	}
	if (m_Pozice.y < 1) {
		m_Pozice.y = 1;
		return(true);
	}
	if (m_Pozice.y > 25) {
		m_Pozice.y = 25;
		return(true);
	}
	return false;
}

CPozice CLod::GetPozici()
{
	return(m_Pozice);
}

CPozice CLod::GetPoziciOld()
{
	return m_PoziceOld;
}



void CLod::Zobraz(int delka) 
{
	PrintXY(m_PoziceOld.x,m_PoziceOld.y," ");
	PrintXY(m_Pozice.x,m_Pozice.y,"#");
}
