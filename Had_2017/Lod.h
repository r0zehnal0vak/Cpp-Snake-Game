#pragma once
#include "printxy.h"
#include "pozice.h"
#include <vector>
using namespace std;

#define DOLEVA 0
#define DOPRAVA 1
#define NAHORU 2
#define DOLU 3
class CLod
{
	CPozice m_Pozice;
	CPozice m_PoziceOld;
	int m_Smer; //0 doleva, 1 doprava, 2 nahoru, 3 dolu
//(if m_Smer == DOLEVA) ..... had pojede doleva
	//vector <CLod> Had;
private:
public:
	void Zobraz(int pocet);
	bool Pohni();
	bool Hranice();
	CPozice GetPozici();
	CPozice GetPoziciOld();
	CLod(void);
	~CLod(void);
};
