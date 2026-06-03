#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(int x, int y);
	Owca(int x, int y, int sila, int inicjatywa, int wiek);
	Owca* nowyObiekt() override;
};