#pragma once
#include <iostream>

using namespace std;
class Swiat;
class Organizm {
private:
	int sila;
	int inicjatywa;
	char symbol;
	//funkcje
protected:
	int wiek;
	Swiat* swiat;
	struct polozenie {
		int x;
		int y;
	} pozycja;

	polozenie ruchy[4] = {
		{0, 1},
		{0, -1},
		{1, 0},
		{-1, 0}
	}; //mo¿liwe ruchy

public:
	Organizm(int x, int y, int sila, int inicjatywa, char symbol, int wiek);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* atakujacy) = 0;
	virtual void losowyRuch(bool czy_puste, Organizm* wzgledem_kogo) = 0;
	virtual Organizm* nowyObiekt() = 0;
	void rysowanie();
	void dodajWiek();
	bool czyMozliwyRuch(int x, int y, bool musiBycPuste);
	
	void setPolozenie(int x, int y);
	void setSila(int sila);
	//gettery
	int getPozycjaX();
	int getPozycjaY();
	int getWiek();
	int getSila();
	int getInicjatywa();
	int getX();
	int getY();
	char getSymbol();
};