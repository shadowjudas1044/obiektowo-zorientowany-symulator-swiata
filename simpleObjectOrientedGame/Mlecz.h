#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(int x, int y);
	Mlecz(int x, int y, int sila, int wiek);
	void odejmijWiek();
	void akcja() override;
	Mlecz* nowyObiekt() override;
};