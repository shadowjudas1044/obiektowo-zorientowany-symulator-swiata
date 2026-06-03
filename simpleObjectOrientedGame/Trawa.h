#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(int x, int y);
	Trawa(int x, int y, int sila, int wiek);
	Trawa* nowyObiekt() override;
};