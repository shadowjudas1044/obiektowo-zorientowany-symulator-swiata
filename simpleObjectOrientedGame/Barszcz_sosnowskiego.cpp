#include "Barszcz_sosnowskiego.h"
#include "Swiat.h"

#define SILA 10
#define SYMBOL 'b'

Barszcz_sosnowskiego::Barszcz_sosnowskiego(int x, int y) : Roslina(x, y, SILA, SYMBOL, 0) {}

Barszcz_sosnowskiego::Barszcz_sosnowskiego(int x, int y, int sila, int wiek) : Roslina(x, y, sila, SYMBOL, wiek) {}


void Barszcz_sosnowskiego::akcja() {
	this->dodajWiek();
	for (int i = 0; i < 4; i++) {
		if(swiat->getOrganizm(this->getPozycjaX() + ruchy[i].x, this->getPozycjaY() + ruchy[i].y) == nullptr) {
			continue;
		}
		char symbol = swiat->getOrganizm(this->getPozycjaX() + ruchy[i].x, this->getPozycjaY() + ruchy[i].y)->getSymbol();
		if (symbol >= 'A' && symbol <= 'Z') {
			swiat->dodajLog(" sie rozlal i zabil", this);
			swiat->usunOrganizm(swiat->getOrganizm(this->getPozycjaX() + ruchy[i].x, this->getPozycjaY() + ruchy[i].y));
		}
	}
	Roslina::akcja();
}

void Barszcz_sosnowskiego::kolizja(Organizm* atakujacy) {
	swiat->usunOrganizm(atakujacy);
	swiat->usunOrganizm(this);
}

Organizm* Barszcz_sosnowskiego::nowyObiekt() {
	return new Barszcz_sosnowskiego(*this);
}