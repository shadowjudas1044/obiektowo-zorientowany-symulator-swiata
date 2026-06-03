#include "Swiat.h"
#include "Zwierze.h"
using namespace std;

Zwierze::Zwierze(int x, int y, int sila, int inicjatywa, char symbol, int wiek) : Organizm(x, y, sila, inicjatywa, symbol, wiek) {}

void Zwierze::losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) {
	if (!czy_puste) {
		int los = rand() % 4;
		while (!this->czyMozliwyRuch(getX() + ruchy[los % 4].x, getY() + ruchy[los % 4].y, czy_puste)) {
			los++;
		}
	}
	else {

		int los = rand() % 4;
		int timer = 0;
		auto nowe_zwierze = dynamic_cast<Zwierze*>(this->nowyObiekt()); //tworzy nowe zwierze na tymczasowym miejscu aktualnego zwierzêcia
		while (!nowe_zwierze->czyMozliwyRuch(getX() + ruchy[los % 4].x, getY() + ruchy[los % 4].y, czy_puste)) {
			los++;
			timer++;
			if (timer == 4) {
				swiat->dodajLog(" nie ma miejsca na dziecko :(", this);
				delete nowe_zwierze;
				return;
			}
		}
		swiat->dodajOrganizm(nowe_zwierze);
		swiat->dodajLog(" to zwierze rozmnozylo sie", this);
	}
}

void Zwierze::akcja() {
	dodajWiek();
	losowyRuch(false, this);
}

void Zwierze::kolizja(Organizm* atakujacy) {
	if (atakujacy->getSymbol() == this->getSymbol()) {
		//rozmnazanie
		if (wiek >= 2) {
			losowyRuch(true, atakujacy); //tworzenie nowego organizmu wzglêdem atakuj¹cego, ¿eby nie by³o pêtli rozmna¿ania
		}
	}
	else {
		if (this->getSila() > atakujacy->getSila()) {
			swiat->dodajLog(" to zwierze zostalo zabite", atakujacy);
			swiat->usunOrganizm(atakujacy);
		}
		else if (this->getSila() < atakujacy->getSila() || this->getSila() == atakujacy->getSila()) {
			swiat->dodajLog(" to zwierze zostalo zabite", this);
			int x = this->getPozycjaX();
			int y = this->getPozycjaY();
			swiat->usunOrganizm(this);
			atakujacy->setPolozenie(x, y);
		}
	}
}