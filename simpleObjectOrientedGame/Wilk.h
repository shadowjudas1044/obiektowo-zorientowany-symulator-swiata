#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(int x, int y);
	Wilk(int x, int y, int sila, int inicjatywa, int wiek);
	Wilk* nowyObiekt() override;
};