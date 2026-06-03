#include "Lis.h"
#include "Swiat.h"

#define SILA 3
#define INICJATYWA 7
#define SYMBOL 'L'


Lis::Lis(int x, int y) : Zwierze(x, y, SILA, INICJATYWA, SYMBOL, 0) {}

Lis::Lis(int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(x, y, sila, inicjatywa, SYMBOL, wiek) {}

void Lis::losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) {
	if (!czy_puste) {
		int los;
		los = rand() % 4;
		int x = this->getPozycjaX();
		int y = this->getPozycjaY();

		while (los<8) { //mniej ni¿ 8 poniewa¿ zwierze mo¿e nie mieæ w ogóle ruchu np.otoczone przez silniejsze zwierzêta
			if (swiat->getOrganizm(x + ruchy[los % 4].x, y + ruchy[los % 4].y) != nullptr) {
				if (swiat->getOrganizm(x + ruchy[los % 4].x, y + ruchy[los % 4].y)->getSila() < this->getSila()) {
					this->czyMozliwyRuch(x + ruchy[los % 4].x, y + ruchy[los % 4].y, false);
					break;
				}
				else {
					swiat->dodajLog(" wyniuchal niebezpieczenstwo i zmienil kierunek", this);
					los++;
				}
			}
			else {
				this->czyMozliwyRuch(x + ruchy[los % 4].x, y + ruchy[los % 4].y, false);
				break;
			}
		}

	}
	else {
		Zwierze::losowyRuch(true, wzgledem_kogo); //to samo
	}
}

Lis* Lis::nowyObiekt() {
	return new Lis(*this);
}