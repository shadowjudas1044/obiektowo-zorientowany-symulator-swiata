#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	polozenie ruchy[8] = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0},
		{0, 2},
		{0, -2},
		{2, 0},
		{-2, 0}
	};
public:
	Antylopa(int x, int y);
	Antylopa(int x, int y, int sila, int inicjatywa, int wiek);
	void losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) override;
	void kolizja(Organizm* atakujacy) override;
	Organizm* nowyObiekt() override;
};