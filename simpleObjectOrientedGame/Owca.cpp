#include "Owca.h"

#define SILA 4
#define INICJATYWA 4
#define SYMBOL 'O'

Owca::Owca(int x, int y) : Zwierze(x, y, SILA, INICJATYWA, SYMBOL, 0) {}

Owca::Owca(int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(x, y, sila, inicjatywa, SYMBOL, wiek) {}


Owca* Owca::nowyObiekt() {
	return new Owca(*this);
}