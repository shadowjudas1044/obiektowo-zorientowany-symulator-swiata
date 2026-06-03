#include "Swiat.h"
#include "Roslina.h"
#include <Windows.h>

using namespace std;

#define SZANSA_ROZMNAZANIA 5

Roslina::Roslina(int x, int y, int sila, char symbol, int wiek) : Organizm(x, y, sila, 0, symbol, wiek) {}

void Roslina::losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) {
	int los = rand() % 4;
	int timer = 0;
	auto nowa_roslina = dynamic_cast<Roslina*>(this->nowyObiekt());
	while (!nowa_roslina->czyMozliwyRuch(getX() + ruchy[los % 4].x, getY() + ruchy[los % 4].y, true)) {
		los++;
		timer++;
		if (timer == 4) {
			swiat->dodajLog(" nie ma miejsca na rozprzestrzenienie sie", this);
			delete nowa_roslina;
			return;
		}
	}
	swiat->dodajOrganizm(nowa_roslina);
	swiat->dodajLog(" sie rozprzestrzenia", this);
}

void Roslina::akcja() {
	this->dodajWiek();
	if (rand() % 100 < SZANSA_ROZMNAZANIA) {
		losowyRuch(true, this);
	}
}

void Roslina::kolizja(Organizm* atakujacy) {
	if (this->getSila() > atakujacy->getSila()) {
		swiat->dodajLog(" to zwierze zostalo zatrute", atakujacy);
		swiat->usunOrganizm(atakujacy);
	}
	else if (this->getSila() < atakujacy->getSila() || this->getSila() == atakujacy->getSila()){
		swiat->dodajLog(" ta roslina zostala zniszczona", this);
		int x = this->getPozycjaX();
		int y = this->getPozycjaY();
		swiat->usunOrganizm(this);
		atakujacy->setPolozenie(x, y);
	}
}