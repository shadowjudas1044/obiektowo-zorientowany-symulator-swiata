#pragma once
#include "Roslina.h"

class Wilcze_jagody : public Roslina {
public:
	Wilcze_jagody(int x, int y);
	Wilcze_jagody(int x, int y, int sila, int wiek);
	void kolizja(Organizm* atakujacy) override;
	Organizm* nowyObiekt() override;
};