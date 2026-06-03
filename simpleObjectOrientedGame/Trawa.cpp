#include "Trawa.h"

#define SILA 0
#define SYMBOL 't'

Trawa::Trawa(int x, int y) : Roslina(x, y, SILA, SYMBOL, 0) {}

Trawa::Trawa(int x, int y, int sila, int wiek) : Roslina(x, y, sila, SYMBOL, wiek) {}

Trawa* Trawa::nowyObiekt() {
	return new Trawa(*this);
}