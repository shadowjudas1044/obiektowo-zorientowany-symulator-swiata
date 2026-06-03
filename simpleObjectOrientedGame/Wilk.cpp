#include "Wilk.h"

#define SILA 9
#define INICJATYWA 5
#define SYMBOL 'W'

Wilk::Wilk(int x, int y) : Zwierze(x, y, SILA, INICJATYWA, SYMBOL, 0) {}
Wilk::Wilk(int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(x, y, sila, inicjatywa, SYMBOL, wiek) {}


Wilk* Wilk::nowyObiekt() {
	return new Wilk(*this);
}