#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int x, int y);
	Lis(int x, int y, int sila, int inicjatywa, int wiek);
	void losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) override;
	Lis* nowyObiekt() override;
};
