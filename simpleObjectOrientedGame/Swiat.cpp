#include <algorithm>
#include <iostream>
#include "conio.h"

#include "Swiat.h"
#include "Czlowiek.h"
#include "Zolw.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Wilcze_jagody.h"
#include "Barszcz_sosnowskiego.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Mlecz.h"

#define LOSUJ_MIEJSCE(zwierze)\
		x = rand() % szerokosc;\
		y = rand() % wysokosc;\
		if (getOrganizm(x, y) == nullptr)\
			new zwierze(x, y);\
		else\
			i--;
/*
#########################################################
###### USTAWIENIA POCZATKOWEGO ROZKLADU ORGANIZMOW ######
#########################################################
*/
#define WILKI 2
#define OWCE 2
#define LISY 1
#define ANTYLOPY 2
#define ZOLWIE 1
#define WILCZE_JAGODY 1
#define BARSZCZE_SOSNOWSKIEGO 1
#define TRAWA 4
#define GUARANA 2
#define MLECZ 1

using namespace std;

Swiat::Swiat(int wysokosc, int szerokosc) {
	this->wysokosc = wysokosc;
	this->szerokosc = szerokosc;
	this->stworzony_swiat = this;
	this->czlowiek = nullptr;
}

void Swiat::dodajOrganizm(Organizm* organizm) {
	this->organizmy.push_back(organizm);
}

void Swiat::usunOrganizm(Organizm* organizm) {
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i] == organizm) {
			Organizm* temp = this->organizmy[i];
			this->organizmy.erase(this->organizmy.begin() + i);
			delete temp;
			break;
		}
	}	
}

void Swiat::rysujSwiat() {
	//czyszczenie ekranu
	system("cls");
	cout << "\033[39m"; //bialy kolor
	for (int i = 0; i < szerokosc + 2; i++) {
		for (int j = 0; j < wysokosc + 2; j++) {
			if (i == 0 || i == szerokosc + 1 || j == 0 || j == wysokosc + 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	//rysowanie organizmow
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->rysowanie();
	}
}

void Swiat::organizmyNaPlanszy() {
	//dodawanie organizmow
	int x, y;

	x = rand() % szerokosc;
	y = rand() % wysokosc;
	czlowiek = new Czlowiek(x, y);

	for (int i = 0; i < WILKI; i++) {
		LOSUJ_MIEJSCE(Wilk)
	}
	for (int i = 0; i < OWCE; i++) {
		LOSUJ_MIEJSCE(Owca)
	}
	for (int i = 0; i < LISY; i++) {
		LOSUJ_MIEJSCE(Lis)
	}
	for (int i = 0; i < ANTYLOPY; i++) {
		LOSUJ_MIEJSCE(Antylopa)
	}
	for (int i = 0; i < ZOLWIE; i++) {
		LOSUJ_MIEJSCE(Zolw)
	}
	for (int i = 0; i < WILCZE_JAGODY; i++) {
		LOSUJ_MIEJSCE(Wilcze_jagody)
	}
	for (int i = 0; i < BARSZCZE_SOSNOWSKIEGO; i++) {
		LOSUJ_MIEJSCE(Barszcz_sosnowskiego)
	}
	for (int i = 0; i < TRAWA; i++) {
		LOSUJ_MIEJSCE(Trawa)
	}
	for (int i = 0; i < GUARANA; i++) {
		LOSUJ_MIEJSCE(Guarana)
	}
	for (int i = 0; i < MLECZ; i++) {
		LOSUJ_MIEJSCE(Mlecz)
	}
}

bool Swiat::priorytet(Organizm* organizm1, Organizm* organizm2) {
	if (organizm1->getInicjatywa() != organizm2->getInicjatywa()) {
		return organizm1->getInicjatywa() > organizm2->getInicjatywa();
	}
	else {
		return organizm1->getWiek() > organizm2->getWiek();
	}
}

void Swiat::tura() {
	sort(organizmy.begin(), organizmy.end(), [this](Organizm* a, Organizm* b) {
		return this->priorytet(a, b);
		});
	for (int i = 0; i < this->organizmy.size(); i++) {
		/*
		cout << "\033[30;"<<i+1<<"H";
		cout<<organizmy[i]->getSymbol();
		*/
		this->organizmy[i]->akcja();
	}
}

void Swiat::dodajLog(string log, Organizm* kto) {
	string sym = " ";
	sym += kto->getSymbol();
	log = sym + " (" + to_string(kto->getPozycjaX()) + ", " + to_string(kto->getPozycjaY()) + ")" + log;
	this->log.push_back(log);
}

void Swiat::rysujLog() {
	cout<< "\033[31m";
	cout<< "\033[1;" << szerokosc + 5 << "H";

	for (int i = 0; i < this->log.size(); i++) {
		if (i > wysokosc + 2) {
			cout << "za duzo logow";
			break;
		}
		cout << this->log[i];
		cout << "\033[" << 2 + i << ";" << szerokosc + 5 << "H";
	}
	this->log.clear();
}

void Swiat::zapiszSwiat(ofstream& plik) {
	plik << this->wysokosc << " " << this->szerokosc << endl;
	for(int i = 0; i < this->organizmy.size(); i++) {
		if(this->organizmy[i]->getSymbol() != 'C')
		plik << this->organizmy[i]->getSymbol() << " " 
		 	 << this->organizmy[i]->getPozycjaX() << " " 
			 << this->organizmy[i]->getPozycjaY() << " " 
			 << this->organizmy[i]->getSila() << " " 
			 << this->organizmy[i]->getInicjatywa() << " " 
			 << this->organizmy[i]->getWiek() << endl;
		else {
			plik << this->organizmy[i]->getSymbol() << " "
				<< this->organizmy[i]->getPozycjaX() << " "
				<< this->organizmy[i]->getPozycjaY() << " "
				<< this->organizmy[i]->getSila() << " "
				<< this->organizmy[i]->getInicjatywa() << " "
				<< this->organizmy[i]->getWiek() << " "
				<< dynamic_cast<Czlowiek*>(this->organizmy[i])->getCzasOdnowienia() << endl;
		}
	}
}

Swiat* Swiat::stworzony_swiat = nullptr;

Swiat* Swiat::wczytajSwiat(ifstream& plik) {
	delete stworzony_swiat;
	char symbol;
	int x, y, sila, inicjatywa, wiek, czasOdnowienia, wysokosc, szerokosc;
	plik >> wysokosc >> szerokosc;
	stworzony_swiat = new Swiat(wysokosc, szerokosc);
	while (plik >> symbol >> x >> y >> sila >> inicjatywa >> wiek) {
		if (symbol == 'C') {
			plik >> czasOdnowienia;
			stworzony_swiat->czlowiek = new Czlowiek(x, y, sila, inicjatywa, wiek, czasOdnowienia);
		}
		else if (symbol == 'W')
			new Wilk(x, y, sila, inicjatywa, wiek);
		else if (symbol == 'O')
			new Owca(x, y, sila, inicjatywa, wiek);
		else if (symbol == 'L')
			new Lis(x, y, sila, inicjatywa, wiek);
		else if (symbol == 'A')
			new Antylopa(x, y, sila, inicjatywa, wiek);
		else if (symbol == 'Z')
			new Zolw(x, y, sila, inicjatywa, wiek);
		else if (symbol == 'j')
			new Wilcze_jagody(x, y, sila, wiek);
		else if (symbol == 'b')
			new Barszcz_sosnowskiego(x, y, sila, wiek);
		else if (symbol == 't')
			new Trawa(x, y, sila, wiek);
		else if (symbol == 'g')
			new Guarana(x, y, sila, wiek);
		else if (symbol == 'm')
			new Mlecz(x, y, sila, wiek);
	}
	return stworzony_swiat;
}

int Swiat::getWysokosc() {
	return this->wysokosc;
}

int Swiat::getSzerokosc() {
	return this->szerokosc;
}

Organizm* Swiat::getCzlowiek() {
	return czlowiek;
}

Swiat* Swiat::getSwiat() {
	return stworzony_swiat;
}

Organizm* Swiat::getOrganizm(int x, int y) {
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i]->getX() == x && this->organizmy[i]->getY() == y) {
			return this->organizmy[i];
		}
	}
	return nullptr;
}