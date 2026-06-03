#pragma once
#include "Roslina.h"

class Barszcz_sosnowskiego : public Roslina {
public:
	Barszcz_sosnowskiego(int x, int y);
	Barszcz_sosnowskiego(int x, int y, int sila, int wiek);

	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	Organizm* nowyObiekt() override;
};

