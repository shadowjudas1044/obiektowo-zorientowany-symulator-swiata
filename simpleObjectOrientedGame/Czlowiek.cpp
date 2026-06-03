#include "Czlowiek.h"
#include "Swiat.h"
#include "conio.h"

#define SILA 5
#define INICJATYWA 4
#define SYMBOL 'C'
#define CZAS_ODNOWIENIA 5

#define GORA 'w'
#define DOL 's'
#define LEWO 'a'
#define PRAWO 'd'
#define SPACJA ' '

Czlowiek::Czlowiek(int x, int y) : Zwierze(x, y, SILA, INICJATYWA, SYMBOL, 0) {
	this->czas_odnowienia = 0;
	this->ruch = { 0, 0 };
}

Czlowiek::Czlowiek(int x, int y, int sila, int inicjatywa, int wiek, int czas_odnowienia) : Zwierze(x, y, sila, inicjatywa, SYMBOL, wiek) {
	this->czas_odnowienia = czas_odnowienia;
	this->ruch = { 0, 0 };
}


void Czlowiek::umiejetnosc() {
	for (int i = 0; i < 4; i++) {
		if (swiat->getOrganizm(this->getPozycjaX() + ruchy[i].x, this->getPozycjaY() + ruchy[i].y) != nullptr) {
			swiat->dodajLog(" zostal spalony przez umiejetnosc czlowieka", swiat->getOrganizm(this->getPozycjaX() + ruchy[i].x, this->getPozycjaY() + ruchy[i].y));
			swiat->usunOrganizm(swiat->getOrganizm(this->getPozycjaX() + ruchy[i].x, this->getPozycjaY() + ruchy[i].y));
		}
	}
	this->czas_odnowienia = CZAS_ODNOWIENIA;
}

void Czlowiek::wybierzRuch() {
	char klawisz;
	while (true) {

		klawisz = _getch();
		if (klawisz == GORA) {
			this->ruch = { 0, -1 };
		}
		else if (klawisz == DOL) {
			this->ruch = { 0, 1 };
		}
		else if (klawisz == LEWO) {
			this->ruch = { -1, 0 };
		}
		else if (klawisz == PRAWO) {
			this->ruch = { 1, 0 };
		}
		else if (klawisz == SPACJA) {
			if (this->czas_odnowienia == 0) {
				swiat->dodajLog(" uzyl umiejetnosci", this);
				umiejetnosc();
			}
			continue;
		}
		else {
			continue;
		}

		if (czyMozliwyRuch(this->pozycja.x + ruch.x, this->pozycja.y + ruch.y, false)) {
			break;
		}
	}
}

void Czlowiek::akcja() {
	this->dodajWiek();
	if (this->czas_odnowienia > 0) {
		this->czas_odnowienia--;
	}
	else {
		this->czas_odnowienia = 0;
	}
	wybierzRuch();
}

Czlowiek* Czlowiek::nowyObiekt() {
	return nullptr;

}
int Czlowiek::getCzasOdnowienia() {
	return this->czas_odnowienia;
}