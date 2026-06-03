#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int czas_odnowienia;
	polozenie ruch;
	void wybierzRuch();
public:
	Czlowiek(int x, int y);
	Czlowiek(int x, int y, int sila, int inicjatywa, int wiek, int czas_odnowienia);
	void umiejetnosc();
	void akcja() override;
	Czlowiek* nowyObiekt() override;
	int getCzasOdnowienia();
};
