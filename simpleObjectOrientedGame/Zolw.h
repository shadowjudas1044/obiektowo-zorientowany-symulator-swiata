#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {

public:
	Zolw(int x, int y);
	Zolw(int x, int y, int sila, int inicjatywa, int wiek);
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	Organizm* nowyObiekt() override;

};