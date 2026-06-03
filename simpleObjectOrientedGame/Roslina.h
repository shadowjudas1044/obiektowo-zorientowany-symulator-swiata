#pragma once
#include "Organizm.h"

using namespace std;

class Roslina : public Organizm {
public:
	Roslina(int x, int y, int sila, char symbol, int wiek);
	void losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) override;
	virtual void kolizja(Organizm* atakujacy) override;
	virtual void akcja();
};