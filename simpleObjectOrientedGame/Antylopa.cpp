#include "Antylopa.h"
#include "Swiat.h"

#define SILA 4
#define INICJATYWA 4
#define SYMBOL 'A'
#define SZANSA_UNIKU 2 // 1/SZANSA_UNIKU

Antylopa::Antylopa(int x, int y) : Zwierze(x, y, SILA, INICJATYWA, SYMBOL, 0) {}

Antylopa::Antylopa(int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(x, y, sila, inicjatywa, SYMBOL, wiek) {}

void Antylopa::losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) {
	if (!czy_puste) {
		int los = rand() % 8;
		while (!this->czyMozliwyRuch(getX() + ruchy[los % 8].x, getY() + ruchy[los % 8].y, czy_puste)) {
			los++;
		}
	}
	else {

		int los = rand() % 8;
		int timer = 0;
		auto nowe_zwierze = dynamic_cast<Zwierze*>(this->nowyObiekt()); //tworzy nowe zwierze na tymczasowym miejscu aktualnego zwierzêcia
		while (!nowe_zwierze->czyMozliwyRuch(getX() + ruchy[los % 8].x, getY() + ruchy[los % 8].y, czy_puste)) {
			los++;
			if (timer == 8) {
				delete nowe_zwierze;
				return;
			}
		}

	}
}

void Antylopa::kolizja(Organizm* atakujacy) {
	if (atakujacy->getSymbol() == this->getSymbol()) {
		//rozmnazanie - jak zawsze
		Zwierze::kolizja(atakujacy);
	}
	else {
		if (rand() % SZANSA_UNIKU == 0) {
			Zwierze::losowyRuch(true, this); //s¹siednie pole, dlatego Zwierze::
			swiat->dodajLog(" uciekla na aktualne pole", this);
		}
		else {
			Zwierze::kolizja(atakujacy); //normalna kolizja
		}
	}
}

Organizm* Antylopa::nowyObiekt() {
	return new Antylopa(*this);
}