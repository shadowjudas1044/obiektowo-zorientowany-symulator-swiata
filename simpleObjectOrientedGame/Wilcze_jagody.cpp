#include "Wilcze_jagody.h"
#include "Swiat.h"

#define SILA 99
#define SYMBOL 'j'

Wilcze_jagody::Wilcze_jagody(int x, int y) : Roslina(x, y, SILA, SYMBOL, 0) {}

Wilcze_jagody::Wilcze_jagody(int x, int y, int sila, int wiek) : Roslina(x, y, sila, SYMBOL, wiek) {}


void Wilcze_jagody::kolizja(Organizm* atakujacy) {
	swiat->usunOrganizm(atakujacy);
	swiat->usunOrganizm(this);
}

Organizm* Wilcze_jagody::nowyObiekt() {
	return new Wilcze_jagody(*this);
}