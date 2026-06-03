#include "Mlecz.h"

#define ILOSC_PROB 3
#define SILA 0
#define SYMBOL 'm'

Mlecz::Mlecz(int x, int y) : Roslina(x, y, SILA, SYMBOL, 0) {}

Mlecz::Mlecz(int x, int y, int sila, int wiek) : Roslina(x, y, sila, SYMBOL, wiek) {}

void Mlecz::odejmijWiek() {
	this->wiek--;
}

void Mlecz::akcja() {
	for (int i = 0; i < ILOSC_PROB; i++)
		Roslina::akcja();
	for(int i=0; i<ILOSC_PROB-1; i++)
		odejmijWiek();
}

Mlecz* Mlecz::nowyObiekt() {
	return new Mlecz(*this);
}