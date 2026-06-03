#pragma once
#include "Organizm.h"

using namespace std;

class Zwierze : public Organizm {
public:
	Zwierze(int x, int y, int sila, int inicjatywa, char symbol, int wiek);
	virtual void losowyRuch(bool czy_puste, Organizm* wzgledem_kogo);
	virtual void kolizja(Organizm* atakujacy) override;
	virtual void akcja();
};