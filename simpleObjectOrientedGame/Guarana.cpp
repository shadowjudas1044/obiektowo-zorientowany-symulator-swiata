#include "Guarana.h"
#include "Swiat.h"

#define SILA 0
#define SYMBOL 'g'
#define ILE_SILY 3


Guarana::Guarana(int x, int y) : Roslina(x, y, SILA, SYMBOL, 0) {}

Guarana::Guarana(int x, int y, int sila, int wiek) : Roslina(x, y, sila, SYMBOL, wiek) {}


void Guarana::kolizja(Organizm* atakujacy) {
	atakujacy->setSila(atakujacy->getSila() + 3);
	swiat->dodajLog(" +" + to_string(ILE_SILY) + " sily", atakujacy);
	Roslina::kolizja(atakujacy);
}

Guarana* Guarana::nowyObiekt() {
	return new Guarana(*this);
}