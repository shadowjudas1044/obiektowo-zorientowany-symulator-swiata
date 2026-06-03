#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y);
	Guarana(int x, int y, int sila, int wiek);
	void kolizja(Organizm* atakujacy) override;
	Guarana* nowyObiekt();
};