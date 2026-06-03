#include "Zolw.h"
#include "Swiat.h"

#define SILA 2
#define INICJATYWA 1
#define SYMBOL 'Z'
#define SZANSA_WYKONANIA_RUCHU 4 // 1/SZANSA_WYKONANIA_RUCHU
#define ODBICIE_KOLIZJI 5 //sila < ODBICIE_KOLIZJI -> odbicie kolizji

Zolw::Zolw(int x, int y) : Zwierze(x, y, SILA, INICJATYWA, SYMBOL, 0) {}
Zolw::Zolw(int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(x, y, sila, inicjatywa, SYMBOL, wiek) {}


void Zolw::akcja() {
	if (rand() % SZANSA_WYKONANIA_RUCHU == 0) {
		Zwierze::akcja();
	}
	else {
		this->dodajWiek();
		swiat->dodajLog(" jest za wolny", this);
	}
}

void Zolw::kolizja(Organizm* atakujacy) {
	if (atakujacy->getSymbol() == this->getSymbol()) {
		//rozmnazanie - takie samo
		Zwierze::kolizja(atakujacy);
	}
	else {
		if (atakujacy->getSila() < ODBICIE_KOLIZJI) {
			swiat->dodajLog(" odbil przeciwnika", this);
		}
		else {
			Zwierze::kolizja(atakujacy);
		}
	}
}

Organizm* Zolw::nowyObiekt() {
	return new Zolw(*this);
}